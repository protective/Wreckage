#ifndef MESSAGE_H
#define	MESSAGE_H

#include "../../BInclude.h"
#include "../enums.h"

struct Message {
	Message(MESSAGE::Enum type, OBJID fromId){
		_type = type;
		_fromId = fromId;
	}
	Message(Message& m){
		_type = m._type;
		_fromId = m._fromId;
	}
	uint32_t serialize(char* buff){}
	MESSAGE::Enum _type;
	OBJID _fromId;
};

#endif	/* MESSAGE_H */

