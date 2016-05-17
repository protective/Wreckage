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

ProgramExecutor::ProgramExecutor(uint32_t runRefId, SObj* obj,  Program* program, map<uint32_t, systemCallFunc> systemCallFuncs , map<Variable, Variable> envContext) {
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

void ProgramExecutor::interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& args){
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


uint32_t ProgramExecutor::run(uint32_t obj){
	vector<Variable> arg;
	return this->run(obj, 0, arg);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId){
	vector<Variable> arg;
	return this->run(obj, functionId, arg);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId, vector<Variable> args){
//cerr<<"execure CommandOrderThread"<<endl;
	_mipsCredit = 1000;
	if (functionId > 0 && !(_registerFlags & registerFlags::interrupt)) {
		_programCounter = _program->getInterruptHandlers()[functionId];
		int i = 0;
		list<uint32_t> stack;
		
		stack.push_back(0xBBBB); //retVal
		for(auto it : args){
			stack.push_back(it);
		}
		stack.push_back(0x0); //pc EOP

		for (list<uint32_t>::iterator stackit = stack.begin(); stackit!= stack.end();stackit++){
			_stackTop = i;
			_stack[i++] = *stackit;
#ifdef WKL_DEBUG
			cerr<<"args "<<*stackit<<endl;
#endif
		}
	}
	
		if (_registerFlags & registerFlags::interrupt &&
			_registerFlags & registerFlags::yield)
			cerr<<"ERROR wkl function call interrupt && yield"<<endl;

#ifdef WKL_DEBUG
	if (_registerFlags & registerFlags::interrupt)
		cerr<<"BEGIN wkl function call"<<endl;
	else if (_registerFlags & registerFlags::yield)
		cerr<<"BEGIN wkl function call"<<endl;
	else
		cerr<<"BEGIN wkl function call"<<endl;
#endif
	
	while(_mipsCredit
			&& _program
			&& (!(_registerFlags & registerFlags::yield) || (_registerFlags & registerFlags::interrupt))){
		
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
				if(_stackTop < 0)
					return segfault("inst::popPC stack empty");
				if(_stack[_stackTop].t)
					return segfault("inst::popPC Not a valid PC");
				if(_stack[_stackTop].v < 0)
					return segfault("inst::popPC invalid PC");
				_programCounter = _stack[_stackTop--].v;
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
			case inst::multiS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] * _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::deviS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] / _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::moduloS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] % _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::bitandS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] & _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::bitorS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = _stack[_stackTop-1] | _stack[_stackTop];
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::andS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] && _stack[_stackTop]) ? 1 : 0;
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::orS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] || _stack[_stackTop]) ? 1 : 0;
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::leeqS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] <= _stack[_stackTop]) ? 1 : 0;
				_stackTop--;
				_programCounter += 1;
				break;
			}			
			case inst::leS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] < _stack[_stackTop]) ? 1 : 0;
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::gteqS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] >= _stack[_stackTop]) ? 1 : 0;
				_stackTop--;
				_programCounter += 1;
				break;
			}
			case inst::gtS01dS1:{
				if(_stackTop == 0)
					return segfault();
				_stack[_stackTop-1] = (_stack[_stackTop-1] > _stack[_stackTop]) ? 1 : 0;
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
			case inst::cpN_ADAS2:
			case inst::cpN_ADRS2:
			case inst::cpN_RDAS2:
			case inst::cpN_RDRS2:		
			case inst::cpN_EAD2:
			case inst::cpN_ERD2:
			case inst::cpN_AED2:
			case inst::cpN_RED2:
			{
				uint32_t src , dest;
				uint32_t sup = SOPCODE(ins);
				
				if (sup & 0x10 ){
					src = _program->program()[_programCounter + 1];
				}else if (sup & 0x01 ) {
					if (_stackTop < _program->program()[_programCounter+1]) {
						stringstream s; s<<"rel src negative src="<<src;
						return segfault(s.str());
					}
					src = _stackTop - _program->program()[_programCounter+1];
				} else {
					src = _program->program()[_programCounter + 1];
				}
				if (sup & 0x04) {
					dest = _program->program()[_programCounter + 2];
				} else if (sup & 0x02) {
					if (_stackTop < _program->program()[_programCounter + 2]) {
						stringstream s; s<<"rel dest negative dest="<<dest;
						return segfault(s.str());
					}
					dest = _stackTop - _program->program()[_programCounter + 2];
				} else {
					dest = _program->program()[_programCounter + 2];
				}
				Variable v;
				if (sup & 0x10) { //src is env
					map<Variable, Variable>::iterator it = _envContext.find(src);
					if (it == _envContext.end()){
						stringstream s; s<<"src env variable id="<<src<<" not found";
						return segfault(s.str());
					}
					v = it->second;
				}else if(src < _stackMax){
					v = _stack[src];
				}else{
					return segfault();
				}
				
				if (sup & 0x04){ //dest is env
					_envContext[dest] = v;
				}else if(dest < _stackMax) {
					_stack[dest] = v;
				}else{
					return segfault();
				}

				_programCounter += 3;
				break;
			}
			case inst::cp_ASIAD2:
			case inst::cp_ASIRD2:
			case inst::cp_RSIAD2:
			case inst::cp_RSIRD2:		
			case inst::cp_ASsvIAD2:
			case inst::cp_ASsvIRD2:
			case inst::cp_RSsvIAD2:
			case inst::cp_RSsvIRD2:{
				
				uint32_t src, index , dest;
				uint32_t sup = SOPCODE(ins);
				if (sup & 0x01)
					src = _stackTop - _program->program()[_programCounter+1];
				else
					src = _program->program()[_programCounter+1];
					
				if (sup & 0x02)
					dest = _stackTop - _program->program()[_programCounter+3];
				else
					dest = _program->program()[_programCounter+3];
					

				Variable v;
				if (sup & 0x10) { //src is env
					map<Variable, Variable>::iterator it = _envContext.find(src);
					if (it == _envContext.end()){
						stringstream s; s<<"src env variable id="<<src<<" not found";
						return segfault(s.str());
					}
					v = it->second;
				}else if(src < _stackMax){
					v = _stack[src];
				}else{
					return segfault();
				}					
					
				if (sup & 0x20){ //dest is env
					map<Variable, Variable>::iterator it_dest = _envContext.find(dest);
					if (it_dest == _envContext.end()){
						stringstream s; s<<"dest env variable id="<<dest<<" not found";
						return segfault(s.str());
					}
					_envContext[dest] = v;
				}else if(dest < _stackMax) {
					_stack[dest] = v;
				}else{
					return segfault();
				}
					
				_programCounter += 4;
				break;
			}
			case inst::cpCO_DS2:{
				uint32_t src = _program->program()[_programCounter+1];
				uint32_t dest = _stackTop - _program->program()[_programCounter+2];
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

