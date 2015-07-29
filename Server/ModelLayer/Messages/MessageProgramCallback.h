
#ifndef MESSAGEPROGRAMCALLBACK_H
#define	MESSAGEPROGRAMCALLBACK_H

#include "Message.h"
#include "../../wkl/Utils/Variable.h"
#include "../../wkl/Program.h"

struct MessageProgramCallback : public Message {
	MessageProgramCallback(
			OBJID from,
			wkl::Program* program,
			map<uint32_t, wkl::Variable> env,
			uint32_t functionId,
			uint32_t runRef
	):Message(MESSAGE::programCallback, from){
		_env = env;
		_functionId = functionId;
		_runRef = runRef;
		_program = new wkl::Program(program);
	}
	MessageProgramCallback(MessageProgramCallback& m):
	Message(m._type, m._fromId){
		_env = m._env;
		_functionId = m._functionId;
		_runRef = m._runRef;
		_program = new wkl::Program(m._program);
	}
	~MessageProgramCallback(){
		if (_program)
			delete _program;
	}
	map<uint32_t, wkl::Variable> _env;
	wkl::Program* _program;
	uint32_t _functionId;
	uint32_t _runRef;
};

#endif	/* MESSAGEPROGRAMCALLBACK_H */

