/* 
 * File:   SObj.cpp
 * Author: karsten
 * 
 * Created on 13. oktober 2014, 23:08
 */

#include "SObj.h"
#include "Components/SComponent.h"
#include "Signals/Signal.h"

SObj::SObj(OBJID id) {
	_id = id;
	_processor = NULL;
}
void SObj::addComponent(SComponent* comp){
	if(comp){
		comp->setObj(this);
		_components[comp->_type] = comp;
	}
}

void SObj::signal(SIGNAL::Enum type, Signal* data){
	map<SIGNAL::Enum, list<SComponent*> >::iterator it = _signalAccept.find(type);
	if (it != _signalAccept.end()){
		for (list<SComponent*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			(*it2)->acceptSignal(type, data);
		}
	}
}

void SObj::message(MESSAGE::Enum type, Message* data){
	map<MESSAGE::Enum, list<SComponent*> >::iterator it = _messageAccept.find(type);
	if (it != _messageAccept.end()){
		for (list<SComponent*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			(*it2)->acceptMessage(type, data);
		}
	}
}

void SObj::subscribeSignal(SIGNAL::Enum signal, SComponent* comp){
	_signalAccept[signal].push_back(comp);
}
void SObj::unSubscribeSignal(SIGNAL::Enum signal, SComponent* comp){
	if(_signalAccept.find(signal) != _signalAccept.end())
		_signalAccept[signal].remove(comp);
}

void SObj::subscribeMessage(MESSAGE::Enum message, SComponent* comp){
	_messageAccept[message].push_back(comp);
}
void SObj::unSubscribeMessage(MESSAGE::Enum message, SComponent* comp){
	if(_messageAccept.find(message) != _messageAccept.end())
		_messageAccept[message].remove(comp);
}

SObj::~SObj() {
}

