/* 
 * File:   TaskAcceptInput.cpp
 * Author: karsten
 * 
 * Created on 24. oktober 2014, 22:00
 */

#include "TaskAcceptInput.h"

#include "../ModelLayer/SObj.h"

#include "../Processor/Processor.h"

TaskAcceptInput::TaskAcceptInput(OBJID id, SerialInputPayload* data) :
Task(0)	{
	_id = id;
	_data = data;
}


uint32_t TaskAcceptInput::execute() {
	if(!_processor->getObj(_id))
		return COMMAND_FINAL;
	SObj* obj = _processor->getObj(_id);
	
	obj->input(_data);
	
	
	free(_data);
	_data = NULL;
	return COMMAND_FINAL;
}


TaskAcceptInput::~TaskAcceptInput() {
	if(_data)
		free(_data);
}

