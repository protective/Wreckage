
#include "CompProgramable.h"

#include "../../../Processor/Processor.h"

#include "../../../wkl/ProgramInstance.h"

#include "../../Messages/MessageDestInRangeReq.h"
#include "../../Messages/MessageDestInRangeRsp.h"
#include "../../Messages/MessageProgramSleepWake.h"
#include "../../Messages/MessageProgramFunctionSleep.h"
#include "../../Messages/MessageProgramIterate.h"

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
			
			auto it = _programInst.find(s->_instanceRef);
			wkl::ProgramInstance* pi;
			if(it != _programInst.end()){
				pi = it->second;
			}else{
				//cerr<<"env size = "<<(*(s->_env)).size()<<endl;
				pi = new wkl::ProgramInstance(_programIdCounter++ ,this->getObj(), s->_program, _syscall, *(s->_env));
			    _programInst[pi->getInstanceRef()] = pi;
			}
			uint32_t ret = 0;
			//uint32_t tmmi = pi->getRegister();
			if (s->_functionId == systemCallBackLib::__gain_buff__){
				if (this->getObj()->haveComponent(COMPID::targeted)){
					CompTargeted* comp = (CompTargeted*)this->getObj()->getComponents()[COMPID::targeted];
					comp->getBuffs()[pi->getInstanceRef()] = pi;
				}
			}
			uint32_t runRef = s->_runRef;
			if((pi->getRegister(runRef) & wkl::registerFlags::yield) > 0){
				//we are returning from a yield call
				cerr<<"wkl ref="<<runRef<<" yield "<<s->_retVar->v<<endl;
				pi->yield(runRef, s->_retVar);
				ret = pi->run(runRef, _obj->getId());
			}else if(s->_program->getInterruptHandlers().find(s->_functionId) != s->_program->getInterruptHandlers().end()){
				//call interrupt t run a 
				cerr<<"wkl interrupt function "<<s->_functionId<<endl;
				runRef = pi->interrupt(_obj->getId(), s->_functionId);
			}
			

			if(pi->isTerminating()){
				_programInst.erase(pi->getInstanceRef());
				if (this->getObj()->haveComponent(COMPID::targeted)){
					CompTargeted* comp = (CompTargeted*)this->getObj()->getComponents()[COMPID::targeted];
					comp->getBuffs().erase(pi->getInstanceRef());
				}
				delete pi;
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
			SignalRunProgram s( &v, msg->_instanceRef, msg->_runRef);
			this->_obj->signal(SIGNAL::runProgram, &s);

			break;
		}
		case MESSAGE::programSleepWake : {
			MessageProgramSleepWake* msg = (MessageProgramSleepWake*)data;
			
			wkl::Variable v(0);

			SignalRunProgram s( &v, msg->_instanceRef, msg->_runRef);
			this->_obj->signal(SIGNAL::runProgram, &s);

			break;
		}
		case MESSAGE::programFunctionSleep : {
			MessageProgramFunctionSleep* msg = (MessageProgramFunctionSleep*)data;
			
			msg->_function(msg->_obj, msg->_programExe, msg->_arg);

			break;
		}
		case MESSAGE::programIterate:{
			MessageProgramIterate* msg = (MessageProgramIterate*)data;
			msg->_function(this->_obj, msg->_block);
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
			programExe->getInstanceRef(),
			programExe->getRunRef());
	networkControl->sendMessage(_this->getId(), outmsg, args[1].v); //args[1].v sleep amount
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
			programExe->getInstanceRef(),
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
