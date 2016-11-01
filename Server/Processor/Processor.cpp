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

#include "../ModelLayer/Messages/MessageSystemBroadcast.h"

#include "../ModelLayer/Signals/SignalEnterClient.h"
#include "../ModelLayer/Signals/SignalExitClient.h"

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
	

	stringstream s;
	
	pqxx::work w2(*_dbCon);
	w2.exec("delete from comp where objid NOT IN (select objid from objs);");

	w2.exec("delete from objdata where objid NOT IN (select objid from objs);");
	
	w2.exec("delete from objpos where objid NOT IN (select objid from objs);");
	w2.commit();	
	
	pqxx::work w(*_dbCon);
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
		OBJID id = r[i][0].as<OBJID>();
		OBJID from = r[i][0].as<OBJID>();
		addTask(new TaskCreateObj(id, from, true));
		addTask(new TaskSendMessage(id, 
					new MessageSystemBroadcast(0, MessageSystemBroadcast::dbloadObjComplete),
				1000)
				);
	}	
}

SObj* Processor::createObj(
	OBJID id,
	OBJID fromId,
	bool makePersistent,
	bool makeTemplate)
{
	if(id == 0)
		id = this->getFreeID();
	if(fromId){
		pqxx::work w(this->getDB());	
		stringstream s; s<<"select istemplate, cloneispersistent from objs where objid = "<<fromId<<";";
		pqxx::result r = w.exec(s); w.commit();	

		if(id != fromId){
			makeTemplate = false;
			makePersistent = r[0][1].as<bool>();
		}else if(id == fromId){
			makeTemplate = r[0][0].as<bool>();
			makePersistent = true;
		}
	}
	SObj* obj = new SObj(id, makePersistent, makeTemplate, id == fromId, this);
	if(fromId)
		this->setClone(fromId, obj);
	cerr<<"create new obj id="<<id<<" from id="<<fromId<<endl;

	loadComponents(obj, fromId);
	loadData(obj, fromId);
	loadPos(obj, fromId);

	if(id != fromId && makePersistent)
		obj->save();

	this->addObj(obj);
	return obj;
}

void Processor::loadData(SObj* obj, OBJID fromId){
	/*
	 * 
	 * TODO do we need this?
	for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it != _components.end();it++){
		for (list<OBJDATA::Enum>::iterator it2 = it->second->getDataAccesUssage().begin() ; it2 != it->second->getDataAccesUssage().end();it2++){
			obj->setData(*it2, 0);
		}
	}
	*/
	SObj* from = this->getObj(fromId);
	if (from) {
		for (auto& kv: from->getData()) {
			obj->setData(kv.first, kv.second);
		}
	} else {
		pqxx::work w(this->getDB());
		stringstream s;
		s<<"select dataid, value from objdata where "
		"objid = "<<fromId<<";";
		pqxx::result r = w.exec(s); w.commit();
		for (int i = 0; i< r.size(); i++){
			obj->setData((OBJDATA::Enum)r[i][0].as<int32_t>(), r[i][1].as<int32_t>());
		}
	}
}

void Processor::loadPos(SObj* obj, OBJID fromId){
	SObj* from = this->getObj(fromId);
	if (from) {
		SPos* p = from->getPos();
		if (p)
			obj->setPos(*p);
	} else {
		pqxx::work w(this->getDB());
		stringstream s;
		s<<"select x, y, z, d from objpos where "
		"objid = "<<fromId<<";";
		pqxx::result r = w.exec(s); w.commit();
		if ( r.size() > 0){
			SPos p(r[0][0].as<int32_t>(),r[0][1].as<int32_t>(),r[0][2].as<int32_t>(),r[0][3].as<uint16_t>());
			obj->setPos(p);
		}
	}
}

void Processor::loadComponents(SObj* obj, OBJID fromId){
	SObj* from = this->getObj(fromId);
	if (from) {
		for (auto& kv : from->getComponents()) {
			obj->addComponent(kv.second->clone(obj));
		}
	} else {
		pqxx::work w(this->getDB());
		stringstream s;
		s<<"select compid from comp where objid = "<<fromId<<";";
		pqxx::result r = w.exec(s);
		w.commit();
		for(int i = 0; i< r.size();i++){
			SComponent* cmp = createComponent(obj, (COMPID::Enum)r[i][0].as<uint32_t>(), fromId, this->getDB());
			obj->addComponent(cmp);
		}
	}
}

void Processor::addObj(SObj* obj){
	if(obj){
		_localObjs[obj->getId()] = obj;
		TaskProcess* task = new TaskProcess(obj,1000);
		addTask(task);
		obj->setProcessTask(task);
		networkControl->registerObj(obj->getId(),this);
	}else
		cerr<<"ERROR Processor::addObj obj = NULL"<<endl;
}

void Processor::removeObj(SObj* obj){
	if(obj){
		_localObjs[obj->getId()] = obj;
		obj->getProcessTask()->objDeleted();
		networkControl->deRegisterObj(obj->getId());
		delete obj;
	}else
		cerr<<"ERROR Processor::addObj obj = NULL"<<endl;
}

SObj* Processor::getObj(OBJID id){
	if(_localObjs.find(id) != _localObjs.end())
		return _localObjs[id];
	return NULL;
}



void  Processor::sendMessage(OBJID to, Message* message){
	TaskSendMessage* cmd = new TaskSendMessage(to, message);
	this->addTask(cmd);
}

void  Processor::sendMessage(OBJID to, Message* message, uint32_t delay){
	TaskSendMessage* cmd = new TaskSendMessage(to, message, delay);
	this->addTask(cmd);
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

void Processor::addClientView(uint32_t id){
	_clientViews[id] = new ClientViews(id);

	for(map<OBJID, SObj*>::iterator it = _localObjs.begin(); it != _localObjs.end(); it++){
		SignalEnterClient s(id);
		it->second->signal(SIGNAL::enterClient, &s);
		it->second->signal(SIGNAL::enterDevClient, &s);
	}
}

void Processor::removeClientView(uint32_t id){
	
	for(map<OBJID, SObj*>::iterator it = _localObjs.begin(); it != _localObjs.end(); it++){
		SignalExitClient s(id);
		it->second->signal(SIGNAL::exitClient, &s);
	}
	if (_clientViews.find(id) != _clientViews.end()){
		delete _clientViews[id];
		_clientViews.erase(id);
	}		
}

uint32_t Processor::removeTask(Task* cmd){
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
	
	for(map<uint32_t, ClientViews*>::iterator it = _clientViews.begin(); it != _clientViews.end(); it++){
		delete it->second;
	}
}

