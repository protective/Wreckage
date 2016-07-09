
#ifndef TARGETSTATCHANGESERIAL_H
#define	TARGETSTATCHANGESERIAL_H

#include "Serialize.h"

namespace SerialEventTargetStatChange{

struct SerialTargetStatChangeStat {
	OBJDATA::Enum _statType;
	int32_t _oldVal;
	int32_t _newVal;
}__attribute__((__packed__));

struct SerialTargetStatChangeEffect {
	uint32_t _effect;
	uint8_t _hardpoint;
}__attribute__((__packed__));

struct SerialTargetStatChange : public SerialData{
	int16_t _nStats;
	int16_t _nEffects;
	powerResults::Enum _result;
	OBJID _target;
	OBJID _caster;

}__attribute__((__packed__));

SerialTargetStatChange* allocStatChange(OBJID target, OBJID caster,
		OBJDATA::Enum statType, int32_t oldVal, int32_t newVal, powerResults::Enum result){
	size_t size = sizeof(SerialTargetStatChange);
	SerialTargetStatChange* s = (SerialTargetStatChange*)malloc(size);
	s->_type = SerialType::SerialTargetStatChange;
	s->_size = size;
	//s->_newVal = newVal;
	//s->_oldVal = oldVal;
	//s->_statType = statType;
	s->_caster = caster;
	s->_target = target;
	s->_result = result;
	return s;
}
}

#endif	/* TARGETSTATCHANGESERIAL_H */

