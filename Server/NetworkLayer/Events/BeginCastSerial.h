

#ifndef BEGINCASTSERIAL_H
#define	BEGINCASTSERIAL_H

#include "../Network/Serialize.h"

namespace SerialEventSerialBeginCast{

struct SerialBeginCast : public SerialData{
	OBJID _caster;
	OBJID _powerId;
	OBJID _target;
	uint32_t _beginTime;
	uint32_t _endTime;
}__attribute__((__packed__));


SerialBeginCast* alloc(OBJID objId, OBJID powerId, OBJID target, uint32_t beginTime, uint32_t endTime){

	size_t size = sizeof(SerialBeginCast);
	SerialBeginCast* s = (SerialBeginCast*)malloc(size);
	s->_type = SerialType::SerialBeginCast;
	s->_size = size;
	s->_caster = objId;
	s->_powerId = powerId;
	s->_target = target;
	s->_beginTime = beginTime;
	s->_endTime = endTime;
	return s;
}
}
#endif	/* BEGINCASTSERIAL_H */

