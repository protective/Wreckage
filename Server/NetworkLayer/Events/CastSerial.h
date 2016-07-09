

#ifndef CASTSERIAL_H
#define	CASTSERIAL_H

#include "../Network/Serialize.h"

namespace SerialEventSerialCast{

struct SerialCastChangeStat {
	OBJDATA::Enum _statType;
	int32_t _oldVal;
	int32_t _newVal;
}__attribute__((__packed__));

struct SerialCastEffect {
	uint32_t _effect;
	uint8_t _hardpoint;
}__attribute__((__packed__));

struct SerialCast : public SerialData{
	OBJID _caster;
	OBJID _powerId;
	OBJID _target;
	int16_t _nStats;
	int16_t _nEffects;

}__attribute__((__packed__));

SerialCast* alloc(OBJID objId, OBJID powerId, OBJID target, list<SerialCastEffect> effects, list<SerialCastChangeStat> statschange){

	size_t size = sizeof(SerialCast)
			+ (sizeof(SerialCastEffect) * effects.size())
			+ (sizeof(SerialCastChangeStat) * statschange.size());
	
	SerialCast* s = (SerialCast*)malloc(size);
	s->_type = SerialType::SerialCast;
	s->_size = size;
	s->_nEffects = effects.size();
	s->_nStats = statschange.size();
	s->_target = target;
	s->_caster = objId;
	s->_powerId = powerId;
	s->_target = target;
	uint32_t i = 0;
	for (list<SerialCastEffect>::iterator it = effects.begin(); it != effects.end(); it++){
		SerialCastEffect* sce = (SerialCastEffect*)(s + sizeof(SerialCastEffect) * i++);
		sce->_effect = (*it)->_effect;
		sce->_hardpoint = (*it)->_hardpoint;
	}
	i = 0;
	for (list<SerialCastChangeStat>::iterator it = statschange.begin(); it != statschange.end(); it++){
		SerialCastChangeStat* sce = (SerialCastChangeStat*)(s + (sizeof(SerialCastEffect) * effects.size()) + sizeof(SerialCastChangeStat) * i++);
		sce->_statType = (*it)->_statType;
		sce->_oldVal = (*it)->_oldVal;
		sce->_newVal = (*it)->_newVal;
	}
	return s;
};
	
}

#endif	/* CASTSERIAL_H */

