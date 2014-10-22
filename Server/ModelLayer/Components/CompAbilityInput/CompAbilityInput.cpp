/* 
 * File:   CompAbilityInput.cpp
 * Author: karsten
 * 
 * Created on 19. oktober 2014, 19:35
 */

#include "CompAbilityInput.h"

#include "../../../Processor/Processor.h"
#include "../../Messages/MessagePowerCheck.h"
#include "../../Messages/MessageCasterStats.h"

CompAbilityInput::CompAbilityInput() :
SComponent(COMPID::abilityInput){
	init();
}

CompAbilityInput::CompAbilityInput(const CompAbilityInput& orig) :
SComponent(COMPID::abilityInput){
	init();

}

void CompAbilityInput::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompAbilityInput::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::powerCheck:{
			MessagePowerCheckRsp* msg = new MessagePowerCheckRsp(_obj->getId(),true);
			_obj->getProcessor()->sendMessage(data->_fromId, msg);
			break;
		}
		case MESSAGE::casterStatsReq:{
			MessageCasterStatsRsp* msg = new MessageCasterStatsRsp(_obj->getId(), 42);
			_obj->getProcessor()->sendMessage(data->_fromId, msg);
			break;
		}
	}
}

void CompAbilityInput::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompAbilityInput::~CompAbilityInput() {
}

