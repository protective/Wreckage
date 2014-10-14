/* 
 * File:   Client.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 10:00
 */

#include <vector>
#include "NetworkFunctions.h"
#include "Client.h"

Client::Client(int socket) {

	this->socket = socket;
	_id = 0;
	playerID = 0;
	
	_teamId = 2;
	this->parsingoutput = false;
	this->active_buffer = 1;
	this->networkBuf1.recived = 0;
	this->networkBuf2.recived = 0;
	pthread_mutex_init(&this->networkBufLock, NULL);
	pthread_mutex_init(&this->networkSendLock, NULL);
	pthread_mutex_init(&this->locksubscriber, NULL);
	
	pthread_mutex_lock(&this->networkSendLock);
	networkSendLockBool = true;
	pthread_mutex_unlock(&this->networkSendLock);
	//this->switchBuffer();
	inputnetworkBuf = &networkBuf1;
	outputnetworkBuf = &networkBuf2;

	cerr << "create client" << endl;
}


void Client::initTransfere(){
	cerr<<"init transfere"<<endl;
	
	cerr<<"data sendt"<<endl;
}

Client::~Client() {
}

