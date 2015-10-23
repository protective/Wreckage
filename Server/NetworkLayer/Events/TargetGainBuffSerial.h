
#ifndef TARGETGAINBUFFSERIAL_H
#define	TARGETGAINBUFFSERIAL_H

#include "../Network/Serialize.h"

namespace SerialEventTargetGainBuff{

struct SerialTargetGainBuff : public SerialData{
	OBJID _target;
	OBJID _caster;
	uint32_t _buffIndex;
	uint32_t _duration;
	uint32_t _maxduration;
	uint32_t _charges;
	uint32_t _image;
	uint32_t _nameSIndex;
}__attribute__((__packed__));

SerialTargetGainBuff* alloc (OBJID target,
							OBJID caster,
							uint32_t buffIndex,
							uint32_t duration,
							uint32_t maxduration,
							uint32_t charges,
							uint32_t image,
							uint32_t nameSIndex){

	size_t size = sizeof(SerialTargetGainBuff);
	SerialTargetGainBuff* s = (SerialTargetGainBuff*)malloc(size);
	s->_type = SerialType::SerialTargetGainBuff;
	s->_size = size;
	s->_target = target;
	s->_caster = caster;
	s->_buffIndex = buffIndex;
	s->_duration = duration;
	s->_maxduration = maxduration;
	s->_charges = charges;
	s->_image = image;
	s->_nameSIndex = nameSIndex;
	return s;
}
}

#endif	/* TARGETGAINBUFFSERIAL_H */

