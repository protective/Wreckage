
#include "SObj.h"

#include "../NetworkLayer/ObjSerial.h"
#include "../NetworkLayer/Events/TargetStatChangeSerial.h"
#include "../NetworkLayer/NetworkControler.h"

void SObj::sendall(uint32_t clientId){
	//cerr<<"SObj::sendall obj "<<this->_id<<endl;
	uint32_t size = SerialObjAll::getMallocSize(this);
	char* tmp = (char*)malloc(size);
	SerialObjAll::pack(tmp, this, size);
	networkControl->sendToC(clientId, tmp, size);
	free(tmp);
}
void SObj::sendEventTargetStatChange (
	OBJID caster,
	OBJDATA::Enum statType,
	int32_t oldVal,
	int32_t newVal,
	powerResults::Enum result,
	GFXTYPE::Enum gfxType,
	uint8_t gfxRef)
{
	list<SerialEventTargetStatChange::SerialStat> stat_l;
	SerialEventTargetStatChange::SerialStat stat;
	stat._newVal = newVal;
	stat._oldVal = oldVal;
	stat._statType = statType;
	stat_l.push_back(stat);

	list<SerialEventTargetStatChange::SerialEffect> effect_l;
	SerialEventTargetStatChange::SerialEffect effect;
	effect._effect = (uint32_t)gfxType;
	effect._hardpoint = 0;
	effect_l.push_back(effect);
	
	SerialEventTargetStatChange::SerialTargetStatChange* tmp = SerialEventTargetStatChange::allocStatChange(
		this->getId(),
		caster,
		result,
		stat_l,
		effect_l,
		gfxRef);
	for(map<uint32_t, uint32_t>::iterator it = _subscribers.begin(); it != _subscribers.end(); it++){
		if (it->second > 0)
			networkControl->sendToC(it->first, tmp, tmp->_size);
	}
	free(tmp);
}