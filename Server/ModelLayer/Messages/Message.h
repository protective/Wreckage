#ifndef MESSAGE_H
#define	MESSAGE_H

#include "../../BInclude.h"
#include "../enums.h"

struct Message {
	Message(MESSAGE::Enum type){
		_type = type;
	}
	Message(Message& m){
		_type = m._type;
	}
	uint32_t serialize(char* buff){}
	MESSAGE::Enum _type;
};

#endif	/* MESSAGE_H */

