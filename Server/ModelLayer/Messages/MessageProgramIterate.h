/* 
 * File:   MessageProgramIterate.h
 * Author: karsten
 *
 * Created on 28. juni 2016, 22:27
 */

#ifndef MESSAGEPROGRAMITERATE_H
#define	MESSAGEPROGRAMITERATE_H

#include "Message.h"
#include "../../wkl/Utils/Variable.h"
#include "../../wkl/Program.h"

struct MessageProgramIterate : public Message {
	MessageProgramIterate(
		OBJID obj,
		iterateFunc function,
		void* block
	):Message(MESSAGE::programIterate, obj){
		_function = function;
		_block = block;
	}
	MessageProgramIterate(MessageProgramIterate& m):
	Message(MESSAGE::programIterate, m._fromId){
		_function = m._function;
		_block = m._block;
	}
	~MessageProgramIterate(){
	}
	iterateFunc _function;
	void* _block;
};


#endif	/* MESSAGEPROGRAMITERATE_H */

