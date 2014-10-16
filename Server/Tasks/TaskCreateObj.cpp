/* 
 * File:   TaskCreateObj.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 20:28
 */

#include "TaskCreateObj.h"
#include "../ModelLayer/SObj.h"
#include "../ModelLayer/Components/SComponent.h"

#include "../Processor/Processor.h"

TaskCreateObj::TaskCreateObj(bool persistent) :
Task(0) {
	_persistent = persistent;
	
}

void TaskCreateObj::addComponent(SComponent* cmp){

	_components[cmp->getType()] = cmp;
}

uint32_t TaskCreateObj::execute(){
	cerr<<"TaskCreateObj::execute"<<endl;
	SObj* obj = new SObj(_processor->getFreeID(), _processor);
	_processor->addObj(obj);

	for(map<COMPID::Enum, SComponent*>::iterator it = _components.begin(); it!=_components.end(); it++){
		obj->addComponent(it->second);
	}
	if(_persistent)
		obj->save();
	
	return COMMAND_FINAL;
}

TaskCreateObj::~TaskCreateObj() {
}

