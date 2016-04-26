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

using namespace std;
namespace wkl {
	enum registerFlags{
		halt = 0x01,
		interrupt = 0x2,
		yield = 0x04,
		segfault = 0x08
		
	};
	
class ProgramExecutor {
public:
	ProgramExecutor(uint32_t runRefId, SObj* comp, Program* program, map<uint32_t, systemCallFunc> systemCallFuncs, map<Variable, Variable> envContext);

	
	uint32_t run(uint32_t obj);
	uint32_t run(uint32_t obj, uint32_t functionId);
	uint32_t run(uint32_t obj, uint32_t functionId, vector<Variable> args);
	void interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& _args);
	vector<Variable>& getStack(){return _stack;}
	void yield(Variable* retVar);
	
	uint32_t getRunRef() {return this->_runRefId;}
	Program* getProgram() {return this->_program;}
	uint32_t getRegister(){return this->_registerFlags;}
	void setFlag(uint32_t flag){this->_registerFlags |= flag;}
	map<Variable, Variable>& getEnvContext() {return this->_envContext;}
	uint32_t segfault(string message);	
	uint32_t segfault();
	void dumpStack();
	virtual ~ProgramExecutor();
private:
	uint32_t _runRefId;
	Program* _program;
	SObj* _obj;
	map<uint32_t, systemCallFunc> _systemCallFuncs;
	uint32_t _registerFlags;
	uint32_t _mipsCredit;	
	uint32_t _programCounter;
	int32_t _stackTop;
	vector<Variable> _stack;
	uint32_t _locRet;
	map<Variable, Variable> _envContext;
	uint32_t _stackMax;
};
}
#endif	/* PROGRAMEXECUTOR_H */

