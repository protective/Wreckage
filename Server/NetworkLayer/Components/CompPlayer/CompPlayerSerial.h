
#ifndef COMPPLAYERSERIAL_H
#define	COMPPLAYERSERIAL_H

#include "../CompSerialize.h"

namespace SerialCompPlayer{
	enum Enum{
		Invalid = 0,
		SendFull = 1
	};

struct SerialSendFull : public SerialComp{
}__attribute__((__packed__));

SerialSendFull* allocSendFull(OBJID objId){

	size_t size = sizeof(SerialSendFull);
	SerialSendFull* s = (SerialSendFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::player;
	s->op = (uint32_t)SerialCompPlayer::SendFull;
	return s;
}

}

#endif	/* COMPPLAYERSERIAL_H */

