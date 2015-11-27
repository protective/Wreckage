
#ifndef MESSAGEPROGRAMFUNCTIONSLEEP_H
#define	MESSAGEPROGRAMFUNCTIONSLEEP_H

#include "Message.h"
#include "../../wkl/ProgramExecutor.h"

struct MessageProgramFunctionSleep : public Message {
	MessageProgramFunctionSleep(OBJID from,
								wkl::systemCallFunc function,
								SObj* obj,
								wkl::ProgramExecutor* programExe,
								void* arg):
	Message(MESSAGE::programFunctionSleep, from){
		_obj = obj;
		_function = function;
		_programExe = programExe;
		_arg = arg;
	}
	MessageProgramFunctionSleep(MessageProgramFunctionSleep& m):
	Message(MESSAGE::programFunctionSleep, m._fromId){
		_obj = m._obj;
		_function = m._function;
		_programExe = m._programExe;
		_arg = m._arg;
		
	}
	~MessageProgramFunctionSleep(){
	}
	SObj* _obj;
	wkl::systemCallFunc _function;
	wkl::ProgramExecutor* _programExe;
	void* _arg;
};

#endif	/* MESSAGEPROGRAMFUNCTIONSLEEP_H */

