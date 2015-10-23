
#include "CompTargeted.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Events/TargetGainBuffSerial.h"
#include "../../../NetworkLayer/Events/TargetLoseBuffSerial.h"

#include "../../../NetworkLayer/Components/CompTargeted/CompTargetedSerial.h"


void CompTargeted::sendEventTargetLoseBuff(
		OBJID target,
		uint32_t buffIndex)
{
	SerialEventTargetLoseBuff::SerialTargetLoseBuff* tmp = SerialEventTargetLoseBuff::alloc(
		target,
		buffIndex
		);
	for(map<uint32_t, uint32_t>::iterator it = this->_obj->getSubscribers().begin(); it != this->_obj->getSubscribers().end(); it++){
		if (it->second > 0)
			networkControl->sendToC(it->first, tmp, tmp->_size);
	}
	free(tmp);
}

void CompTargeted::sendEventTargetGainBuff(
		OBJID target,
		OBJID caster,
		uint32_t buffIndex,
		uint32_t duration,
		uint32_t maxduration,
		uint32_t charges,
		uint32_t image,
		uint32_t nameSIndex)
{
	SerialEventTargetGainBuff::SerialTargetGainBuff* tmp = SerialEventTargetGainBuff::alloc(
		target,
		caster,
		buffIndex,
		duration,
		maxduration,
		charges,
		image,
		nameSIndex
		);
	for(map<uint32_t, uint32_t>::iterator it = this->_obj->getSubscribers().begin(); it != this->_obj->getSubscribers().end(); it++){
		if (it->second > 0)
			networkControl->sendToC(it->first, tmp, tmp->_size);
	}
	free(tmp);

}

void CompTargeted::sendFull(uint32_t clientId){
	//cerr<<"CompTargeted::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompTargeted::SerialSendFull* tmp = SerialCompTargeted::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

