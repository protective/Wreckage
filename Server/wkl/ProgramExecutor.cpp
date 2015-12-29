/* 
 * File:   ProgramExecutor.cpp
 * Author: karsten
 * 
 * Created on 11. juli 2015, 20:21
 */

#include <stdint.h>

#include "ProgramExecutor.h"
#include "Compiler/Compiler.h"
#include "../wkl/Compiler/ProgramPrinter.h"

ProgramExecutor::ProgramExecutor(uint32_t runRefId, SObj* obj,  Program* program, map<uint32_t, systemCallFunc> systemCallFuncs , map<uint32_t, Variable> envContext) {
	_runRefId = runRefId;
	_obj = obj;
	_program = program;
	_systemCallFuncs = systemCallFuncs;
	_envContext = envContext;
	_registerFlags = 0;
	_mipsCredit = 0;
	_programCounter = 0;
	_stackTop = 0;
	_locRet = 0;
	//if(_stack)
	//	free(_stack);
	//_stack = (uint32_t*)malloc(sizeof(uint32_t)* 100);
	//memset(_stack,0,sizeof(uint32_t)* 100);
	
	_stack.resize(100);
	_stackMax = 100;
}

void ProgramExecutor::yield(Variable* retVar){
	if (_registerFlags & registerFlags::yield){
		_stack[_locRet] = *retVar;
		_locRet = 0;
		_registerFlags = _registerFlags & (~registerFlags::yield);
	}else
		segfault("yield while flags is not set");

}

uint32_t ProgramExecutor::run(uint32_t obj){
	list<uint32_t> arg;
	return this->run(obj, 0, arg);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId){
	list<uint32_t> arg;
	return this->run(obj, functionId, arg);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId, list<uint32_t> args){
//cerr<<"execure CommandOrderThread"<<endl;
	_mipsCredit = 1000;
	if (functionId > 0) {
		_programCounter = _program->getInterruptHandlers()[functionId];
		int i = 0;
		list<uint32_t> stack;
		stack.push_back(0xBBBB); //retVal
		stack.push_back(0x0); //pc EOP
		for(auto it : args){
			stack.push_back(it);
			
		}

#ifdef WKL_DEBUG
		cerr<<"BEGIN External function call"<<endl;
#endif
		for (list<uint32_t>::iterator stackit = stack.begin(); stackit!= stack.end();stackit++){
			_stackTop = i;
			_stack[i++] = *stackit;
#ifdef WKL_DEBUG
			cerr<<"args "<<*stackit<<endl;
#endif
		}
	}else if(_registerFlags & registerFlags::interrupt){
		_registerFlags = _registerFlags & (~registerFlags::interrupt); 
	}
	
	while(_mipsCredit && _program && !(_registerFlags & registerFlags::yield)){
		
		_mipsCredit--;
		//if((_registerFlags & registerFlags::Yeld) > 0){
		//	_registerFlags &= ~registerFlags::Yeld;
			//cerr<<"yeld"<<endl;
		//	return 1;
		//}
		if(_programCounter > _program->program().size())
			return segfault();
		uint32_t ins = _program->program()[_programCounter];
		
		//cerr<<"exe line "<<std::hex<<_programCounter<<std::dec<<" stack top "<<_stackTop<<endl;
#ifdef WKL_DEBUG
		dumpStack();
#endif
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
				if(_stackTop < 0)
					return segfault("inst::popPC stack empty");
				if(_stack[_stackTop].t)
					return segfault("inst::popPC Not a valid PC");
				if(_stack[_stackTop].v < 0)
					return segfault("inst::popPC invalid PC");
				_programCounter = _stack[_stackTop--];
				break;
			}
			case inst::pushUIndx:{
				if(_programCounter + 1 >= _program->program().size())
					return segfault();
				uint32_t src = _stackTop - _program->program()[_programCounter + 1];
				if(_stackTop++ >= _stackMax)
					return segfault();
				if(_stack[src].t == NULL)
					return segfault("variable not iterable");
				
				_stack[_stackTop] = _stack[src].t->_vector.size();
				_programCounter += 2;
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
			case inst::cjmp2NeqA_1:{
				if(_stackTop < 1)
					return segfault();
				if (_stack[_stackTop] != _stack[_stackTop-1]){
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
				
				if(_systemCallFuncs.find(ARG(ins)) != _systemCallFuncs.end()){
					_stack[_stackTop - stackArg + 1] =
							_systemCallFuncs[ARG(ins)](_obj, this, (void*)(&_stack[_stackTop - stackArg +1]));
					if(_registerFlags & registerFlags::yield){
						_locRet = _stackTop - stackArg + 1;
					}		
				}else{
					return segfault("syscall not implemented");
				}
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
			case inst::minusS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] - _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::eqS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] == _stack[_stackTop]) ? 1 : 0;
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::neqS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] != _stack[_stackTop]) ? 1 : 0;
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
			case inst::cpCO_DS2:{
				uint32_t dest = _stackTop - _program->program()[_programCounter+1];
				uint32_t src = _program->program()[_programCounter+2];
				if (systemConst::systemConstValues.find(src) == systemConst::systemConstValues.end())
					return segfault();
				for(int i = 0 ; i< ARG(ins); i++){
					if(dest + i < _stackMax)
						_stack[dest + i] = systemConst::systemConstValues[src];
					else{
						return segfault();
					}
				}
				_programCounter += 3;
				break;
			}
			case inst::mvMapAL:{
				uint32_t size = ARG(ins);
				uint32_t dest = _stackTop - (size*2);
				if (_stack.size() <= dest)
					return segfault();
				if (_stackTop-(size*2)-1 < 0)
					return segfault();
				for(int i = 0 ; i< ARG(ins); i++){
					int32_t test = _stackTop-(i*2)-1;
					if (_stack[dest].t == NULL)
						_stack[dest].t = new VObject();
					_stack[dest].t->_vector[
							_stack[test]] =
							_stack[_stackTop-(i*2)]; 
				}
				_programCounter += 1;
				break;
			}
			case inst::cpRIS2_T:{
				uint32_t src = _stackTop - _program->program()[_programCounter+1];
				if(ARG(ins) > _stackTop || _stackTop - ARG(ins) > _stackMax)
					return segfault();
				uint32_t index = _stack[_stackTop- ARG(ins)];
				if(_stack[src].t == NULL)
					return segfault("not iteratable");
				if(_stack[src].t->_vector.size() < index)
					return segfault("index out of range");
				_stack[_stackTop] = _stack[src].t->_vector[index];
				_programCounter += 2;
				break;
			}			
			case inst::cpEN_DS2:{
				uint32_t dest = _stackTop - _program->program()[_programCounter+1];
				uint32_t src = _program->program()[_programCounter+2];
				for(int i = 0 ; i< ARG(ins); i++){
					if(dest + i < _stackMax){
						map<uint32_t, Variable>::iterator it = _envContext.find(src);
						if (it == _envContext.end()){
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
			case inst::cpT_EN:{
				if(_programCounter + 1 >= _program->program().size())
					return segfault();
				uint32_t dest = _program->program()[_programCounter+1];
				_envContext[dest] = _stack[_stackTop];
				_programCounter += 2;
				break;
			}			
			case inst::NOP:{
				_programCounter += 1;
				break;
			}
			case inst::FUN:{
				_programCounter += 1;
				break;
			}
			case inst::EOP:{
#ifdef WKL_DEBUG
				cerr<<"EOP exit OK"<<endl;
#endif				
				_registerFlags |= registerFlags::halt;
				//TODO
				//free(_stack);
				return _registerFlags;
				break;
			}
			default:{
				cerr<<"ERROR UNKNOW INSTRUCTION opcode "<<OPCODE(ins)<<endl;
				//TODO

				_registerFlags |= registerFlags::halt;
				//free(_stack);
				return _registerFlags;
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

	return this->segfault();
	
}

uint32_t ProgramExecutor::segfault(){
	cerr<<"SEGFAULT PC ="<<wkl::toHex(_programCounter,0)<<" stack top ="<<_stackTop<<endl;
	cerr<<"stack"<<endl;
	dumpStack();
	_programCounter = 0;
	_mipsCredit = 0;
	
	_registerFlags |= registerFlags::segfault;
	_registerFlags |= registerFlags::halt;
	//TODO
	//free(_stack);
	return _registerFlags;
}

void ProgramExecutor::dumpStack(){
	for(int i = 0; i <= _stackTop ; i++){
		//TODO
		if(_stack[i].t == NULL)
			cerr<<_stack[i].v<<" ";
		else{
			cerr<<"[";
			bool first = true;
			for( map<Variable,Variable>::iterator it = _stack[i].t->_vector.begin(); it != _stack[i].t->_vector.end(); it++){
				if (!first)
					cerr<<", ";
				cerr<<(it->first).v<<":"<<(it->second.v);
				first = false;
			}
			cerr<<"] ";
		}
			
	}
	cerr<<endl<<endl;
}

ProgramExecutor::~ProgramExecutor() {
}

