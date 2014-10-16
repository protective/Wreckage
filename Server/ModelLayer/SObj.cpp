/* 
 * File:   SObj.cpp
 * Author: karsten
 * 
 * Created on 13. oktober 2014, 23:08
 */

#include "SObj.h"
#include "Components/SComponent.h"
#include "Signals/Signal.h"
#include "../Processor/Processor.h"

SObj::SObj(OBJID id, Processor* processor) {
	_id = id;
	_processor = processor;
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


void SObj::save(){
	
	
	pqxx::work w(_processor->getDB());
	
	stringstream s1;
	s1<<"delete from comp where "
	"objId = "<<_id<<";"
	"delete from objs where objid = "<<_id<<";"
	"insert into objs values("<<_id<<","<<(isTemplate()? "true": "false")<<");";
	w.exec(s1);
		
	for(map<COMPID::Enum ,SComponent*>::iterator it = _components.begin(); it!= _components.end(); it++){
		stringstream s;
		s<<"insert into comp values( "
			<<_id<<", "
			<<(uint32_t)it->first<<");";
		w.exec(s);
		it->second->dbSave();
	}
	w.commit();	

	
	
	//pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='objs');");

}


SObj::~SObj() {
}

