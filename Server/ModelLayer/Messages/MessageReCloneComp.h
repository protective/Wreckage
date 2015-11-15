
#ifndef MESSAGERECLONECOMP_H
#define	MESSAGERECLONECOMP_H

#include "Message.h"
#include "../Components/SComponent.h"

struct MessageReCloneComp : public Message {
	MessageReCloneComp(
		OBJID from,
		SComponent* comp):
	Message(MESSAGE::reCloneComp, from)
	{
		_comp = comp;
	}
	MessageReCloneComp(MessageReCloneComp& m):
	Message(m._type, m._fromId){
		_comp = m._comp;
	}
	~MessageReCloneComp(){
		if (_comp)
			delete _comp;
	}
	SComponent* _comp;
};

#endif	/* MESSAGERECLONECOMP_H */

