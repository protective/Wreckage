/* 
 * File:   TaskAcceptInput.cpp
 * Author: karsten
 * 
 * Created on 24. oktober 2014, 22:00
 */

#include "TaskAcceptInput.h"

#include "../ModelLayer/SObj.h"

#include "../Processor/Processor.h"

TaskAcceptInput::TaskAcceptInput(OBJID obj, inputOP op, inputLen len, uint32_t* data) :
Task(0)	{
	
	if(len > sizeof(uint32_t) &&len < 1000){
		data = (uint32_t*)malloc(len);
		memcpy(_data, data, len);	
	}
	else{
		data = NULL;
	}
}


uint32_t TaskAcceptInput::execute() {
	if(!_processor->getObj(_id))
		return COMMAND_FINAL;
	
	SObj* obj = _processor->getObj(_id);
	
	obj->input(_op, _len, _data);
	return COMMAND_FINAL;
}


TaskAcceptInput::~TaskAcceptInput() {
	if(_data)
		free(_data);
}

