
#include "CompPowerBase.h"

#include "../../Signals/SignalEnterDevClient.h"


CompPowerBase::CompPowerBase() :
SComponent(COMPID::powerBase){
	init();
}

CompPowerBase::CompPowerBase(const CompPowerBase& orig) :
SComponent(COMPID::powerBase){
	init();
}

void CompPowerBase::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
		case SIGNAL::enterClient:{
			cerr<<"signal enter"<<endl;
			//SignalEnterClient* s = (SignalEnterClient*)data;
			//sendEnter(s->_clientId);
			break;
		}
		case SIGNAL::exitClient:{
			//SignalExitClient* s = (SignalExitClient*)data;
			//sendEnter(s->_clientId);
			break;
		}
	}
}

void CompPowerBase::acceptMessage(MESSAGE::Enum type, Message* data){

}

void CompPowerBase::init(){
}

CompPowerBase::~CompPowerBase() {
}

