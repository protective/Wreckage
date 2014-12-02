/* 
 * File:   MessagePowerCheck.h
 * Author: karsten
 *
 * Created on 22. oktober 2014, 23:00
 */

#ifndef MESSAGEPOWERCHECK_H
#define	MESSAGEPOWERCHECK_H

#include "Message.h"

struct MessagePowerCheck: public Message {
	MessagePowerCheck(OBJID from):
	Message(MESSAGE::powerCheck, from){
	}
	MessagePowerCheck(MessagePowerCheck& m):
	Message(MESSAGE::powerCheck, m._fromId){
	}
};

struct MessagePowerCheckRsp : public Message {
	MessagePowerCheckRsp(OBJID from, bool success):
	Message(MESSAGE::powerCheckRsp, from){
		this->success = success;
	}
	MessagePowerCheckRsp(MessagePowerCheckRsp& m):
	Message(MESSAGE::powerCheckRsp, m._fromId){
	}
	bool success;
};

#endif	/* MESSAGEPOWERCHECK_H */

