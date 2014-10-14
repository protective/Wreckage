/* 
 * File:   TaskCreateObj.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 20:28
 */

#include "TaskCreateObj.h"
#include "../ModelLayer/SObj.h"
#include "../Processor/Processor.h"

TaskCreateObj::TaskCreateObj() :
Task(0) {
	
	
}

uint32_t TaskCreateObj::execute(){

	SObj* obj = new SObj(_processor->getFreeID());
	_processor->addObj(obj);
}

TaskCreateObj::~TaskCreateObj() {
}

