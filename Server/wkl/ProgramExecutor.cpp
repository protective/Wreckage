/* 
 * File:   ProgramExecutor.cpp
 * Author: karsten
 * 
 * Created on 11. juli 2015, 20:21
 */

#include <stdint.h>

#include "ProgramExecutor.h"
#include "ProgramInstance.h"
#include "Compiler/Compiler.h"
#include "../ModelLayer/Components/CompTargeted/CompTargeted.h"

#include "../wkl/Compiler/ProgramPrinter.h"

ProgramExecutor::ProgramExecutor(ProgramInstance* instance, uint32_t runRefId) {
	_instance = instance;
	_runRefId = runRefId;
	_callback = NULL;
	_callbackBlock= NULL;
	this->reset();
}

void ProgramExecutor::reset(){
	_locRet = 0;
	_mipsCredit = 1000;
	_programCounter = 0;
	_registerFlags = 0;

	_stackTop = 0;
	_stack.resize(100);
	_stackMax = 100;
}


bool ProgramExecutor::isHalt() {
	return _registerFlags & registerFlags::halt;
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
	vector<Variable> arg;
	return this->run(obj, 0, arg);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId){
	vector<Variable> arg;
	return this->run(obj, functionId, arg);
}

uint32_t ProgramExecutor::run(uint32_t obj, uint32_t functionId, vector<Variable>& args){
//cerr<<"execure CommandOrderThread"<<endl;
	uint32_t arg_ret_pos = 0;
	_mipsCredit = 1000;
	Program* program = _instance->getProgram();
	if (functionId > 0) {
		_programCounter = program->getInterruptHandlers()[functionId];
		int i = 0;
		list<uint32_t> stack;
		//arg_ret_pos = stack.size();
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

#ifdef WKL_DEBUG

	cerr<<"BEGIN wkl function call yield ="<<(_registerFlags & registerFlags::yield ? "true" : "false")<<endl;
#endif
	if (_registerFlags & registerFlags::yield){
		cerr<<"hest"<<endl;
	}
	while(_mipsCredit
			&& program
			&& (!(_registerFlags & registerFlags::yield))){
		cerr<<"ret0 "<<arg_ret_pos<<endl;
		_mipsCredit--;

		if(_programCounter > program->program().size())
			return segfault();
		uint32_t ins = program->program()[_programCounter];
		
		cerr<<"exe line "<<std::hex<<_programCounter<<std::dec<<" stack top "<<_stackTop<<endl;

		dumpStack();

		switch(OPCODE(ins)){
			case inst::pushN_1:{
				for(int i = 0 ; i < ARG(ins);i++){
					if(_stackTop++ >= _stackMax)
						return segfault();
					_stack[_stackTop] = program->program()[_programCounter+1];
				}
				_programCounter += 2;
				break;
			}
			case inst::jmpA_1:{
				if(program->program()[_programCounter+1] >= program->program().size())
					return segfault();
				_programCounter = program->program()[_programCounter+1];
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
				_stack[_stackTop] = program->program()[_programCounter+1]; 
	
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
				if(_programCounter + 1 >= program->program().size())
					return segfault();
				uint32_t src = _stackTop - program->program()[_programCounter + 1];
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
					if(program->program()[_programCounter+1] >= program->program().size())
						return segfault();
					_programCounter =  program->program()[_programCounter+1];
				}else{
					_programCounter += 2;
				}
				break;
			}
			case inst::cjmp2NeqA_1:{
				if(_stackTop < 1)
					return segfault();
				if (_stack[_stackTop] != _stack[_stackTop-1]){
					if(program->program()[_programCounter+1] >= program->program().size())
						return segfault();
					_programCounter =  program->program()[_programCounter+1];
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
				uint32_t stackArg = program->program()[_programCounter+1];
				cerr<<"ret1 "<<arg_ret_pos<<endl;
				if(_instance->getSystemCallFuncs().find(ARG(ins)) != _instance->getSystemCallFuncs().end()){
					_stack[_stackTop - stackArg + 1] =
							_instance->getSystemCallFuncs()[ARG(ins)](this->getObj(), this, (void*)(&_stack[_stackTop - stackArg + 1]));
					if(_registerFlags & registerFlags::yield){
						_locRet = _stackTop - stackArg + 1;
					}		
				}else{
					return segfault("syscall not implemented");
				}
				cerr<<"ret2 "<<arg_ret_pos<<endl;
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
					src = program->program()[_programCounter + 1];
				}else if (sup & 0x01 ) {
					if (_stackTop < program->program()[_programCounter+1]) {
						stringstream s; s<<"rel src negative src="<<src;
						return segfault(s.str());
					}
					src = _stackTop - program->program()[_programCounter+1];
				} else {
					src = program->program()[_programCounter + 1];
				}
				if (sup & 0x04) {
					dest = program->program()[_programCounter + 2];
				} else if (sup & 0x02) {
					if (_stackTop < program->program()[_programCounter + 2]) {
						stringstream s; s<<"rel dest negative dest="<<dest;
						return segfault(s.str());
					}
					dest = _stackTop - program->program()[_programCounter + 2];
				} else {
					dest = program->program()[_programCounter + 2];
				}
				Variable v;
				if (sup & 0x10) { //src is env
					map<Variable, Variable>::iterator it = _instance->getEnvContext().find(src);
					if (it ==  _instance->getEnvContext().end()){
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
					 _instance->getEnvContext()[dest] = v;
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
					src = _stackTop - program->program()[_programCounter+1];
				else
					src = program->program()[_programCounter+1];
					
				if (sup & 0x02)
					dest = _stackTop - program->program()[_programCounter+3];
				else
					dest = program->program()[_programCounter+3];

				Variable v;
				if (sup & 0x10) { //src is env
					map<Variable, Variable>::iterator it =  _instance->getEnvContext().find(src);
					if (it ==  _instance->getEnvContext().end()){
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
					map<Variable, Variable>::iterator it_dest =  _instance->getEnvContext().find(dest);
					if (it_dest ==  _instance->getEnvContext().end()){
						stringstream s; s<<"dest env variable id="<<dest<<" not found";
						return segfault(s.str());
					}
					 _instance->getEnvContext()[dest] = v;
				}else if(dest < _stackMax) {
					_stack[dest] = v;
				}else{
					return segfault();
				}
					
				_programCounter += 4;
				break;
			}
			case inst::cpCO_DS2:{
				uint32_t src = program->program()[_programCounter+1];
				uint32_t dest = _stackTop - program->program()[_programCounter+2];
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
				for (int i = 0; i < args.size(); i++){
					args[i] = _stack[arg_ret_pos + i + 1];
				}
				if (_callback){
					
					BuffIterator* _buffiterator = (BuffIterator*)this->_callbackBlock;
					for(uint32_t i = 0; i < _buffiterator->callback_args.size(); i++){
						_buffiterator->callback_args[i] = _stack[arg_ret_pos + 1 + i];
					}
					//, (void*)(&_stack[arg_ret_pos + 1])
					_callback(this->getObj(), _callbackBlock);
					
				}
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

