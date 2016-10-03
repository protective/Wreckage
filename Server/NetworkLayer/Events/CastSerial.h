

#ifndef CASTSERIAL_H
#define	CASTSERIAL_H

#include "../Network/Serialize.h"

namespace SerialEventSerialCast{

struct SerialCastEffect {
	uint32_t _effect;
	uint8_t _hardpoint;
}__attribute__((__packed__));

struct SerialCast : public SerialData{
	OBJID _caster;
	OBJID _powerId;
	OBJID _target;
	uint8_t _gfxRef;
	uint8_t _nEffects;

}__attribute__((__packed__));

SerialCast* alloc(OBJID objId, OBJID powerId, OBJID target, list<SerialCastEffect> effects, uint8_t gfxRef){
	uint32_t tm = effects.size();
	size_t size = sizeof(SerialCast)
			+ (sizeof(SerialCastEffect) * effects.size());
	
	SerialCast* s = (SerialCast*)malloc(size);
	memset(s, 0, size);
	s->_type = SerialType::SerialCast;
	s->_size = size;
	s->_nEffects = effects.size();
	s->_target = target;
	s->_gfxRef = gfxRef;
	s->_caster = objId;
	s->_powerId = powerId;
	s->_target = target;
	uint32_t i = 0;
	for (list<SerialCastEffect>::iterator it = effects.begin(); it != effects.end(); it++){
		SerialCastEffect* sce = (SerialCastEffect*)((char*)&s[1] + (sizeof(SerialCastEffect) * i));
		sce->_effect = (*it)._effect;
		sce->_hardpoint = (*it)._hardpoint;
		i++;
	}
	i = 0;
	return s;
};
	
}

#endif	/* CASTSERIAL_H */

