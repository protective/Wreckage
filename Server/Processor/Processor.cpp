/* 
 * File:   Processor.cpp
 * Author: karsten
 * 
 * Created on 16. februar 2014, 22:24
 */

#include "Processor.h"
#include  "../Tasks/Task.h"
#include "../Tasks/TaskCreateObj.h"
#include "../Tasks/TaskSendMessage.h"
#include "../Tasks/TaskProcess.h"

#include "../ModelLayer/SWorld.h"
#include "../ModelLayer/SObj.h"
#include "../ModelLayer/Components/ComponentFactory.h"
#include "../ModelLayer/Components/CompSpawnNode/CompSpawnNode.h"
#include "../ModelLayer/Components/CompReSpawnable/CompReSpawnable.h"

#include "../SGlobals.h"

#include <sys/time.h>
Processor::Processor() {
	
	pthread_cond_init(&_workCond,NULL);
	pthread_mutex_init(&_workMutex,NULL);
	pthread_mutex_init(&_lockFreeID, NULL);
	pthread_mutex_init(&_lockCommands, NULL);
	_workReady = false;
	_freeIdCount = 1;
	_id = 1;
	
	_dbCon = new pqxx::connection("dbname= wreckage user=karsten");

	OBJID maxLocalId = 0x00FFFFFF | (_id << 24);
	
	pqxx::work w(*_dbCon);
	stringstream s;
	cerr<<maxLocalId<<endl;
	s<<"select max(objid) from objs where objid <"<<maxLocalId<<";"; 
	pqxx::result r = w.exec(s);

	if(!r[0][0].is_null())
		_freeIdCount = (r[0][0].as<OBJID>() & 0x00FFFFFF) + 1;
	else
		_freeIdCount = 1;
	w.commit();
	
	loadAllObjFromDb();
	//TaskCreateObj* cmd = new TaskCreateObj(true);
	//cmd->addComponent(new CompSpawnNode(1000,0,0));
	//this->addTask(cmd);	
	
	//cmd = new TaskCreateObj(true);
	//cmd->addComponent(new CompReSpawnable(0));
	//this->addTask(cmd);
}

void Processor::loadAllObjFromDb(){
	pqxx::work w(getDB());
	stringstream s;
	s<<"select objid from objs;"; 
	pqxx::result r = w.exec(s);
	w.commit();
	for(int i = 0; i < r.size();i++){
		addTask(new TaskCreateObj(r[i][0].as<OBJID>(),r[i][0].as<OBJID>(), true));
	}
	
		
}


void Processor::addObj(SObj* obj){
	if(obj){
		cerr<<"processor add obj id="<<obj->getId()<<endl;
		_localObjs[obj->getId()] = obj;
		TaskProcess* task = new TaskProcess(obj,1000);
		addTask(task);
		obj->setProcessTask(task);
	}else
		cerr<<"ERROR Processor::addObj obj = NULL"<<endl;
}

void Processor::removeObj(SObj* obj){
	if(obj){
		cerr<<"processor remove obj id="<<obj->getId()<<endl;
		_localObjs[obj->getId()] = obj;
		obj->getProcessTask()->objDeleted();
		delete obj;
	}else
		cerr<<"ERROR Processor::addObj obj = NULL"<<endl;
}

SObj* Processor::getObj(OBJID id){
	cerr<<"Processor::getObj id "<<id<<endl;
	if(_localObjs.find(id) != _localObjs.end())
		return _localObjs[id];
	return NULL;
}

void  Processor::sendMessage(OBJID to, Message* message){
	SObj* t = getObj(to);
	cerr<<"send message to id="<<to<<" t="<<t<<endl;
	if (t){
		TaskSendMessage* cmd = new TaskSendMessage(t, message);
		this->addTask(cmd);
	}
}
OBJID Processor::getFreeID(){
	OBJID ret;
	pthread_mutex_lock(&_lockFreeID);
		_freeIdCount++;
		ret = _freeIdCount | (_id << 24); //add the 8 bit processor id
	pthread_mutex_unlock(&_lockFreeID);
	return ret;
}

void* Processor::workThreadFunction(void* context){
	((Processor*)context)->work(); //cast the thread att to the class function
}

void Processor::work(){

	struct timespec timeToWait;
	struct timeval now;
	Task* tempCommand = NULL;

	
	while(true){
		//get next command that are ready
		tempCommand = procesFirstReadyTask(); 
		if(tempCommand){
			uint32_t result  = tempCommand->execute();
			if (result == COMMAND_FINAL)
				delete tempCommand;  //comand return 0 (DONE) delete it
			else if(result == COMMAND_REPEAT)
				this->addTask(tempCommand);
		}else{
			clock_gettime(CLOCK_REALTIME, &timeToWait);
			timeToWait.tv_nsec+=25000000;  //25ms
			if(timeToWait.tv_nsec >= 1000000000) {
				timeToWait.tv_nsec -= 1000000000;
				timeToWait.tv_sec++;
			}
			pthread_mutex_lock(&_workMutex);
			pthread_cond_timedwait(&_workCond,&_workMutex,&timeToWait);
			pthread_mutex_unlock(&_workMutex);
		}
	}
}

Task* Processor::procesFirstReadyTask(){
		Task* temp = NULL;
		//lock commandList
		pthread_mutex_lock(&this->_lockCommands);
		if(_commands.size()){
			if(_commands.front()->getTime() <= world->getTime()){
				temp = _commands.front();
				_commands.pop_front();
			}
		}
		//we are done Unlock list
		pthread_mutex_unlock(&this->_lockCommands);
		//return the command found if any
		return temp;
}

uint32_t Processor::addTask(Task* cmd){
	//lock commandlist
	pthread_mutex_lock(&this->_lockCommands);
	list<Task*>::iterator it = _commands.begin();
	//cerr<<"insert ="<<cmd<<endl;
	
	while (true){
		if(it != _commands.end()){
			if (cmd->getTime() <= (*it)->getTime()){
				cmd->setProcessor(this);
				_commands.insert(it,cmd);
				break;
			}else{
				it++;
			}
		}else{
			cmd->setProcessor(this);
			_commands.push_back(cmd);
			break;
		}
	}
	//cerr<<"content=";
	//for(list<Command*>::iterator it = _commands.begin(); it!=_commands.end(); it++){
	//	cerr<<*it<<" "<<(*it)->getTime()<<" ";
	//}
	//cerr<<endl;
	//we are done adding
	pthread_mutex_unlock(&this->_lockCommands);
	//we have work to do signal! 
	pthread_mutex_lock(&_workMutex);
	this->_workReady = true;
	pthread_mutex_unlock(&_workMutex);
	pthread_cond_signal(&this->_workCond);
	return 0;
}

uint32_t Processor::removeTask(Task* cmd){
	cerr<<"remove command"<<endl;
	pthread_mutex_lock(&this->_lockCommands);
	list<Task*>::iterator it = _commands.begin();
	while(it != _commands.end()){
		if(*it == cmd){
			cmd->setProcessor(NULL);
			_commands.remove(cmd);
			pthread_mutex_unlock(&this->_lockCommands);
			return 1;
		}
		it++;
	}
	pthread_mutex_unlock(&this->_lockCommands);
	return 0;
}

Processor::~Processor() {
}

