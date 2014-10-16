/* 
 * File:   TaskCloneObj.cpp
 * Author: karsten
 * 
 * Created on 16. oktober 2014, 20:30
 */

#include "TaskCloneObj.h"
#include "../ModelLayer/SObj.h"
#include "../Processor/Processor.h"

TaskCloneObj::TaskCloneObj() :
Task(0) {
	
}

uint32_t TaskCloneObj::execute(){
	SObj* toClone = _processor->getObj(_id);
	
	if(_processor->getObj(_id)){
		
	}
	
	//_processor->addObj(obj);
}


TaskCloneObj::~TaskCloneObj() {
}

