
#ifndef MESSAGEREQUESTREFOBJ_H
#define	MESSAGEREQUESTREFOBJ_H

#include "Message.h"

struct MessageRequestRefObj : public Message {
	MessageRequestRefObj(OBJID from):
	Message(MESSAGE::requestRefObj, from){
	}
	MessageRequestRefObj(MessageRequestRefObj& m):
	Message(MESSAGE::requestRefObj, m._fromId){
	}
};

#endif	/* MESSAGEREQUESTREFOBJ_H */

