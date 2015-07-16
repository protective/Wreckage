
#include "CompTargeted.h"
#include "../../../Tasks/TaskRemoveObj.h"
#include "../../../Processor/Processor.h"
#include "../../../wkl/ProgramExecutor.h"
#include "../../../wkl/Program.h"
#include "../../../ModelLayer/SObj.h"

#include "../../Signals/SignalEnterDevClient.h"

#include "../../Messages/MessageProgramCallback.h"


#include "GFunctions.h"
#include <math.h>
CompTargeted::CompTargeted() :
SComponent(COMPID::targeted){
	init();
}

CompTargeted::CompTargeted(const CompTargeted& orig) :
SComponent(COMPID::targeted){
	init();
}

void CompTargeted::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
	}
}

void CompTargeted::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::programCallback:{
			
			
			MessageProgramCallback* msg = (MessageProgramCallback*)data;
			
			wkl::ProgramExecutor* pe = new wkl::ProgramExecutor("" ,this, msg->_program, _syscall);

			if(msg->_program->getInterruptHandlers().find(msg->_functionId) != msg->_program->getInterruptHandlers().end())
				pe->run(_obj->getId(), msg->_functionId, msg->_env);

		}

	}
}

void CompTargeted::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);

}

map<uint32_t, wkl::systemCallFunc> CompTargeted::_syscall = 		
	{{wkl::systemCallLib::phycicalDamage, CompTargeted::phycicalDamage}};

wkl::Variable CompTargeted::phycicalDamage(SComponent* _this, wkl::Program* program, map<uint32_t, wkl::Variable> envContext, void* arg){
	
	SObj* target = _this->getObj();
	wkl::Variable* args = (wkl::Variable*)arg;
	cout<<"Projectile Hit"<<endl;
	int32_t  level, attack, missP, critP, damageNormal, damageCrit;
	DAMAGETYPES::Enum dmgtype;
	int32_t def_hp = 0, def_dodge = 0, def_parry = 0, def_block = 0, def_level = 0, def_AC = 0;
	int32_t miss;
	int32_t glancing;
	
	level = envContext[1].v;
	attack = envContext[2].v;
	missP = envContext[3].v;
	critP = envContext[4].v;
	
	dmgtype = (DAMAGETYPES::Enum)args[1].v;
	damageNormal = args[2].v;
	damageCrit = args[3].v;


	if(def_level < level)
		miss = max((int32_t)1, (int32_t)5 - (level - def_level));
	else if(def_level == level)
		miss = 5;
	else
		miss = min((int32_t)99, (int32_t)(6 + pow(def_level - level, 2)));
	miss += max((int32_t)0, missP);

	glancing = max((int32_t)0,
		(100 - ((miss + def_dodge + def_parry + def_block) * 2))
	   -((5 * attack) - def_AC));
	uint32_t roll = myrandom(0, 99);
	string result;
	uint32_t d = 0;

	int32_t damage = 0;
	if(roll < (d += miss)){
		result = "miss";
	}else if(roll < (d += def_dodge)){
		result = "dodge";
	}else if(roll < (d += def_parry)){
		result = "parry";
		damage = dmgtype==DAMAGETYPES::crushing ? damageNormal / 2 : 0;
	}else if(roll < (d += def_block)){
		result = "block";		
		damage = dmgtype==DAMAGETYPES::crushing ? damageNormal / 2 : 0;
	}else if(roll < (d += glancing)){
		result = "glancing";	
		damage = dmgtype==DAMAGETYPES::crushing || dmgtype==DAMAGETYPES::slashing ? damageNormal / 2 : 0;
	}else if(roll < (d += critP)){
		result = "crit";
		damage = damageNormal + damageCrit;
		damage += dmgtype==DAMAGETYPES::pircing ? damageCrit : 0;

	}else{
		result = "hit";
		damage = damageNormal;
	}
	wkl::Variable u;
	u.v = 0;
	u.t = new wkl::VObject();
	u.t->_vector.resize(2);
	//cout<<"projectile apply objid="<<_obj->getId()<<" roll="<<roll<<" result="<<result<<" damage="<<damage<<endl;
	if (target->getData(OBJDATA::hp, &def_hp)) {
		//TODO from id in program??
		target->setData(OBJDATA::hp, def_hp - damage);
		target->sendEventTargetStatChange(0, OBJDATA::hp, def_hp, def_hp - damage, powerResults::hit);
		
		u.t->_vector[0] = (int32_t)powerResults::hit;
		u.t->_vector[1] = def_hp - damage;
	}else{
		cerr<<"ERROR no hp?"<<endl;
		u.t->_vector[0] = 0;
		u.t->_vector[1] = 0;
	}

	return u;
}

CompTargeted::~CompTargeted() {
}

