/* 
 * File:   TaskCreateObj.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 20:28
 */

#include "TaskCreateObj.h"
#include "../ModelLayer/SObj.h"
#include "../ModelLayer/Components/SComponent.h"
#include "../ModelLayer/Components/ComponentFactory.h"

#include "../Processor/Processor.h"

TaskCreateObj::TaskCreateObj(bool persistent, OBJID fromId) :
Task(0) {
	_persistent = persistent;
	_id = 0;
	_fromid = fromId;
}

TaskCreateObj::TaskCreateObj(OBJID id, OBJID fromId, bool persistent) :
Task(0) {
	_persistent = persistent;
	_id = id;
	_fromid = fromId;
}

bool TaskCreateObj::addComponent(SComponent* cmp){
	if(_components.find(cmp->getType()) != _components.end()){
		return false;
	}
	_components[cmp->getType()] = cmp;
	return true;
}


void TaskCreateObj::loadData(OBJID id){

}

void TaskCreateObj::loadComponents(SObj* obj, OBJID id){

	pqxx::work w(_processor->getDB());
	stringstream s; 
	s<<"select compid from comp where objid = "<<id<<";";
	pqxx::result r = w.exec(s);
	w.commit();
	for(int i = 0; i< r.size();i++){
		SComponent* cmp = createComponent(obj,(COMPID::Enum)r[i][0].as<uint32_t>(), id, _processor->getDB());
		if(!this->addComponent(cmp))
			delete cmp;
	}
}

uint32_t TaskCreateObj::execute(){
	if(_id){//load from existing or template
		SObj* obj = new SObj(_id, _persistent, _id == _fromid, _processor);
		cerr<<"create new obj id="<<_id<<" from id="<<_fromid<<endl;
		loadComponents(obj, _fromid);
		loadData(_fromid);
		
		for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it!=_components.end(); it++){
			obj->addComponent(it->second);
		}
		
		if(_id != _fromid && _persistent)
			obj->save();
		
		_processor->addObj(obj);
	
	}else{//create new
		SObj* obj = new SObj(_processor->getFreeID(), _persistent, false, _processor);
		
		if(_fromid)
			cerr<<"create new obj id="<<obj->getId()<<" from template id="<<_fromid<<endl;
		else
			cerr<<"create new obj id="<<obj->getId() <<endl;

		if(_fromid){
			cerr<<"create new obj id="<<obj->getId()<<" from template id="<<_fromid<<endl;
			loadComponents(obj, _fromid);
			loadData(_fromid);
		}
		
		for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it!=_components.end(); it++){
			obj->addComponent(it->second);

		}
		
		if(_persistent)
			obj->save();
		_processor->addObj(obj);
	}
	
	return COMMAND_FINAL;
}

TaskCreateObj::~TaskCreateObj() {
}

