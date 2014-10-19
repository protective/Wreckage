

#ifndef MESSAGEKILLED_H
#define	MESSAGEKILLED_H

#include "Message.h"

struct MessageKilled : public Message {
	MessageKilled(OBJID from):
	Message(MESSAGE::killed, from){
	}
	MessageKilled(MessageKilled& m):
	Message(MESSAGE::killed, m._fromId){
	}
};


#endif	/* MESSAGEKILLED_H */

