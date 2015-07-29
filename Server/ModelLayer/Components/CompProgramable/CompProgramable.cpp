
#include "CompProgramable.h"

#include "../../../Processor/Processor.h"

#include "../../../wkl/ProgramExecutor.h"

#include "../../Messages/MessageDestInRangeReq.h"
#include "../../Messages/MessageDestInRangeRsp.h"

#include "../../Signals/SignalEnterDevClient.h"
#include "../../Signals/SignalRunProgram.h"


CompProgramable::CompProgramable() :
SComponent(COMPID::programable){
	init();
}

CompProgramable::CompProgramable(const CompProgramable& orig) :
SComponent(COMPID::programable){
	init();
}

void CompProgramable::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
		
		case SIGNAL::runProgram: {
			
				
			map<uint32_t, wkl::systemCallFunc> _syscall;
			for (auto& it : this->_obj->getComponents()){
				auto tmp = it.second->getSyscalls();
				_syscall.insert(tmp.begin(), tmp.end());
			}
			SignalRunProgram* s = (SignalRunProgram*)data;
			
			auto it = _programExe.find(s->_runRef);
			wkl::ProgramExecutor* pe;
			if(it != _programExe.end()){
				pe = it->second;
			}else{
				cerr<<"env size = "<<(*(s->_env)).size()<<endl;
				pe = new wkl::ProgramExecutor(_programIdCounter++ ,this, s->_program, _syscall, *(s->_env));
			   _programExe[pe->getRunRef()] = pe;
			}
			uint32_t ret = 0;
			uint32_t tmmi = pe->getRegister();
			if((pe->getRegister() & wkl::registerFlags::yield) > 0){
				pe->yield(s->_retVar);
				ret = pe->run(_obj->getId());
			}else if(s->_program->getInterruptHandlers().find(s->_functionId) != s->_program->getInterruptHandlers().end()){
				ret = pe->run(_obj->getId(), s->_functionId);
			}
			
			if(ret & wkl::registerFlags::halt){
				_programExe.erase(pe->getRunRef());
				delete pe;
			}
			break;
		}
	}
}

void CompProgramable::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){

		case MESSAGE::destInRangeRsp :{
			MessageDestInRangeRsp* msg = (MessageDestInRangeRsp*)data;
			
			//that is leave it to wkl
			wkl::Variable v;
			v.t = new wkl::VObject();
			v.t->_vector.resize(msg->_res.size());
			uint32_t i = 0;
			for(auto it : msg->_res){
				v.t->_vector[i++] = it;
			}
			SignalRunProgram s( &v, msg->_ref);
			this->_obj->signal(SIGNAL::runProgram, &s);
			
			break;
		}
	}
}

void CompProgramable::init(){
	_programIdCounter = 1;
}

map<uint32_t, wkl::systemCallFunc> CompProgramable::getSyscalls(){
	return {
		{wkl::systemCallLib::getObjInRange, CompProgramable::getObjInRange}
	};
};


	
wkl::Variable CompProgramable::getObjInRange(SComponent* _this, wkl::ProgramExecutor* programExe, void* arg){

	wkl::Variable* args = (wkl::Variable*)arg;
	cerr<<"getObjInRange"<<endl;
	programExe->setFlag(wkl::registerFlags::yield);
	uint32_t range;
	range = (DAMAGETYPES::Enum)args[1].v;
	SPos p(0,0,0, 0);
	MessageDestInRangeReq* outmsg = new MessageDestInRangeReq(_this->getObj()->getId(), p, range, programExe->getRunRef());

	networkControl->sendMessage(0, outmsg);

			
	return wkl::Variable(0);
}


CompProgramable::~CompProgramable() {
}
