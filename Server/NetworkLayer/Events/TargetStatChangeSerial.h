
#ifndef TARGETSTATCHANGESERIAL_H
#define	TARGETSTATCHANGESERIAL_H

#include "Serialize.h"

namespace SerialEventTargetStatChange{

struct SerialTargetStatChange : public SerialData{
	STATS::Enum _statType;
	OBJID _target;
	OBJID _caster;
	powerResults::Enum _result;
	int32_t _oldVal;
	int32_t _newVal;
}__attribute__((__packed__));

SerialTargetStatChange* allocStatChange(OBJID target, OBJID caster, STATS::Enum statType, int32_t oldVal, int32_t newVal, powerResults::Enum result){
	size_t size = sizeof(SerialTargetStatChange);
	SerialTargetStatChange* s = (SerialTargetStatChange*)malloc(size);
	s->_type = SerialType::SerialTargetStatChange;
	s->_size = size;
	s->_newVal = newVal;
	s->_oldVal = oldVal;
	s->_statType = statType;
	s->_caster = caster;
	s->_target = target;
	s->_result = result;
	return s;
}
}

#endif	/* TARGETSTATCHANGESERIAL_H */

