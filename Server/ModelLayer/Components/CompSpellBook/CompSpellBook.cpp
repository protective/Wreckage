
#include "CompSpellBook.h"


#include "../../../Processor/Processor.h"



#include "../../Messages/MessagePowerStats.h"
#include "../../Messages/MessageProgramCallback.h"

#include "../../Signals/SignalEnterDevClient.h"
#include "../../Signals/SignalRunProgram.h"


CompSpellBook::CompSpellBook() :
SComponent(COMPID::spellbook){
	init();
}

CompSpellBook::CompSpellBook(const CompSpellBook& orig) :
SComponent(COMPID::spellbook){
	init();
}

void CompSpellBook::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
	}
}

void CompSpellBook::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::powerStatsRsp :{
			//cerr<<"MESSAGE::powerStatsRsp"<<endl;
			MessagePowerStats* msg = (MessagePowerStats*)data;
			
			map<uint32_t, wkl::Variable> envContext;
			envContext[systemEnvLib::wkl_level] = 1;
			envContext[systemEnvLib::wkl_target] = msg->_target;
			envContext[systemEnvLib::wkl_missChance] = 10;
			envContext[systemEnvLib::wkl_critChance] = 90;
			
			//that is leave it to wkl
			SignalRunProgram s(msg->_program, &envContext, systemCallBackLib::__activate_target__, 0);
			this->_obj->signal(SIGNAL::runProgram, &s);
			break;
		}
	}
}

void CompSpellBook::init(){

}

map<uint32_t, wkl::systemCallFunc> CompSpellBook::getSyscalls(){
	return {
		{wkl::systemCallLib::channel, CompSpellBook::channel},
		{wkl::systemCallLib::consume, CompSpellBook::consume}
	};
} 		



wkl::Variable CompSpellBook::consume(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){

	wkl::Variable* args = (wkl::Variable*)arg;
	cerr<<"consume"<<endl;
	return wkl::Variable(0);
}

wkl::Variable CompSpellBook::channel(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){
	
	wkl::Variable* args = (wkl::Variable*)arg;
	OBJID target = (OBJID)args[1].v;
	uint32_t count = (uint32_t)args[2].v;
	uint32_t delay = (uint32_t)args[3].v;
	
	//MessagePowerStats* msg = (MessagePowerStats*)data;
	for(int i = 1 ; i <= count; i++){
		MessageProgramCallback* outmsg = new MessageProgramCallback(
				_this->getId(),
				programExe->getProgram(),
				programExe->getEnvContext(),
				wkl::systemCallBackLib::__hit__,
				0);
		_this->getProcessor()->sendMessage(target, outmsg, delay * i);
	}
	return wkl::Variable(0);
}

CompSpellBook::~CompSpellBook() {
}