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

SObj::SObj(OBJID id, bool persistent, Processor* processor) {
	_id = id;
	_processor = processor;
	_flags = persistent ? OBJFLAGPERSISTENT : 0;
}
void SObj::addComponent(SComponent* comp){
	if(comp){
		comp->setObj(this);
		_components[comp->_type] = comp;
		
		if(isPersistent() && isInit()){
			stringstream s;
			pqxx::work w2(_processor->getDB());

			s<<"insert into comp values( "
				<<_id<<", "
				<<comp->getType()<<");";
			w2.exec(s);
			w2.commit();
			comp->dbSave();
		}
	}
}

void SObj::addData(OBJDATA::Enum id, int32_t value){
	if(_data.find(id) != _data.end()){
		_data[id] = value;
		if(isPersistent() && isInit()){
			pqxx::work w3(_processor->getDB());	
			stringstream s;
			s<<"insert into objdata values("
			<<_id<<", "
			<<id<<", "
			<<value<<");";
			w3.exec(s);
		}
			
	}
}

void SObj::signal(SIGNAL::Enum type, Signal* data){
	//map<SIGNAL::Enum, list<SComponent*> >::iterator it = _signalAccept.find(type);
	//if (it != _signalAccept.end()){
	for (map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it != _components.end(); it++){
		it->second->acceptSignal(type, data);
	}
	//}
}

void SObj::message(MESSAGE::Enum type, Message* data){
	for (map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it != _components.end(); it++){
		it->second->acceptMessage(type, data);
	}
	//NOTE the task is responsible for deleting the message data
}


void SObj::save(){
	
	if(isInit()){
		//pqxx::work w(_processor->getDB());

		for(map<COMPID::Enum ,SComponent*>::iterator it = _components.begin(); it!= _components.end(); it++){
			it->second->dbSave();
		}
		
		pqxx::work w3(_processor->getDB());	
		for(map<OBJDATA::Enum ,int32_t>::iterator it = _data.begin(); it!= _data.end(); it++){
			stringstream s;
			s<<"update objdata set value = "
				<<(int32_t)it->second<<" where "
				<<"objId = "<<_id<<" and " 
				<<"dataId = "<< it->first<<");";
			w3.exec(s);

		}
		w3.commit();
		
		
		
	}else{
		init();
	}
}

void SObj::init(){
	pqxx::work w(_processor->getDB());

	stringstream s1;
	s1<<"insert into objs values("<<_id<<","<<(isTemplate()? "true": "false")<<");";
	w.exec(s1);
	w.commit();	
	for(map<COMPID::Enum ,SComponent*>::iterator it = _components.begin(); it!= _components.end(); it++){
		stringstream s;
		pqxx::work w2(_processor->getDB());

		s<<"insert into comp values( "
			<<_id<<", "
			<<(uint32_t)it->first<<");";
		w2.exec(s);
		w2.commit();
		it->second->dbSave();
	}
	
	pqxx::work w3(_processor->getDB());	
	for(map<OBJDATA::Enum ,int32_t>::iterator it = _data.begin(); it!= _data.end(); it++){
		stringstream s;
		s<<"insert into objdata values("
			<<_id<<", "
			<<it->first<<", "
			<<(int32_t)it->second<<");";
		w3.exec(s);
			
	}
	w3.commit();
	_flags &= OBJFLAGINIT;
}

SObj::~SObj() {
}

