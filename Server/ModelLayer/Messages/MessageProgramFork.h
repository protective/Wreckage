
#ifndef MESSAGEPROGRAMFORK_H
#define	MESSAGEPROGRAMFORK_H

#include "Message.h"
#include "../../wkl/Utils/Variable.h"
#include "../../wkl/Program.h"

struct MessageProgramFork : public Message {
	MessageProgramFork(
			OBJID from,
			wkl::Program* program,
			map<wkl::Variable, wkl::Variable> env,
			uint32_t functionId,
			uint32_t runRef
	):Message(MESSAGE::programFork, from){
		_env = env;
		_functionId = functionId;
		_runRef = runRef;
		_program = new wkl::Program(program);
	}
	MessageProgramFork(MessageProgramFork& m):
	Message(m._type, m._fromId){
		_env = m._env;
		_functionId = m._functionId;
		_runRef = m._runRef;
		_program = new wkl::Program(m._program);
	}
	~MessageProgramFork(){
		if (_program)
			delete _program;
	}
	map<wkl::Variable, wkl::Variable> _env;
	wkl::Program* _program;
	uint32_t _functionId;
	uint32_t _runRef;
};

#endif	/* MESSAGEPROGRAMFORK_H */

