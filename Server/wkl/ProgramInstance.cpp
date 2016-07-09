/* 
 * File:   ProgramInstance.cpp
 * Author: karsten
 * 
 * Created on 21. maj 2016, 23:24
 */

#include "ProgramInstance.h"
#include "ProgramExecutor.h"

ProgramInstance::ProgramInstance(uint32_t instanceRefId, SObj* obj,  Program* program, map<uint32_t, systemCallFunc> systemCallFuncs , map<Variable, Variable> envContext) {
	_instanceRefId = instanceRefId;
	_obj = obj;
	_program = program;
	_systemCallFuncs = systemCallFuncs;
	_envContext = envContext;
}

bool ProgramInstance::isTerminating(){
	for (auto it: _instances) {
		if (!it.second->isHalt())
			return false;
	}
	return true;

}

void ProgramInstance::yield(uint32_t refId, Variable* retVar){
	ProgramExecutor* pe = getRunRef(refId);
	if(pe)
		pe->yield(retVar);
}

ProgramExecutor* ProgramInstance::getRunRef(uint32_t refId)
{
	return _instances.find(refId) != _instances.end() ? _instances[refId]: NULL;
}

uint32_t ProgramInstance::getRegister(uint32_t refId) {
	ProgramExecutor* pe = getRunRef(refId);
	if(pe)
		return pe->getRegister();
}

uint32_t ProgramInstance::run(uint32_t refId, uint32_t obj) {
	ProgramExecutor* pe = getRunRef(refId);
	if(pe){	
		vector<Variable> arg;
		return pe->run(obj, 0, arg);
	}else
		return 0;
}

uint32_t ProgramInstance::run(uint32_t refId, uint32_t obj, uint32_t functionId){
	ProgramExecutor* pe = getRunRef(refId);
	if(pe){	
		vector<Variable> arg;
		return pe->run(obj, functionId, arg);
	}else
		return 0;
}

uint32_t ProgramInstance::run(uint32_t refId, uint32_t obj, uint32_t functionId, vector<Variable> args){
	ProgramExecutor* pe = getRunRef(refId);
	if(pe){
		return pe->run(obj, functionId, args);
	}else
		return 0;
}

uint32_t ProgramInstance::interrupt(uint32_t obj, uint32_t functionId){
	vector<Variable> nonargs;
	return this->interrupt(obj, functionId, nonargs, NULL, NULL);			
}
uint32_t ProgramInstance::interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& args){
	
	return this->interrupt(obj, functionId, args, NULL, NULL);	
}

uint32_t ProgramInstance::interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& args, iterateFunc callback, void* callBackBlock){
	cerr<<"ProgramExecutor::interrupt"<<endl;
	//_registerFlags = _registerFlags | registerFlags::interrupt;
	uint32_t runRef;
	uint32_t highest = 0;
	bool found = false;
	for(auto it : this->_instances){
		if (it.second->isHalt()){
			it.second->reset();
			runRef = it.first;
			found = true;
			break;
		}else{
			highest = max(highest, it.first);
		}
	}
	if(!found){
		highest++;
		cerr<<"New program executor "<<highest<<endl;
		this->_instances[highest] = new ProgramExecutor(this, highest);
		runRef = highest;
	}
	
	cerr<<"Program executor run"<<endl;
	this->_instances[runRef]->run(obj, functionId, args);
	
	cerr<<"Program executor run done"<<endl;
	if (this->getRegister(runRef) & wkl::registerFlags::yield)
		this->_instances[runRef]->setCallback(callback, callBackBlock);

	return highest;
}

ProgramInstance::~ProgramInstance() {
}

