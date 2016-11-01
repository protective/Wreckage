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

uint32_t TaskCreateObj::execute(){
	SObj* obj = _processor->createObj(_id, _fromid, _makePersistent, _makeTemplate);
	for(auto &it: _components){
		obj->addComponent(it.second);
	}
	for(auto &it: _data){
		obj->addData(it.first, it.second);
	}
	if (_pos)
		obj->setPos(*_pos);
	
	SignalCreated s(_clientId, _creationRef);
	obj->signal(SIGNAL::created, &s);

	return COMMAND_FINAL;
}

TaskCreateObj::~TaskCreateObj() {
	if(_pos)
		delete _pos;
}

