/* 
 * File:   MessageSystemBroadcast.h
 * Author: karsten
 *
 * Created on 22. juli 2015, 23:23
 */

#ifndef MESSAGESYSTEMBROADCAST_H
#define	MESSAGESYSTEMBROADCAST_H

#include "Message.h"

struct MessageSystemBroadcast : public Message {
	enum  Enum{
		invalid = 0,
		dbloadObjComplete
	};
	MessageSystemBroadcast(OBJID from, Enum message):
	Message(MESSAGE::systemBroadcast, from){
		_message = message;
	}
	MessageSystemBroadcast(MessageSystemBroadcast& m):
	Message(MESSAGE::systemBroadcast, m._fromId){
		_message = m._message;
	}
	Enum _message;
};


#endif	/* MESSAGESYSTEMBROADCAST_H */

