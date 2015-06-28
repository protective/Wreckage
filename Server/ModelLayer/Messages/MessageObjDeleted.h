
#ifndef MESSAGEOBJDELETED_H
#define	MESSAGEOBJDELETED_H

#include "Message.h"

struct MessageObjDeleted : public Message {
	MessageObjDeleted(OBJID from, OBJID deleted):
	Message(MESSAGE::objDeleted, from){
		_deleted = deleted;
	}
	MessageObjDeleted(MessageObjDeleted& m):
	Message(MESSAGE::objDeleted, m._fromId){
		_deleted = m._deleted;
	}
	OBJID _deleted;
};

#endif	/* MESSAGEOBJDELETED_H */

