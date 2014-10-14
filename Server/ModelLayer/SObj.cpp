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

void SObj::signal(SIGNAL::Enum type, Signal* data){
	map<SIGNAL::Enum, list<SComponent*> >::iterator it = _signalAccept.find(type);
	if (it != _signalAccept.end()){
		for (list<SComponent*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			(*it2)->acceptSignal(type, data);
		}
	}
}


SObj::~SObj() {
}

