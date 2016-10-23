
#include "CompSpellBook.h"
#include "../../../Processor/Processor.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../../Network/InputSerial.h"
#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerStats.h"

#include "../../../NetworkLayer/Components/CompSpellBook/CompSpellBookSerial.h"
#include "../../../NetworkLayer/Events/CastSerial.h"
#include "../../../NetworkLayer/Events/BeginCastSerial.h"


void CompSpellBook::acceptNetwork(SerialInputPayload* data){
	//cerr<<"CompSpellBook::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
		case SERIALINPUT::SerialInputCastPower :{
			SerialInputCastPower* d = (SerialInputCastPower*)data;
			
			MessagePowerStats* msg = new MessagePowerStats(_obj->getId(),d->_target);
			//_loadedPowers[d->_power];

			_obj->getProcessor()->sendMessage(d->_power, msg);
			break;
		}
		case SERIALINPUT::SerialIndputAddCompValue: {
			SerialIndputAddCompValue* d = (SerialIndputAddCompValue*)data;
			if(d->_compId == COMPID::spellbook){
				SerialCompSpellBook::addValue(this, (SerialCompSpellBook::SerialAddKnownpower*)&d[1]);

				//for (auto clone : this->getObj()->getProcessor()->getClones(this->_obj->getId())){
				//	MessageReCloneComp* m = new MessageReCloneComp(this->_obj->getId(), new CompPowerBase(*this) );
				//	this->getObj()->getProcessor()->sendMessage(clone->getId(), m);
				//}
			}
		}
		case SERIALINPUT::SerialIndputRemoveCompValue: {
			SerialIndputRemoveCompValue* d = (SerialIndputRemoveCompValue*)data;
			if(d->_compId == COMPID::spellbook){
				SerialCompSpellBook::removeValue(this, (SerialCompSpellBook::SerialRemoveKnownpower*)&d[1]);
			}
		}
	}
}

void CompSpellBook::sendFull(uint32_t clientId){
	//cerr<<"CompSpellBook::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompSpellBook::SerialSendFull* tmp = SerialCompSpellBook::allocSendFull(
			this->_obj->getId(),
			this->_loadedPowers);

	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

void CompSpellBook::sendCast(OBJID powerId, OBJID target, GFXTYPE::Enum gfxType, uint8_t gfxRef){

	list<SerialEventSerialCast::SerialCastEffect> effect_l;
	SerialEventSerialCast::SerialCastEffect effect;
	effect._effect = (uint32_t)gfxType;
	effect._hardpoint = 0;
	effect_l.push_back(effect);
	
	SerialEventSerialCast::SerialCast * tmp = SerialEventSerialCast::alloc(
			this->_obj->getId(),
			powerId,
			target,
			effect_l,
			gfxRef);

	for(map<uint32_t, uint32_t>::iterator it = this->_obj->getSubscribers().begin(); it != this->_obj->getSubscribers().end(); it++){
		if (it->second > 0)
			networkControl->sendToC(it->first, tmp, tmp->_size);
	}
	free(tmp);
}

void CompSpellBook::sendBeginCast(OBJID powerId, OBJID target, uint32_t beginTime, uint32_t endTime){
		SerialEventSerialBeginCast::SerialBeginCast * tmp = SerialEventSerialBeginCast::alloc(
			this->_obj->getId(),
			powerId,
			target,
			beginTime,
			endTime);

	for(map<uint32_t, uint32_t>::iterator it = this->_obj->getSubscribers().begin(); it != this->_obj->getSubscribers().end(); it++){
		if (it->second > 0)
			networkControl->sendToC(it->first, tmp, tmp->_size);
	}
	free(tmp);
	
}
