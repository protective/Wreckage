/* 
 * File:   TaskProcess.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 23:14
 */

#include "TaskProcess.h"
#include "../Processor/Processor.h"
#include "../ModelLayer/SObj.h"
#include "../ModelLayer/SWorld.h"
#include "../ModelLayer/Signals/SignalProcess.h"
#include "../SGlobals.h"

TaskProcess::TaskProcess(SObj* obj, TIME delta):
Task(0){
	_obj = obj;
	_procesDelta = delta;
	_last = world->getTime();
}

uint32_t TaskProcess::execute(){
	cerr<<"TaskProcess::execute()"<<endl;
	TIME  delta = world->getTime() - _last;
	SignalProcess s(SIGNAL::process, delta);
	_obj->signal(SIGNAL::process, &s);
	_last += delta;
	_time = _last + _procesDelta;
	return COMMAND_REPEAT;
}

TaskProcess::~TaskProcess() {
}

