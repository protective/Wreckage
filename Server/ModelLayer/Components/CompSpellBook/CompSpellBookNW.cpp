
#include "CompSpellBook.h"
#include "../../../Processor/Processor.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../../Network/InputSerial.h"
#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerStats.h"
#include "../../Messages/CompSpellBook/MessageSpellbookClone.h"

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
				list<OBJID> tmp;
				for (auto &kv: _powers) {
					tmp.push_back(kv.first);
				}
				for (auto clone : this->getObj()->getProcessor()->getClones(this->_obj->getId())){
					MessageSpellbookClone* m = new MessageSpellbookClone(this->_obj->getId(), tmp);
					this->getObj()->getProcessor()->sendMessage(clone->getId(), m);
				}
			}
		}
		case SERIALINPUT::SerialIndputRemoveCompValue: {
			SerialIndputRemoveCompValue* d = (SerialIndputRemoveCompValue*)data;
			if(d->_compId == COMPID::spellbook){
				SerialCompSpellBook::removeValue(this, (SerialCompSpellBook::SerialRemoveKnownpower*)&d[1]);
				list<OBJID> tmp;
				for (auto &kv: _powers) {
					tmp.push_back(kv.first);
				}
				for (auto clone : this->getObj()->getProcessor()->getClones(this->_obj->getId())){
					MessageSpellbookClone* m = new MessageSpellbookClone(this->_obj->getId(), tmp);
					this->getObj()->getProcessor()->sendMessage(clone->getId(), m);
				}
			}
		}
	}
}

void CompSpellBook::sendFull(uint32_t clientId){
	//cerr<<"CompSpellBook::sendFull obj "<<this->_obj->getId()<<endl;
	list<SerialCompSpellBook::SerialPower> tmplist;
	for(auto it: this->_powers) {
		
		SerialCompSpellBook::SerialPower tmp;
		tmp.templatePower = it.first;
		tmp.level = 0;
		tmp.trainedFlags = 0;
		if (it.second.obj) {
			tmp.power = it.second.obj->getId();
		} else {
			tmp.power = 0;
		}
		tmplist.push_back(tmp);
	}
	SerialCompSpellBook::SerialSendFull* tmp = SerialCompSpellBook::allocSendFull(
			this->_obj->getId(),
			tmplist);

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
