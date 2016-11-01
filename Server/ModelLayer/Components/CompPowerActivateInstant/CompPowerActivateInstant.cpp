
#include "CompPowerActivateInstant.h"

#include "../../Signals/SignalEnterDevClient.h"

CompPowerActivateInstant::CompPowerActivateInstant(SObj* obj) :
SComponent(COMPID::powerActivateInstant, obj){
	init();
}

CompPowerActivateInstant::CompPowerActivateInstant(const CompPowerActivateInstant& orig, SObj* obj) :
SComponent(COMPID::powerActivateInstant, obj){
	init();
}

void CompPowerActivateInstant::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
	}
}

void CompPowerActivateInstant::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::powerCheckRsp:{
			_obj->signal(SIGNAL::powerHit, NULL);
			break;
		}
	}
}

void CompPowerActivateInstant::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompPowerActivateInstant::~CompPowerActivateInstant() {
}

