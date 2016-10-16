
#include "CompPowerBase.h"

#include "../../../Processor/Processor.h"

#include "../../../wkl/ProgramExecutor.h"

#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerCheck.h"
#include "../../Messages/MessageProgramFunctionSleep.h"
#include "../../Messages/MessagePowerStats.h"
#include "../../Messages/MessageReCloneComp.h"

#include "../../Signals/SignalEnterDevClient.h"
#include "../../Signals/SignalGainComp.h"

CompPowerBase::CompPowerBase() :
SComponent(COMPID::powerBase){
	_program = NULL;
	init();
}

CompPowerBase::CompPowerBase(const CompPowerBase& orig) :
SComponent(orig){
	_name = orig._name;
	_description = orig._description;
	_programSource = orig._programSource;
	_sym = orig._sym;
	_program = new wkl::Program(orig._program);
	init();
	
}

void CompPowerBase::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::gainComp:{
			SignalGainComp* s = (SignalGainComp*)data;
			if(s->_comp->getType() == COMPID::powerBase){
				for (map<uint32_t, uint32_t>::iterator it = _obj->getSubscribers().begin(); it != _obj->getSubscribers().end(); it++) {
					if (it->second > 0)
						this->sendFull(it->first);
				}
			}
			break;
		}
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
		case SIGNAL::enterClient:{
			//cerr<<"signal enter"<<endl;
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
		case MESSAGE::powerStats :{
			MessagePowerStats* msg = (MessagePowerStats*)data;
	
			map<uint32_t, wkl::Variable> envContext;
			MessagePowerStats* outmsg = new MessagePowerStats( _obj->getId(), _program, envContext, msg->_target);
			
			_obj->getProcessor()->sendMessage(data->_fromId, outmsg);
			break;
		}
		case MESSAGE::reCloneComp:{
			MessageReCloneComp* msg = (MessageReCloneComp*)data;
			CompPowerBase* comp = (CompPowerBase*)msg->_comp;
			_description = comp->_description;
			_name = comp->_name;
			if(_program)
				delete _program;
			_program = new wkl::Program(comp->_program);
			_sym = comp->_sym;
			
			break;
		}
	}
}

void CompPowerBase::init(){
	if (_program == NULL){
		//_program = new wkl::Program("wkl/testPrograms/test_pow.wkl", false);
		_description = "";
		_name = "";
		_programSource = "";
		_sym = "";
	}
}

void CompPowerBase::compileProgram(string src){
	stringstream outasm;
	if(_program)
		delete _program;
	_program = new wkl::Program(src, outasm);
	_sym = outasm.str();
	_programSource = src;
	//cerr<<_sym<<endl;
	dbSave();
}
void CompPowerBase::setName(string name){
	_name = name;
}
void CompPowerBase::setDescription(string description){
	_description = description;
}

CompPowerBase::~CompPowerBase() {
	if(_program)
		delete _program;
}

