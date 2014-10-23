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

TaskCreateObj::TaskCreateObj(OBJID id, OBJID fromId, bool persistent) :
Task(0) {
	_persistent = persistent;
	_isTemplate = false;
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

bool TaskCreateObj::addData(OBJDATA::Enum dataid, int32_t value){
	if(_data.find(dataid) != _data.end()){
		return false;
	}
	_data[dataid] = value;
	return true;
}


void TaskCreateObj::loadData(SObj* obj, OBJID id){
	pqxx::work w(_processor->getDB());
	
	for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it != _components.end();it++){
		for (list<OBJDATA::Enum>::iterator it2 = it->second->getDataAccesUssage().begin() ; it2 != it->second->getDataAccesUssage().end();it2++){
			obj->setData(*it2,0);
			
		}
	}
	
	stringstream s;
	s<<"select dataid, value from objdata where "
	"objid = "<<id<<";";
	pqxx::result r = w.exec(s); w.commit();	
	for (int i = 0; i< r.size(); i++){
		obj->setData((OBJDATA::Enum)r[i][0].as<int32_t>(), r[i][0].as<int32_t>());
	}

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
		if(_fromid){
			pqxx::work w(_processor->getDB());	
			stringstream s; s<<"select istemplate, cloneispersistent from objs where objid = "<<_fromid<<";";
			pqxx::result r = w.exec(s); w.commit();	
			
			if(_id != _fromid){
				_isTemplate = false;
				_persistent = r[0][1].as<bool>();
			}else if(_id == _fromid){
				_isTemplate = r[0][0].as<bool>();
				_persistent = true;
			}
		}
		SObj* obj = new SObj(_id, _persistent, _isTemplate, _id == _fromid, _processor);
		cerr<<"create new obj id="<<_id<<" from id="<<_fromid<<endl;
		
		for(map<OBJDATA::Enum, int32_t>::iterator it = _data.begin(); it != _data.end(); it++){
			obj->setData(it->first, it->second);
		}
		
		loadComponents(obj, _fromid);
		loadData(obj, _fromid);
		
		for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it!=_components.end(); it++){
			obj->addComponent(it->second);
		}
		
		if(_id != _fromid && _persistent)
			obj->save();
		
		_processor->addObj(obj);
	
	}
	return COMMAND_FINAL;
}

TaskCreateObj::~TaskCreateObj() {
}

