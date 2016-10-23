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

#include "../ModelLayer/Signals/SignalCreated.h"

TaskCreateObj::TaskCreateObj(
    OBJID id,
    OBJID fromId,
    bool makePersistent,
    bool makeTemplate,
    TIME spawnTime,
    uint32_t clientId,
    uint32_t creationRef) :
Task(spawnTime) {
    _makePersistent = makePersistent;
    _makeTemplate = makeTemplate;
    _id = id;
    _fromid = fromId;
    _creationRef = creationRef;
    _clientId = clientId;
    _pos = NULL;
}

bool TaskCreateObj::addComponent(SComponent* cmp){
	if(!cmp)
		return false;
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

bool TaskCreateObj::addPos(SPos* pos){
	if (_pos)
		delete _pos;
	_pos = pos;
	return true;
}

void TaskCreateObj::loadData(SObj* obj, OBJID fromId){

	for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it != _components.end();it++){
		for (list<OBJDATA::Enum>::iterator it2 = it->second->getDataAccesUssage().begin() ; it2 != it->second->getDataAccesUssage().end();it2++){
			obj->setData(*it2, 0);
		}
	}
	SObj* from = _processor->getObj(fromId);
	if (from) {
		for (auto& kv: from->getData()) {
			obj->setData(kv.first, kv.second);
		}
	} else {
		pqxx::work w(_processor->getDB());
		stringstream s;
		s<<"select dataid, value from objdata where "
		"objid = "<<fromId<<";";
		pqxx::result r = w.exec(s); w.commit();
		for (int i = 0; i< r.size(); i++){
			obj->setData((OBJDATA::Enum)r[i][0].as<int32_t>(), r[i][1].as<int32_t>());
		}
	}
}

void TaskCreateObj::loadPos(SObj* obj, OBJID fromId){
	SObj* from = _processor->getObj(fromId);
	if (from) {
		SPos p(from->getPos()->x(), from->getPos()->y(), from->getPos()->z(), from->getPos()->d());
		obj->setPos(p);
	} else {
		pqxx::work w(_processor->getDB());
		stringstream s;
		s<<"select x, y, z, d from objpos where "
		"objid = "<<fromId<<";";
		pqxx::result r = w.exec(s); w.commit();
		if ( r.size() > 0){
			SPos p(r[0][0].as<int32_t>(),r[0][1].as<int32_t>(),r[0][2].as<int32_t>(),r[0][3].as<uint16_t>());
			obj->setPos(p);
		}
	}
}

void TaskCreateObj::loadComponents(SObj* obj, OBJID fromId){
	SObj* from = _processor->getObj(fromId);
	if(from) {
		for (auto& kv : from->getComponents()) {
			this->addComponent(kv.second->clone());
		}
	} else {
		pqxx::work w(_processor->getDB());
		stringstream s;
		s<<"select compid from comp where objid = "<<fromId<<";";
		pqxx::result r = w.exec(s);
		w.commit();
		for(int i = 0; i< r.size();i++){
			SComponent* cmp = createComponent(obj,(COMPID::Enum)r[i][0].as<uint32_t>(), fromId, _processor->getDB());
			if(!this->addComponent(cmp))
				delete cmp;
		}
	}
}

uint32_t TaskCreateObj::execute(){
	if(_id == 0)
		_id = _processor->getFreeID();
	if(_id){//load from existing or template
		if(_fromid){
			pqxx::work w(_processor->getDB());	
			stringstream s; s<<"select istemplate, cloneispersistent from objs where objid = "<<_fromid<<";";
			pqxx::result r = w.exec(s); w.commit();	

			if(_id != _fromid){
				_makeTemplate = false;
				_makePersistent = r[0][1].as<bool>();
			}else if(_id == _fromid){
				_makeTemplate = r[0][0].as<bool>();
				_makePersistent = true;
			}
		}
		SObj* obj = new SObj(_id, _makePersistent, _makeTemplate, _id == _fromid, _processor);
		if(_fromid)
			_processor->setClone(_fromid, obj);
		cerr<<"create new obj id="<<_id<<" from id="<<_fromid<<endl;

		for(map<OBJDATA::Enum, int32_t>::iterator it = _data.begin(); it != _data.end(); it++){
			obj->setData(it->first, it->second);
		}
		if(_pos)
			obj->setPos(*_pos);

		//load components to add to the task
		loadComponents(obj, _fromid);
		loadData(obj, _fromid);
		loadPos(obj, _fromid);

		//add components from the task to obj
		for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it!=_components.end(); it++){
			obj->addComponent(it->second);
		}

		if(_id != _fromid && _makePersistent)
			obj->save();

		_processor->addObj(obj);
		SignalCreated s(_clientId, _creationRef);
		obj->signal(SIGNAL::created, &s);

	}
	return COMMAND_FINAL;
}

TaskCreateObj::~TaskCreateObj() {
	if(_pos)
		delete _pos;
}

