
#include "CompPowerBase.h"

#include "../../../Processor/Processor.h"

#include "../../../wkl/ProgramExecutor.h"

#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerCheck.h"
#include "../../Messages/MessageProjectileStats.h"


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
	switch(type){
		case MESSAGE::activatePowerOnt:{
			//cerr<<"MESSAGE::activatePowerOnt REC"<<endl;
			MessageActivatePowerOnTarget* msg = (MessageActivatePowerOnTarget*)data;
			
			
			
			map<uint32_t, Variable> envContext;
			envContext[1] = 1;
			envContext[2] = 2;
			envContext[3] = 10;
			envContext[4] = 90;
			
			MessageProjectileStats* outmsg = new MessageProjectileStats(_obj->getId(),_program,envContext);
			//_obj->setData(OBJDATA::target,(int32_t)d->target);
			
			_obj->getProcessor()->sendMessage(data->_fromId, outmsg);
			break;
		}
	}
}

void CompPowerBase::init(){
	
	_program = new wkl::Program("wkl/testPrograms/test_pow.wkl");
	
}

CompPowerBase::~CompPowerBase() {
}

