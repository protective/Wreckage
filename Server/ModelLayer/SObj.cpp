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
}
void SObj::addComponent(SComponent* comp){
	comp->setObj(this);
	_components[comp->_type] = comp;
}

void SObj::signal(SIGNAL::Enum type, Signal* data){
	map<SIGNAL::Enum, list<SComponent*> >::iterator it = _signalAccept.find(type);
	if (it != _signalAccept.end()){
		for (list<SComponent*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			(*it2)->acceptSignal(type, data);
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

	
SObj::~SObj() {
}

