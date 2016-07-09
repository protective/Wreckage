/* 
 * File:   ProgramExecutor.h
 * Author: karsten
 *
 * Created on 11. juli 2015, 20:21
 */

#ifndef PROGRAMEXECUTOR_H
#define	PROGRAMEXECUTOR_H


#include "Program.h"
#include "Compiler/systemCallLib.h"
#include "Utils/Variable.h"
#include "ProgramInstance.h"

using namespace std;

namespace wkl {
	enum registerFlags{
		halt = 0x01,
		interrupt = 0x2,
		yield = 0x04,
		segfault = 0x08,
		terminate = 0x10,
		
	};
class ProgramInstance;
class ProgramExecutor {
public:
	ProgramExecutor(ProgramInstance* instance, uint32_t runRefId);
	void reset();
	uint32_t run(uint32_t obj);
	uint32_t run(uint32_t obj, uint32_t functionId);
	uint32_t run(uint32_t obj, uint32_t functionId, vector<Variable>& args);
	vector<Variable>& getStack(){return _stack;}
	uint32_t getRegister(){return this->_registerFlags;}
	void setFlag(uint32_t flag){this->_registerFlags |= flag;}
	uint32_t segfault(string message);	
	uint32_t segfault();
	//void setCallback(void (*function)(void*), SObj* obj, void* args);
	bool isHalt();
	SObj* getObj(){return this->_instance->getObj();}
	Program* getProgram() {return this->_instance->getProgram();}
	void yield(Variable* retVar);
	uint32_t getInstanceRef() {return this->_instance->getInstanceRef();}
	uint32_t getRunRef() {return this->_runRefId;}
	void setCallback(iterateFunc callback, void* block){_callback = callback; _callbackBlock = block;}
	map<Variable, Variable>& getEnvContext() {return this->_instance->getEnvContext();}

	void dumpStack();
	virtual ~ProgramExecutor();
private:
	uint32_t _runRefId;
	ProgramInstance* _instance;
	uint32_t _registerFlags;
	uint32_t _mipsCredit;	
	uint32_t _programCounter;
	int32_t _stackTop;
	vector<Variable> _stack;
	uint32_t _locRet;
	uint32_t _stackMax;
	iterateFunc _callback;
	void* _callbackBlock;
};
}
#endif	/* PROGRAMEXECUTOR_H */

