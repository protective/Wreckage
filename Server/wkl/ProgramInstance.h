/* 
 * File:   ProgramInstance.h
 * Author: karsten
 *
 * Created on 21. maj 2016, 23:24
 */

#ifndef PROGRAMINSTANCE_H
#define	PROGRAMINSTANCE_H

#include "Program.h"
#include "Compiler/systemCallLib.h"
#include "Utils/Variable.h"

using namespace std;
namespace wkl {
class ProgramExecutor;
class ProgramInstance {
public:
	ProgramInstance(uint32_t instanceRefId, SObj* comp, Program* program, map<uint32_t, systemCallFunc> systemCallFuncs, map<Variable, Variable> envContext);
	
	uint32_t interrupt(uint32_t obj, uint32_t functionId);
	uint32_t interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& _args);
	uint32_t interrupt(uint32_t obj, uint32_t functionId, vector<Variable>& _args, iterateFunc callback, void* callBackBlock);
	void yield(uint32_t refId, Variable* retVar);
	uint32_t getRegister(uint32_t refId);
	bool isTerminating();
	uint32_t run(uint32_t refId, uint32_t obj);
	uint32_t run(uint32_t refId, uint32_t obj, uint32_t functionId);
	uint32_t run(uint32_t refId, uint32_t obj, uint32_t functionId, vector<Variable> args);

	uint32_t getInstanceRef() {return this->_instanceRefId;}
	ProgramExecutor* getRunRef(uint32_t refId);
	SObj* getObj(){return this->_obj;}
	
	Program* getProgram() {return this->_program;}
	map<Variable, Variable>& getEnvContext() {return this->_envContext;}
    map<uint32_t, systemCallFunc>& getSystemCallFuncs(){return this->_systemCallFuncs;}
	virtual ~ProgramInstance();
private:
	uint32_t _instanceRefId;
	Program* _program;
	SObj* _obj;
	
	map<uint32_t, systemCallFunc> _systemCallFuncs;
	map<uint32_t, ProgramExecutor*> _instances;
	map<Variable, Variable> _envContext;
};
}
#endif	/* PROGRAMINSTANCE_H */

