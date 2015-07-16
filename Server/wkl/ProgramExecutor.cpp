/* 
 * File:   ProgramExecutor.cpp
 * Author: karsten
 * 
 * Created on 11. juli 2015, 20:21
 */

#include <stdint.h>

#include "ProgramExecutor.h"
#include "Compiler/Compiler.h"

ProgramExecutor::ProgramExecutor(string name, SComponent* comp,  Program* program, map<uint32_t, systemCallFunc> systemCallFuncs) {
	_name = name;
	_comp = comp;
	_program = program;
	_systemCallFuncs = systemCallFuncs;
	
	_registerFlags = 0;
	_mipsCredit = 0;
	_programCounter = 0;
	_stackTop = 0;
	//if(_stack)
	//	free(_stack);
	//_stack = (uint32_t*)malloc(sizeof(uint32_t)* 100);
	//memset(_stack,0,sizeof(uint32_t)* 100);
	
	_stack.resize(100);
	_stackMax = 100;
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId, map<uint32_t, Variable> envContext){
	list<uint32_t> arg;
	this->run(obj, functionId, arg, envContext);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId, list<uint32_t> args, map<uint32_t, Variable> envContext){
//cerr<<"execure CommandOrderThread"<<endl;
	_mipsCredit = 1000;
	
	_programCounter = _program->getInterruptHandlers()[functionId];
	int i = 0;
	list<uint32_t> stack;
	stack.push_back(0x0); //pc EOP
	stack.push_back(0xBBBB); //retVal
	for(auto it : args)
		stack.push_back(it);
	
	for (list<uint32_t>::iterator stackit = stack.begin(); stackit!= stack.end();stackit++){
		_stack[i++] = *stackit;
		_stackTop = i;
	}
	
	
	while(_mipsCredit && _program){
		
		_mipsCredit--;
		//if((_registerFlags & registerFlags::Yeld) > 0){
		//	_registerFlags &= ~registerFlags::Yeld;
			//cerr<<"yeld"<<endl;
		//	return 1;
		//}
		if(_programCounter > _program->program().size())
			return segfault();
		uint32_t ins = _program->program()[_programCounter];
		
		cerr<<"exe line "<<std::hex<<_programCounter<<std::dec<<" stack top "<<_stackTop<<endl;
		dumpStack();
		switch(OPCODE(ins)){
			case inst::pushN_1:{
				for(int i = 0 ; i < ARG(ins);i++){
					if(_stackTop++ >= _stackMax)
						return segfault();
					_stack[_stackTop] = _program->program()[_programCounter+1];
				}
				_programCounter += 2;
				break;
			}
			case inst::jmpA_1:{
				if(_program->program()[_programCounter+1] >= _program->program().size())
					return segfault();
				_programCounter = _program->program()[_programCounter+1];
				break;
			}
			case inst::pushPC:{
				if(_stackTop++ >= _stackMax)
					return segfault();			
				_stack[_stackTop] = _programCounter + 3; //skip next jump
	
				_programCounter += 1;
				break;
			}
			case inst::pushRPC:{
				if(_stackTop++ >= _stackMax)
					return segfault();			
				_stack[_stackTop] = _program->program()[_programCounter+1]; 
	
				_programCounter += 2;
				break;
			}
			case inst::popPC:{
				if(_stackTop == 0)
					return segfault();
				_programCounter = _stack[_stackTop--];
				break;
			}
			case inst::cjmpA_1:{
				if (_stack[_stackTop]){
					if(_program->program()[_programCounter+1] >= _program->program().size())
						return segfault();
					_programCounter =  _program->program()[_programCounter+1];
				}else{
					_programCounter += 2;
				}
				break;
			}
			case inst::popN:{
				if(_stackTop < ARG(ins))
					return segfault();
				_stackTop-= ARG(ins);
				_programCounter += 1;
				break;
			}
			case inst::pushN:{
				_stackTop += ARG(ins);
				if(_stackTop >= _stackMax)
					return segfault();
				_programCounter += 1;
				break;
			}
			case inst::sysCall:{
				uint32_t stackArg = _program->program()[_programCounter+1];
				_stack[_stackTop - stackArg + 1] =
						_systemCallFuncs[ARG(ins)](_comp, _program, envContext, (void*)(&_stack[_stackTop - stackArg +1]));
				_programCounter += 2;
				break;
			}
			
			case inst::addS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] + _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::cpI_DS2:{
				uint32_t dest = _stackTop - _program->program()[_programCounter+1];
				uint32_t src = _stackTop - _program->program()[_programCounter+2];
				
				if(dest  < _stackMax && src  < _stackMax && _stack[src ].t)
					if(_stack[src].t->_vector.size() > ARG(ins))
						_stack[dest] = _stack[src].t->_vector[ARG(ins)];
					else
						segfault("Tuple index out of range");
				else{
					return segfault();
				}
				
				_programCounter += 3;
				break;
			}
			case inst::cpN_DS2:{
				uint32_t dest = _stackTop - _program->program()[_programCounter+1];
				uint32_t src = _stackTop - _program->program()[_programCounter+2];
				for(int i = 0 ; i< ARG(ins); i++){
					if(dest + i < _stackMax && src + i < _stackMax)
						_stack[dest + i] = _stack[src + i];
					else{
						return segfault();
					}
				}
				_programCounter += 3;
				break;
			}
			case inst::cpN_DRS2:{
				uint32_t dest =  _program->program()[_programCounter+1];
				uint32_t src = _stackTop - _program->program()[_programCounter+2];
				for(int i = 0 ; i< ARG(ins); i++){
					if(dest + i < _stackMax && src + i < _stackMax)
						_stack[dest + i] = _stack[src + i];
					else{
						return segfault();
					}
				}
				_programCounter += 3;
				break;
			}
			case inst::cpN_RDS2:{
				uint32_t dest = _stackTop - _program->program()[_programCounter+1];
				uint32_t src = _program->program()[_programCounter+2];
				for(int i = 0 ; i< ARG(ins); i++){
					if(dest + i < _stackMax && src + i < _stackMax)
						_stack[dest + i] = _stack[src + i];
					else{
						return segfault();
					}
				}
				_programCounter += 3;
				break;
			}
			
			
			case inst::cpEN_DS2:{
				uint32_t dest = _stackTop - _program->program()[_programCounter+1];
				uint32_t src = _program->program()[_programCounter+2];
				for(int i = 0 ; i< ARG(ins); i++){
					if(dest + i < _stackMax){
						map<uint32_t, Variable>::iterator it = envContext.find(src);
						if (it == envContext.end()){
							stringstream s;
							s<<"env variable id="<<src<<" not found";
							return segfault(s.str());
						}
		
						_stack[dest + i] = it->second;
					}else{
						return segfault();
					}
				}
				_programCounter += 3;
				break;
			}
			
			case inst::NOP:{
				_programCounter += 1;
				break;
			}
			case inst::EOP:{
				cerr<<"EOP exit OK"<<endl;
				//TODO
				//free(_stack);
				return 0;
				break;
			}
			default:{
				cerr<<"ERROR UNKNOW INSTRUCTION opcode "<<OPCODE(ins)<<endl;
				//TODO
				//free(_stack);
				return 0;
			}
		}
	}
}



void ProgramExecutor::interrupt(uint32_t programId, uint32_t handlerId, uint32_t* payload, uint32_t payloadLen){
	if(!_program)
		return;
	if(_program->getInterruptHandlers().find(handlerId) == _program->getInterruptHandlers().end()){
		cerr<<"SProgrammable::interrupt ERROR handler not found "<<endl;
		return;
	}
	
	
	//cerr<<"INTERRUPT "<<endl;
	_stackTop +=1;
	_stack[_stackTop] = _programCounter;
	
	//TODO
	//memcpy(_stack + _stackTop+1, payload, payloadLen);
	_stackTop+= payloadLen / sizeof(uint32_t);


	_programCounter = _program->getInterruptHandlers()[handlerId];
}

uint32_t ProgramExecutor::segfault(string message){
	cerr<<"SEGFAULT Message = "<<message<<endl;
	this->segfault();
	
}

uint32_t ProgramExecutor::segfault(){
	cerr<<"SEGFAULT PC ="<<_programCounter<<" stack top ="<<_stackTop<<endl;
	cerr<<"stack"<<endl;
	dumpStack();
	_programCounter = 0;
	_mipsCredit = 0;
	//TODO
	//free(_stack);
	return 0;
}

void ProgramExecutor::dumpStack(){
	for(int i = 0; i <= _stackTop ; i++){
		//TODO
		if(_stack[i].t == NULL)
			cerr<<_stack[i].v<<" ";
		else{
			cerr<<"[";
			bool first = true;
			for( vector<Variable>::iterator it = _stack[i].t->_vector.begin(); it != _stack[i].t->_vector.end(); it++){
				if (!first)
					cerr<<", ";
				cerr<<(*it).v;
				first = false;
			}
			cerr<<"] ";
		}
			
	}
	cerr<<endl<<endl;
}

ProgramExecutor::~ProgramExecutor() {
}

