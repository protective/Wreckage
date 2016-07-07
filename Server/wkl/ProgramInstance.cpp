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

void ProgramInstance::yield(uint32_t refId, Variable* retVar){
	ProgramExecutor* pe = getRunRef(refId);
	if(pe)
		pe->yield(retVar);
}

uint32_t ProgramInstance::getRegister(uint32_t refId, uint32_t refId) {
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

void ProgramInstance::interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& args){
	cerr<<"ProgramExecutor::interrupt"<<endl;
	_registerFlags = _registerFlags | registerFlags::interrupt; 
	
	list<Variable> stack;

	stack.push_back(0xBBBB); //retVal
	for(auto it : args){
		stack.push_back(it);
	}
	uint32_t oldPc = _programCounter;
	stack.push_back(0x00); //pc EOP
	int i = _stackTop;
	uint32_t ret_top = _stackTop;
	for (list<Variable>::iterator stackit = stack.begin(); stackit!= stack.end();stackit++){
		_stackTop = i;
		_stack[i++] = *stackit;
	}	
	_programCounter = _program->getInterruptHandlers()[functionId];
	run(obj, functionId, args);
	_programCounter = oldPc;
	_registerFlags = _registerFlags & (~registerFlags::interrupt);
	_stackTop = ret_top;
	
	for (i = 0; i < args.size(); i++){
		args[i] = _stack[ret_top + i + 1];
	}
	//*argIndex = ret_top + 1;
}

ProgramInstance::~ProgramInstance() {
}

