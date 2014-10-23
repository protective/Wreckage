
#include "CompPowerUseCheck.h"

#include "../../../Processor/Processor.h"

#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerCheck.h"

CompPowerUseCheck::CompPowerUseCheck() :
SComponent(COMPID::powerUseCheck){
	
}

CompPowerUseCheck::CompPowerUseCheck(const CompPowerUseCheck& orig) :
SComponent(COMPID::powerUseCheck){

}


void CompPowerUseCheck::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompPowerUseCheck::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::activatePowerOnt:{
			MessageActivatePowerOnTarget* d = (MessageActivatePowerOnTarget*)data;
			_obj->setData(OBJDATA::target,(int32_t)d->target);
			MessagePowerCheck* msg = new MessagePowerCheck(_obj->getId());
			_obj->getProcessor()->sendMessage(data->_fromId, msg);
			break;
		}
	}
}


void CompPowerUseCheck::init(){
		_objDataAcces.push_back(OBJDATA::target);
}

CompPowerUseCheck::~CompPowerUseCheck() {
}

