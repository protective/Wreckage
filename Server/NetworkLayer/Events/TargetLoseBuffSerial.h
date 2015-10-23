
#ifndef TARGETLOSEBUFFSERIAL_H
#define	TARGETLOSEBUFFSERIAL_H


#include "../Network/Serialize.h"

namespace SerialEventTargetLoseBuff{

struct SerialTargetLoseBuff : public SerialData{
	OBJID _target;
	uint32_t _buffIndex;
}__attribute__((__packed__));

SerialTargetLoseBuff* alloc (OBJID target,
							uint32_t buffIndex){

	size_t size = sizeof(SerialTargetLoseBuff);
	SerialTargetLoseBuff* s = (SerialTargetLoseBuff*)malloc(size);
	s->_type = SerialType::SerialTargetLoseBuff;
	s->_size = size;
	s->_target = target;
	s->_buffIndex = buffIndex;
	return s;
}
}


#endif	/* TARGETLOSEBUFFSERIAL_H */

