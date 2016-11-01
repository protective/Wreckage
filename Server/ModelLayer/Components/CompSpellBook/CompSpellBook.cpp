
#include "CompSpellBook.h"

#include "../../SWorld.h"

#include "../../../Processor/Processor.h"

#include "../../Messages/MessagePowerStats.h"
#include "../../Messages/MessageProgramFork.h"
#include "../../Messages/MessageProgramSleepWake.h"
#include "../../Messages/MessageProgramFunctionSleep.h"
#include "../../Messages/CompSpellBook/MessageSpellbookClone.h"

#include "../../Signals/SignalEnterDevClient.h"
#include "../../Signals/SignalRunProgram.h"

CompSpellBook::CompSpellBook(SObj* obj) :
SComponent(COMPID::spellbook, obj){
	init();
}

CompSpellBook::CompSpellBook(const CompSpellBook& orig, SObj* obj) :
SComponent(COMPID::spellbook, obj){
	init();
	_gfxId = orig._gfxId;
	_castTime = 0;
	_beginTime = 0;
}

void CompSpellBook::addPower(OBJID power){
	if(!_obj->isTemplate()){
		OBJID tmp = _obj->getProcessor()->getFreeID();
		SObj* powerObj = _obj->getProcessor()->createObj(tmp, power, false, false);
		_powers[power] = powerObj;
	}else{
		_powers[power] = NULL;
	}
}
void CompSpellBook::removePower(OBJID power){
	//TODO delete obj
	_powers.erase(power);
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

			map<wkl::Variable, wkl::Variable> envContext;
			envContext[systemEnvLib::wkl_powerId] = msg->_fromId;
			envContext[systemEnvLib::wkl_level] = 1;
			envContext[systemEnvLib::wkl_target] = msg->_target;
			envContext[systemEnvLib::wkl_missChance] = 1;
			envContext[systemEnvLib::wkl_critChance] = 90;
			envContext[systemEnvLib::wkl_gfx_cast] = GFXTYPE::fireball1;
			envContext[systemEnvLib::wkl_gfx_hit] = GFXTYPE::renew1;
			
			//that is leave it to wkl
			SignalRunProgram s(msg->_program, &envContext, systemCallBackLib::__activate_target__, 0, 0);
			this->_obj->signal(SIGNAL::runProgram, &s);
			break;
		}
		case MESSAGE::reCloneComp:{
			MessageSpellbookClone* msg = (MessageSpellbookClone*)data;
			for (auto it: msg->_powers) {
				if (_powers.find(it) == _powers.end()) {
					this->addPower(it);
				}
			}
			break;
		}
	}
}

void CompSpellBook::init(){
	_gfxId = 0;
}

map<uint32_t, wkl::systemCallFunc> CompSpellBook::getSyscalls(){
	return {
		{wkl::systemCallLib::cast, CompSpellBook::cast},
		{wkl::systemCallLib::channel, CompSpellBook::channel},
		{wkl::systemCallLib::consumeMana, CompSpellBook::consumeMana}
	};
} 		

wkl::Variable CompSpellBook::consumeMana(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){

	wkl::Variable* args = (wkl::Variable*)arg;
	
	uint32_t consume = (uint32_t)args[1].v;
	int32_t curMana;
	cerr<<"consumeMana"<<endl;
	if (_this->getData(OBJDATA::mana, &curMana)){
		if (curMana >= consume){
			_this->setData(OBJDATA::mana, curMana - consume);
			//_this->sendEventTargetStatChange(0, OBJDATA::mana, curMana, curMana - consume, powerResults::invalid);
		
			return wkl::Variable(consume);
		}
	}
	return wkl::Variable(0);
}

wkl::Variable CompSpellBook::channel(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){

	wkl::Variable* args = (wkl::Variable*)arg;
	OBJID target = (OBJID)args[1].v;
	uint32_t count = (uint32_t)args[2].v;
	uint32_t delay = (uint32_t)args[3].v;

	//MessagePowerStats* msg = (MessagePowerStats*)data;
	for(int i = 1 ; i <= count; i++){
		MessageProgramFork* outmsg = new MessageProgramFork(
				_this->getId(),
				programExe->getProgram(),
				programExe->getEnvContext(),
				wkl::systemCallBackLib::__hit__,
				0);
		_this->getProcessor()->sendMessage(target, outmsg, delay * i);
	}
	return wkl::Variable(0);
}

wkl::Variable CompSpellBook::cast(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){

	wkl::Variable* args = (wkl::Variable*)arg;
	OBJID target = (OBJID)args[1].v;
	uint32_t delay = (uint32_t)args[2].v;
	
	VObject* tmp = (VObject*)args[3].t;
	int32_t manacost = 0;
	int32_t hpcost = 0;
	if (tmp){
		if (tmp->_vector.find(OBJDATA::mana) != tmp->_vector.end()) 
			manacost = tmp->_vector[OBJDATA::mana].v;
		if (tmp->_vector.find(OBJDATA::hp) != tmp->_vector.end())
			hpcost = tmp->_vector[OBJDATA::hp].v;
	}

	CompSpellBook* spellBook = (CompSpellBook*)_this->getComponents()[COMPID::spellbook];
	if(!spellBook){
		cerr<<"ERROR CompSpellBook::cast calling spellbook function without component"<<endl;
	}
	int32_t mana, hp;
	if(manacost != 0 && !_this->getData(OBJDATA::mana, &mana)){
		cerr<<"ERROR CompSpellBook::cast no mana var on obj"<<endl;
		return wkl::Variable(0);
	}
	if(hpcost != 0 && !_this->getData(OBJDATA::hp, &hp)){
		cerr<<"ERROR CompSpellBook::cast no hp var on obj"<<endl;
		return wkl::Variable(0);
	}
	if(spellBook->_castList.size() == 0){
		OBJID powerId = programExe->getEnvContext()[wkl::systemEnvLib::wkl_powerId].v;
		programExe->getEnvContext()[wkl::systemEnvLib::wkl_gfx_ref] = spellBook->_gfxId++;
		spellBook->_castList.push_back(powerId);
		spellBook->_beginTime = world->getTime();
		spellBook->_castTime = spellBook->_beginTime + delay;

		if (delay > 0){
			programExe->setFlag(wkl::registerFlags::yield);
			MessageProgramFunctionSleep* outmsg = new MessageProgramFunctionSleep(
				_this->getId(),
				CompSpellBook::cast_final,
				_this,
				programExe,
				arg);
			_this->getProcessor()->sendMessage(_this->getId(), outmsg, delay);
			spellBook->sendBeginCast(powerId, target, spellBook->_beginTime, spellBook->_castTime);
		}else{
			return CompSpellBook::cast_final(_this, programExe, arg);
		}
	}
	return wkl::Variable(0);
}

wkl::Variable CompSpellBook::cast_final(SObj* _this, wkl::ProgramExecutor* programExe, void* arg){
	wkl::Variable* args = (wkl::Variable*)arg;
	OBJID target = (OBJID)args[1].v;
	uint32_t delay = (uint32_t)args[2].v;
	VObject* tmp = (VObject*)args[3].t;
	
	CompSpellBook* spellBook = (CompSpellBook*)_this->getComponents()[COMPID::spellbook];
	if(!spellBook){
		cerr<<"ERROR CompSpellBook::cast calling spellbook function without component"<<endl;
	}

	int32_t manacost = 0;
	int32_t hpcost = 0;
	if (tmp){
		if (tmp->_vector.find(OBJDATA::mana) != tmp->_vector.end()) 
			manacost = tmp->_vector[OBJDATA::mana].v;
		if (tmp->_vector.find(OBJDATA::hp) != tmp->_vector.end())
			hpcost = tmp->_vector[OBJDATA::hp].v;
	}
	
	OBJID powerId = programExe->getEnvContext()[wkl::systemEnvLib::wkl_powerId].v;
	spellBook->_castList.remove(powerId);
	bool sucess = true;
	int32_t mana, hp;
	if(manacost != 0 && !_this->getData(OBJDATA::mana, &mana)){
		cerr<<"ERROR CompSpellBook::cast_final no mana var on obj"<<endl;
		sucess = false;
	}
	if(hpcost != 0 && !_this->getData(OBJDATA::hp, &hp)){
		cerr<<"ERROR CompSpellBook::cast_final no hp var on obj"<<endl;
		return wkl::Variable(0);
	}

	if (sucess){
		uint8_t gfxRef = programExe->getEnvContext()[wkl::systemEnvLib::wkl_gfx_ref].v;
		if(manacost != 0){
			_this->setData(OBJDATA::mana, mana - manacost);
			_this->sendEventTargetStatChange(
				0,
				OBJDATA::mana,
				mana,
				mana - manacost,
				powerResults::invalid,
				GFXTYPE::none,
				gfxRef);
		}
		if(hpcost != 0){
			_this->setData(OBJDATA::hp, hp - hpcost);
			_this->sendEventTargetStatChange(0,
					OBJDATA::mana,
					hp,
					hp - hpcost,
					powerResults::invalid,
					GFXTYPE::none,
					gfxRef);
		}
		MessageProgramFork* msgHit = new MessageProgramFork(
			_this->getId(),
			programExe->getProgram(),
			programExe->getEnvContext(),
			wkl::systemCallBackLib::__hit__,
			0);
		_this->getProcessor()->sendMessage(target, msgHit, 0);

		spellBook->sendCast(
			powerId,
			target,
			(GFXTYPE::Enum)programExe->getEnvContext()[wkl::systemEnvLib::wkl_gfx_cast].v,
			gfxRef);
	}

	MessageProgramSleepWake* outSleepWake = new MessageProgramSleepWake(
			_this->getId(),
			programExe->getInstanceRef(),
			programExe->getRunRef());
		_this->getProcessor()->sendMessage(_this->getId(), outSleepWake);

	return wkl::Variable(0);
}

CompSpellBook::~CompSpellBook() {
}