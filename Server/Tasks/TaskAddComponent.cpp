/* 
 * File:   TaskAddComponent.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 20:48
 */

#include "TaskAddComponent.h"

#include "../ModelLayer/Signals/SignalGainComp.h"

#include "../Processor/Processor.h"
TaskAddComponent::TaskAddComponent(SObj* id, SComponent* component) :
Task(0) {
	_id = id;
	_component = component;
}

uint32_t TaskAddComponent::execute(){
	_id->addComponent(_component);
	SignalGainComp s(_component);
	_id->signal(SIGNAL::gainComp, &s);
	return COMMAND_FINAL;
}

TaskAddComponent::~TaskAddComponent() {
}

