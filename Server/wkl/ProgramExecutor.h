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
class ProgramExecutor {
public:
	ProgramExecutor(string name, SObj* obj, Program* program, map<uint32_t, systemCallFunc> systemCallFuncs);

	uint32_t run(uint32_t obj, uint32_t functionId, list<uint32_t> stack, map<uint32_t, Variable> envContext);
	
	uint32_t segfault(string message);	
	uint32_t segfault();
	void dumpStack();
	virtual void interrupt(uint32_t programId, uint32_t handlerId, uint32_t* payload, uint32_t payloadLen);
	//void yeld(){_registerFlags |= registerFlags::Yeld;}
	
	virtual ~ProgramExecutor();
private:
	string _name;
	Program* _program;
	SObj* _obj;
	map<uint32_t, systemCallFunc> _systemCallFuncs;
	uint32_t _registerFlags;
	uint32_t _mipsCredit;	
	uint32_t _programCounter;
	uint32_t _stackTop;
	vector<Variable> _stack;
	uint32_t _stackMax;
};
}
#endif	/* PROGRAMEXECUTOR_H */

