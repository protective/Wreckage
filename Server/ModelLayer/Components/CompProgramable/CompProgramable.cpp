
#include "CompProgramable.h"

#include "../../../Processor/Processor.h"

#include "../../../wkl/ProgramExecutor.h"

#include "../../Messages/MessageDestInRangeReq.h"
#include "../../Messages/MessageDestInRangeRsp.h"
#include "../../Messages/MessageProgramSleepWake.h"
#include "../../Messages/MessageProgramFunctionSleep.h"

#include "../../Signals/SignalEnterDevClient.h"
#include "../../Signals/SignalRunProgram.h"

#include "../CompTargeted/CompTargeted.h"

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
				//cerr<<"env size = "<<(*(s->_env)).size()<<endl;
				pe = new wkl::ProgramExecutor(_programIdCounter++ ,this->getObj(), s->_program, _syscall, *(s->_env));
			    _programExe[pe->getRunRef()] = pe;
			}
			uint32_t ret = 0;
			uint32_t tmmi = pe->getRegister();
			if (s->_functionId == systemCallBackLib::__gain_buff__){
				if (this->getObj()->haveComponent(COMPID::targeted)){
					CompTargeted* comp = (CompTargeted*)this->getObj()->getComponents()[COMPID::targeted];
					comp->getBuffs()[pe->getRunRef()] = pe;
				}
			}
			if((pe->getRegister() & wkl::registerFlags::yield) > 0){
				//we are returning from a yield call
				pe->yield(s->_retVar);
				ret = pe->run(_obj->getId());
			}else if(s->_program->getInterruptHandlers().find(s->_functionId) != s->_program->getInterruptHandlers().end()){
				//call run function
				ret = pe->run(_obj->getId(), s->_functionId);
			}

			if(ret & wkl::registerFlags::halt){
				_programExe.erase(pe->getRunRef());
				if (this->getObj()->haveComponent(COMPID::targeted)){
					CompTargeted* comp = (CompTargeted*)this->getObj()->getComponents()[COMPID::targeted];
					comp->getBuffs().erase(pe->getRunRef());
				}
				
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
			//v.t->_vector.resize(msg->_res.size());
			uint32_t i = 0;
			for(auto it : msg->_res){
				v.t->_vector[i++] = it;
			}
			SignalRunProgram s( &v, msg->_ref);
			this->_obj->signal(SIGNAL::runProgram, &s);
			
			break;
		}
		case MESSAGE::programSleepWake : {
			MessageProgramSleepWake* msg = (MessageProgramSleepWake*)data;
			
			//that is leave it to wkl
			wkl::Variable v(0);

			SignalRunProgram s( &v, msg->_runRef);
			this->_obj->signal(SIGNAL::runProgram, &s);
			
			break;
		}
		case MESSAGE::programFunctionSleep : {
			MessageProgramFunctionSleep* msg = (MessageProgramFunctionSleep*)data;
			
			msg->_function(msg->_obj, msg->_programExe, msg->_arg);

			break;
		}		
		
	}
}

void CompProgramable::init(){
	_programIdCounter = 1;
}

map<uint32_t, wkl::systemCallFunc> CompProgramable::getSyscalls(){
	return {
		{wkl::systemCallLib::getObjInRange, CompProgramable::getObjInRange},
		{wkl::systemCallLib::sleep, CompProgramable::sleep},
		{wkl::systemCallLib::min, CompProgramable::min},
		{wkl::systemCallLib::max, CompProgramable::max}
	};
};

wkl::Variable CompProgramable::sleep(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){
	wkl::Variable* args = (wkl::Variable*)arg;
	programExe->setFlag(wkl::registerFlags::yield);
	MessageProgramSleepWake* outmsg = new MessageProgramSleepWake(
			_this->getId(),
			programExe->getRunRef());
	networkControl->sendMessage(_this->getId(), outmsg, args[1].v);
	return wkl::Variable(0);
}
	
wkl::Variable CompProgramable::getObjInRange(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){

	wkl::Variable* args = (wkl::Variable*)arg;
	//cerr<<"getObjInRange"<<endl;
	programExe->setFlag(wkl::registerFlags::yield);
	uint32_t range;
	range = (DAMAGETYPES::Enum)args[1].v;
	SPos p(0,0,0, 0);
	MessageDestInRangeReq* outmsg = new MessageDestInRangeReq(
			_this->getId(),
			p,
			range,
			programExe->getRunRef());

	networkControl->sendMessage(0, outmsg);

			
	return wkl::Variable(0);
}


wkl::Variable CompProgramable::max(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){
	wkl::Variable* args = (wkl::Variable*)arg;
	if (args[1].v > args[2].v)
		return args[1].v;
	else
		return args[2].v;
}

wkl::Variable CompProgramable::min(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){
	wkl::Variable* args = (wkl::Variable*)arg;
	if (args[1].v < args[2].v)
		return args[1].v;
	else
		return args[2].v;
}

CompProgramable::~CompProgramable() {
}
