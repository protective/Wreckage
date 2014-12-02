
#include "CompPowerDealDamage.h"

#include "../../../Processor/Processor.h"

#include "../../Messages/MessageCasterStats.h"
#include "../../Messages/MessageProjectileStats.h"

CompPowerDealDamage::CompPowerDealDamage() :
SComponent(COMPID::powerDealDamage){
	init();
}

CompPowerDealDamage::CompPowerDealDamage(const CompPowerDealDamage& orig) :
SComponent(COMPID::abilityInput){
	init();
}



void CompPowerDealDamage::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::powerHit:{
			
			MessageCasterStats* msg = new MessageCasterStats(_obj->getId());
			_obj->getProcessor()->sendMessage(_obj->getData(OBJDATA::owner), msg);

			break;
		}
	}
}

void CompPowerDealDamage::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::casterStatsRsp:{
			if(_obj->getData(OBJDATA::target)){
				MessageProjectileStats* msg = new MessageProjectileStats(_obj->getId());
				_obj->getProcessor()->sendMessage((OBJID)_obj->getData(OBJDATA::target), msg);
			}
			break;
		}
	}
}



void CompPowerDealDamage::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompPowerDealDamage::~CompPowerDealDamage() {
}

