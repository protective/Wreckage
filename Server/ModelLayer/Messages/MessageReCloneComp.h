
#ifndef MESSAGERECLONECOMP_H
#define	MESSAGERECLONECOMP_H

#include "Message.h"

struct MessageReCloneComp : public Message {
	MessageReCloneComp(OBJID from):
	Message(MESSAGE::reCloneComp, from){}
    
	MessageReCloneComp(MessageReCloneComp& m):
	Message(m._type, m._fromId){}
    
	~MessageReCloneComp(){}
};

#endif	/* MESSAGERECLONECOMP_H */

