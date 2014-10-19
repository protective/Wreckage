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
#include "../ModelLayer/SObj.h"

#include "../Tasks/Task.h"

NetworkControler::NetworkControler() {
	
	pthread_mutex_init(&_clientLock ,NULL);
}

void NetworkControler::readBuffers(){
	for (map<uint32_t, Client*>::iterator ci = _connections.begin(); ci != _connections.end(); ci++){
		ReadBuffer(ci->second);
		ci->second->proces();
	}
}

SObj* NetworkControler::getObj(OBJID obj){
	Processor* temp = processors[1];
	if(temp)
		return temp->getObj(obj);
	return NULL;
}


uint32_t NetworkControler::addTaskToObj(Task* task, OBJID obj){
	Processor* temp = processors[1];
	if(temp){
		cerr<<"NetworkControler::addTaskToObj"<<endl;
		return temp->addTask(task);
	}
	return 1;
}

uint32_t NetworkControler::sendToC(uint32_t id, void* block, uint32_t len){
	bool sendt = false;
	//cerr<<"send to c= "<<id<<endl;
	pthread_mutex_lock(&_clientLock);
	map<uint32_t, Client*>::iterator it = _connections.find(id);
	if (it!= _connections.end()){
		//cerr<<"network send len ="<<len<<endl;
		send(it->second->getSocket(),block, len,MSG_NOSIGNAL);
		sendt = true;
	}else
		cerr<<"ERROR CLIENT NOT FOUND id="<<id<<endl;
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
}
void NetworkControler::removeClient(Client* client){
	_connections.erase(client->getId());
}

NetworkControler::~NetworkControler() {
}

