
#include "CompPowerUseCheck.h"

#include "../../../Processor/Processor.h"

#include "../../Signals/SignalEnterDevClient.h"

#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerCheck.h"

CompPowerUseCheck::CompPowerUseCheck() :
SComponent(COMPID::powerUseCheck){
	
}

CompPowerUseCheck::CompPowerUseCheck(const CompPowerUseCheck& orig) :
SComponent(COMPID::powerUseCheck){

}


void CompPowerUseCheck::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
	}
}

void CompPowerUseCheck::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::activatePowerOnt:{
			cerr<<"MESSAGE::activatePowerOnt REC"<<endl;
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

