
#ifndef TARGETSTATCHANGESERIAL_H
#define	TARGETSTATCHANGESERIAL_H

#include "Serialize.h"

namespace SerialEventTargetStatChange{

struct SerialStat {
	OBJDATA::Enum _statType;
	int32_t _oldVal;
	int32_t _newVal;
}__attribute__((__packed__));

struct SerialEffect {
	uint32_t _effect;
	uint8_t _hardpoint;
}__attribute__((__packed__));

struct SerialTargetStatChange : public SerialData{
	powerResults::Enum _result;
	OBJID _target;
	OBJID _caster;
	uint8_t _nStats;
	uint8_t _nEffects;
	uint8_t _gfxRef;

}__attribute__((__packed__));

SerialTargetStatChange* allocStatChange(OBJID target, OBJID caster,
		powerResults::Enum result,
		list<SerialStat> stats,
		list<SerialEffect> effects,
		uint8_t gfxRef)
{
	size_t size = sizeof(SerialTargetStatChange) +
			      (sizeof(SerialStat) * stats.size()) + 
				  (sizeof(SerialEffect) * effects.size());

	SerialTargetStatChange* s = (SerialTargetStatChange*)malloc(size);
	s->_type = SerialType::SerialTargetStatChange;
	s->_size = size;
	s->_caster = caster;
	s->_target = target;
	s->_result = result;
	s->_nEffects = effects.size();
	s->_nStats = stats.size();
	s->_gfxRef = gfxRef;

	uint32_t i = 0;
	for (list<SerialStat>::iterator it = stats.begin(); it != stats.end(); it++){
		SerialStat* sce =
			(SerialStat*)((char*)&s[1] +
						  (sizeof(SerialStat) * i));
		sce->_newVal = (*it)._newVal;
		sce->_oldVal = (*it)._oldVal;
		sce->_statType = (*it)._statType;
		i++;
	}
	i = 0;
	for (list<SerialEffect>::iterator it = effects.begin(); it != effects.end(); it++){
		uint32_t a= ((sizeof(SerialStat) * stats.size()) +
							(sizeof(SerialEffect) * i));
		SerialEffect* sce =
			(SerialEffect*)((char*)&s[1] + a);
							
		sce->_effect = (*it)._effect;
		sce->_hardpoint = (*it)._hardpoint;
		i++;
	}
	return s;
}
}

#endif	/* TARGETSTATCHANGESERIAL_H */

