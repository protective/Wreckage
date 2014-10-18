/* 
 * File:   TaskAddComponent.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 20:48
 */

#include "TaskAddComponent.h"
#include "../Processor/Processor.h"
TaskAddComponent::TaskAddComponent() :
Task(0) {
}

uint32_t TaskAddComponent::execute(){
	_id->addComponent(_component);
	return COMMAND_FINAL;
}

TaskAddComponent::~TaskAddComponent() {
}

