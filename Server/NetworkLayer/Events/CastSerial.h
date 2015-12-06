

#ifndef CASTSERIAL_H
#define	CASTSERIAL_H

#include "../Network/Serialize.h"

namespace SerialEventSerialCast{

struct SerialCast : public SerialData{
	OBJID _caster;
	OBJID _powerId;
	OBJID _target;
}__attribute__((__packed__));

SerialCast* alloc(OBJID objId, OBJID powerId, OBJID target){

	size_t size = sizeof(SerialCast);
	SerialCast* s = (SerialCast*)malloc(size);
	s->_type = SerialType::SerialCast;
	s->_size = size;
	s->_target = target;
	s->_caster = objId;
	s->_powerId = powerId;
	s->_target = target;
	return s;
};
	
}

#endif	/* CASTSERIAL_H */

