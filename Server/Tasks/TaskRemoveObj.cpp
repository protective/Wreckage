/* 
 * File:   TaskRemoveObj.cpp
 * Author: karsten
 * 
 * Created on 19. oktober 2014, 12:05
 */

#include "TaskRemoveObj.h"

#include "../ModelLayer/SObj.h"

#include "../ModelLayer/Components/SComponent.h"

#include "../Processor/Processor.h"

TaskRemoveObj::TaskRemoveObj(OBJID obj) :
Task(0) {
	_obj = obj;
}


uint32_t TaskRemoveObj::execute(){
	//cerr<<"TaskRemoveObj::execute"<<endl;
	SObj* obj = _processor->getObj(_obj);
	if(!obj)
		return COMMAND_FINAL;
	
	for(map<COMPID::Enum, SComponent*>::iterator it = obj->getComponents().begin(); it != obj->getComponents().end();it++){
		if(obj->isInit() && obj->isPersistent()){
			it->second->dbDelete();
		}
		delete it->second;
	}
	obj->getComponents().clear();
	
	//cerr<<"obj init = "<<obj->isInit()<< " persistent = "<<obj->isPersistent()<<endl;
	
	if(obj->isInit() && obj->isPersistent()){
		obj->DBdelete();
	}
	
	_processor->removeObj(obj);
	return COMMAND_FINAL;
}

TaskRemoveObj::~TaskRemoveObj() {
}

