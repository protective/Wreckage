/* 
 * File:   NetworkControler.cpp
 * Author: karsten
 * 
 * Created on 22. februar 2014, 23:13
 */

#include "NetworkControler.h"
#include "Client.h"
#include "NetworkFunctions.h"

#include "../Processor/Processor.h"

#include "../Tasks/TaskSendMessage.h"

#include "../ModelLayer/SObj.h"
#include "../ModelLayer/Messages/Message.h"
#include "../ModelLayer/Messages/MessageObjDeleted.h"
#include "../ModelLayer/Messages/MessageHeartBeatReq.h"
#include "../ModelLayer/Messages/MessageHeartBeatRsp.h"

#include "../Tasks/Task.h"

NetworkControler::NetworkControler() {
	
	pthread_mutex_init(&_clientLock ,NULL);
	pthread_mutex_init(&_objRegistrationListLock ,NULL);
}

void NetworkControler::registerObj(OBJID obj, Processor* processor){
	pthread_mutex_lock(&_objRegistrationListLock);
	_objRegistration[obj] = processor;
	pthread_mutex_unlock(&_objRegistrationListLock);
}

void NetworkControler::deRegisterObj(OBJID obj){
	pthread_mutex_lock(&_objRegistrationListLock);
	_objRegistration.erase(obj);
	map<OBJID, list<OBJID> >::iterator it = _objRefs.find(obj);
	if( it != _objRefs.end()){
		for(list<OBJID>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			sendObjDel(*it2 , obj);
		}
		_objRefs.erase(it);
	}
		
	pthread_mutex_unlock(&_objRegistrationListLock);

}

void NetworkControler::readBuffers(){
	for (map<uint32_t, Client*>::iterator ci = _connections.begin(); ci != _connections.end(); ci++){
		ci->second->ReadBuffer();
		ci->second->proces();
	}
}

SObj* NetworkControler::getObj(OBJID obj){
	Processor* temp = processors[1];
	if(temp)
		return temp->getObj(obj);
	return NULL;
}

void NetworkControler::sendObjDel(OBJID to, OBJID deleted){
	MessageObjDeleted* msg = new MessageObjDeleted(0, deleted);
	sendMessage(to, msg);
}


void  NetworkControler::sendMessage(OBJID to, Message* message){

	Processor* processor = NULL ;
	map<OBJID, Processor*>::iterator it = _objRegistration.find(to);
	if(it != _objRegistration.end()){
		if(message->_type == MESSAGE::requestRefObj){
			pthread_mutex_lock(&_objRegistrationListLock);
			_objRefs[to].push_back(message->_fromId);
			pthread_mutex_unlock(&_objRegistrationListLock);
			delete message;
			return;
		}
		
		if (it->second){
			TaskSendMessage* cmd = new TaskSendMessage(to, message);
			it->second->addTask(cmd);
		}
	}else{
		if(to != 0)
			sendObjDel(message->_fromId, to);
		if(message->_type == MESSAGE::HeartBeatReq){
			MessageHeartBeatRsp* msg = new MessageHeartBeatRsp(to, false);
			sendMessage(message->_fromId, msg);

		}
			
		delete message;
	}
}

uint32_t NetworkControler::addTaskToObj(Task* task, OBJID obj){
	Processor* temp = processors[1];
	if(temp){
		cerr<<"NetworkControler::addTaskToObj"<<endl;
		return temp->addTask(task);
	}
	return 1;
}

uint32_t NetworkControler::sendToC(uint32_t clientId, void* block, uint32_t len){
	
	bool sendt = false;
	cerr<<"send to c= "<<clientId<<endl;
	pthread_mutex_lock(&_clientLock);
	map<uint32_t, Client*>::iterator it = _connections.find(clientId);
	if (it!= _connections.end()){
		//cerr<<"network send len ="<<len<<endl;
		cerr<<"send IT len="<<len<<endl;
		it->second->sendToC(block, len);
		sendt = true;
	}else
		cerr<<"ERROR CLIENT NOT FOUND id="<<clientId<<endl;
	pthread_mutex_unlock(&_clientLock);
	if(sendt)
		return 0;
	else
		return 1;
}

void NetworkControler::addClient(Client* client){
	cerr<<"add cli before lock"<<endl;
	pthread_mutex_lock(&_clientLock);
	cerr<<"add cli ="<<client->getId()<<endl;
	_connections[client->getId()] = client;
	pthread_mutex_unlock(&_clientLock);
	
	for(map<uint8_t,Processor*>::iterator it = processors.begin(); it != processors.end();it++){
		it->second->addClientView(client->getId());
	}
}
void NetworkControler::removeClient(Client* client){
	_connections.erase(client->getId());
}

NetworkControler::~NetworkControler() {
}

