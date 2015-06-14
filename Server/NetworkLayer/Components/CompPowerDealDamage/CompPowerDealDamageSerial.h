
#ifndef COMPPOWERDEALDAMAGESERIAL_H
#define	COMPPOWERDEALDAMAGESERIAL_H

#include "../CompSerialize.h"

namespace SerialCompPowerDealDamage{
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
	s->compId = COMPID::powerDealDamage;
	s->op = (uint32_t)SerialCompPowerDealDamage::SendFull;
	return s;
}

}

#endif	/* COMPPOWERDEALDAMAGESERIAL_H */

