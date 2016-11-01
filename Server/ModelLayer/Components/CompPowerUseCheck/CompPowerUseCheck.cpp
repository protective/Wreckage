
#include "CompPowerUseCheck.h"

#include "../../../Processor/Processor.h"

#include "../../Signals/SignalEnterDevClient.h"

#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerCheck.h"

CompPowerUseCheck::CompPowerUseCheck(SObj* obj) :
SComponent(COMPID::powerUseCheck, obj){
	
}

CompPowerUseCheck::CompPowerUseCheck(const CompPowerUseCheck& orig, SObj* obj) :
SComponent(COMPID::powerUseCheck, obj){

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
			/*
			cerr<<"MESSAGE::activatePowerOnt REC"<<endl;
			MessageProjectileStats* d = (MessageProjectileStats*)data;
			//_obj->setData(OBJDATA::target,(int32_t)d->target);
			MessageProjectileStats* msg = new MessageProjectileStats(_obj->getId());
			_obj->getProcessor()->sendMessage(data->_fromId, msg);
			*/
			break;
		}
	}
}


void CompPowerUseCheck::init(){
		_objDataAcces.push_back(OBJDATA::target);
}

CompPowerUseCheck::~CompPowerUseCheck() {
}

