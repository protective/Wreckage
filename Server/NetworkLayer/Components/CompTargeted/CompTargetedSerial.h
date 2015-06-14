
#ifndef COMPTARGETEDSERIAL_H
#define	COMPTARGETEDSERIAL_H

#include "../CompSerialize.h"

namespace SerialCompTargeted{
	enum Enum{
		Invalid = 0,
		SendFull = 1,
		ObjExit  = 2,
	};

struct SerialSendFull : public SerialComp{
}__attribute__((__packed__));

SerialSendFull* allocSendFull(OBJID objId){

	size_t size = sizeof(SerialSendFull);
	SerialSendFull* s = (SerialSendFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::targeted;
	s->op = (uint32_t)SerialCompTargeted::SendFull;
	return s;
}

}

#endif	/* COMPTARGETEDSERIAL_H */

