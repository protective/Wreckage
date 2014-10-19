/* 
 * File:   TaskAddComponent.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 20:48
 */

#include "TaskAddComponent.h"
#include "../Processor/Processor.h"
TaskAddComponent::TaskAddComponent(SObj* id, SComponent* component) :
Task(0) {
	_id = id;
	_component = component;
}

uint32_t TaskAddComponent::execute(){
	_id->addComponent(_component);
	return COMMAND_FINAL;
}

TaskAddComponent::~TaskAddComponent() {
}

