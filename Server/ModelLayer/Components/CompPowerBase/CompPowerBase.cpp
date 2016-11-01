
#include "CompPowerBase.h"

#include "../../../Processor/Processor.h"

#include "../../../wkl/ProgramExecutor.h"

#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerCheck.h"
#include "../../Messages/MessageProgramFunctionSleep.h"
#include "../../Messages/MessagePowerStats.h"
#include "../../Messages/CompPowerBase/MessagePowerBaseClone.h"

#include "../../Signals/SignalEnterDevClient.h"
#include "../../Signals/SignalGainComp.h"

CompPowerBase::CompPowerBase(SObj* obj) :
SComponent(COMPID::powerBase, obj){
	_program = NULL;
	init();
}

CompPowerBase::CompPowerBase(const CompPowerBase& orig, SObj* obj) :
SComponent(orig, obj){
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
			MessagePowerBaseClone* msg = (MessagePowerBaseClone*)data;
			_description = msg->_description;
			_name = msg->_name;
			_sym = msg->_sym;
			if(_program)
				delete _program;
			_program = msg->_program;
			msg->_program = NULL;
			
			
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
	dbSave();
}
void CompPowerBase::setDescription(string description){
	_description = description;
	dbSave();
}

CompPowerBase::~CompPowerBase() {
	if(_program)
		delete _program;
}

