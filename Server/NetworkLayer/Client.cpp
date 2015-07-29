/* 
 * File:   Client.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 10:00
 */

#include <vector>
#include "NetworkFunctions.h"
#include "NetworkControler.h"

#include "Client.h"
#include "../ModelLayer/Components/ComponentFactory.h"
#include "../ModelLayer/Components/SComponent.h"
#include "../ModelLayer/Components/CompReSpawnable/CompReSpawnable.h"
#include "../ModelLayer/Components/CompSpawnNode/CompSpawnNode.h"

#include "../Tasks/TaskAddComponent.h"
#include "../Tasks/TaskRemoveObj.h"
#include "../Tasks/TaskAcceptInput.h"
#include "../Tasks/TaskAddClientView.h"
#include "../Tasks/TaskCreateObj.h"


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
	
	pthread_mutex_init(&this->_lockState, NULL);
	
	pthread_mutex_lock(&this->networkSendLock);
	networkSendLockBool = true;
	pthread_mutex_unlock(&this->networkSendLock);
	
	this->_isDisconnecting = false;
	//this->switchBuffer();
	inputnetworkBuf = &networkBuf1;
	outputnetworkBuf = &networkBuf2;

}


void Client::sendToC(void* block, uint32_t len){
	
	send(this->getSocket(), block, len,MSG_NOSIGNAL);
}

void Client::ReadBuffer(){
	if (this->outputnetworkBuf->recived > 0){
		//************************************
		//CRITICAL
		pthread_mutex_lock(&this->networkBufLock);
		this->parsingoutput = true;
		pthread_mutex_unlock(&this->networkBufLock);
		//CRITICAL
		//************************************
		//if(printbufferbool)
		uint32_t delta = parseBuffer(this->outputnetworkBuf->recived);

		memmove(this->outputnetworkBuf->networkBuf, this->outputnetworkBuf->networkBuf+ delta, this->outputnetworkBuf->recived- delta);

		this->outputnetworkBuf->recived -= delta;

		//************************************
		//CRITICAL
		pthread_mutex_lock(&this->networkBufLock);
		this->parsingoutput = false;
		pthread_mutex_unlock(&this->networkBufLock);
		//CRITICAL
		//************************************
	}
}


uint32_t Client::parseBuffer(uint32_t len){
	unsigned char* buffer = this->outputnetworkBuf->networkBuf;
	uint32_t offset = 0;
	uint32_t remaning = 0;
	printBuffer(buffer,len);
	while (offset < len && !this->isDisconnecting()){
		SerialData* temp = (SerialData*)(buffer + offset);
		if(temp->_size < sizeof(SerialData))
			this->disconnect();
		
		if (len - offset >= sizeof(uint32_t)*2 && temp->_size <= len - offset){
			//cerr<<"parse single "<<endl;
			remaning = len - offset;
			switch(temp->_type)
			{
				case SerialType::SerialTime:{
					SerialTime* st = (SerialTime*)(buffer+offset);

					char message[sizeof(SerialTime)];
					memset(message,0,sizeof(SerialTime));

					SerialTime* data = (SerialTime*)(message);
					data->_type = SerialType::SerialTime;
					data->_size = sizeof(SerialTime);
					data->time = SDL_GetTicks();
					data->local = st->local;
					sendToC(message,sizeof(SerialTime));

					break;
				}
				case SerialType::SerialReqJoin:{
					SerialReqJoin* st = (SerialReqJoin*)(buffer+offset);
					this->setPlayerId(st->_unitId);
					this->initTransfere();

					break;
				}
				case SerialType::SerialAddComponent:{
					SerialAddComponent* st = (SerialAddComponent*)(buffer+offset);
					SObj* obj = networkControl->getObj(st->_unitId);
					if(!obj){
						//cerr<<"SerialType::SerialAddComponent: obj not found "<<endl;
						break;
					}
					//TaskAddComponent * t = new TaskAddComponent(obj, new CompSpawnNode(10000,1,0));
					TaskRemoveObj * t = new TaskRemoveObj(st->_unitId);
					networkControl->addTaskToObj(t,st->_unitId);

					break;
				}
				case SerialType::SerialInput:{
					cerr<<"SerialType::SerialInput"<<endl;
					SerialInput* st = (SerialInput*)(buffer+offset);
					SObj* obj = networkControl->getObj(st->_unitId);
					if(!obj){
						break;
					}
					
					SerialInputPayload* data = NULL;
					switch (((SerialInputPayload*)(&st[1]))->_type){
						case SERIALINPUT::SerialInputCastPower:{
							data = (SerialInputPayload*)malloc(sizeof(SerialInputCastPower));
							memcpy(data, &st[1], sizeof(SerialInputCastPower));
							break;
						}
						case SERIALINPUT::SerialIndputSetCompValue:{
							//TODO security
							uint32_t tmp = st->_size;
							
							data = (SerialInputPayload*)malloc(st->_size);
							memcpy(data, &st[1], st->_size);
							break;
						}
						default:{
							break;
						}
						
					}
					TaskAcceptInput * t = new TaskAcceptInput(st->_unitId, data);
					networkControl->addTaskToObj(t,st->_unitId);

					break;
				}
				
				case SerialType::SerialEdit:{
					cerr<<"SerialType::SerialEdit"<<endl;
					SerialData* st = (SerialData*)(buffer+offset);

					switch (((SerialEdit::header*)(&st[1]))->_type){
						case SerialEdit::op::DeleteObj:{
							SerialEdit::DeleteObj* tmp = (SerialEdit::DeleteObj*)&st[1];
							TaskRemoveObj * t = new TaskRemoveObj(tmp->_id);
							networkControl->addTaskToObj(t, tmp->_id);
							break;
						}
						default:{
							break;
						}
						
					}

					break;
				}


				case SerialType::SerialCmdCreateObj:{
					SerialCmdCreateObj* st = (SerialCmdCreateObj*)(buffer+offset);
					
					//TaskAddComponent * t = new TaskAddComponent(obj, new CompSpawnNode(10000,1,0));
					cerr<<"st "<<st<<endl;
					TaskCreateObj* t = new TaskCreateObj(0, st->_template, true);
					SerialObjData* sd = (SerialObjData*)st->_data;
					cerr<<"sd "<<sd<<endl;
					while(sd->_dataType){
						switch(sd->_dataType){
							case OBJDATA::position: {
								t->addPos(new SPos((SerialObjDataPos*)sd));	
								sd = &(((SerialObjDataPos*)sd)[1]);
							}
							default:{
								t->addData((OBJDATA::Enum)((SerialObjDataValue*)sd)->_dataType,((SerialObjDataValue*)sd)->_value);
								sd = &(((SerialObjDataValue*)sd)[1]);
							}
						}
						
						cerr<<"WARNING shoudl be empty "<<sd->_dataType<<endl;
						break;
					}
					SerialObjComp* sc = (SerialObjComp*) (&sd[1]);
					cerr<<"sc "<<sc<<endl;
					while(sc->_compType){
						cerr<<"WARNING shoudl also be empty "<<sc->_compType<<endl;
				
						//component size is max the min of remaning buffer of the size of the package
						int32_t cmpSize = min(remaning, temp->_size);
						t->addComponent(createComponent(sc, &cmpSize));
						if(cmpSize){
							sc += cmpSize; //increasse by the buffer read by the factory
						}else{
							cerr<<"parse buffer SerialType::SerialCmdCreateObj WARNING this should not happen"<<endl;
							break;
						}
					}
					
					networkControl->addTaskToObj(t,0);

					break;
				}
				default:{
					cerr<<"error no packet parse function defined"<<endl;
					offset = len;
					break;
				}
			}
			offset += temp->_size;
		}else{
			cerr<<"servermissing data"<<endl;
			break;
		}
			
	}
	//cerr<<"end parse  "<<endl;
	return offset;
}



void Client::initTransfere(){
}

Client::~Client() {
}

