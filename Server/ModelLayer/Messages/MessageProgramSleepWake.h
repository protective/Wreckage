/* 
 * File:   MessageProgramSleepWake.h
 * Author: karsten
 *
 * Created on 18. oktober 2015, 21:46
 */

#ifndef MESSAGEPROGRAMSLEEPWAKE_H
#define	MESSAGEPROGRAMSLEEPWAKE_H

#include "Message.h"
#include "../../wkl/Utils/Variable.h"
#include "../../wkl/Program.h"

struct MessageProgramSleepWake : public Message {
	MessageProgramSleepWake(
		OBJID from,
		uint32_t instanceRef,
		uint32_t runRef
	):Message(MESSAGE::programSleepWake, from){
		_runRef = runRef;
		_instanceRef = instanceRef;
	}
	MessageProgramSleepWake(MessageProgramSleepWake& m):
	Message(MESSAGE::programSleepWake, m._fromId){
		_runRef = m._runRef;
		_instanceRef = m._instanceRef;
	}
	~MessageProgramSleepWake(){
	}
	uint32_t _runRef;
	uint32_t _instanceRef;
};

#endif	/* MESSAGEPROGRAMSLEEPWAKE_H */

