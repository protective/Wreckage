
#include "CompTargeted.h"
#include "../../../Tasks/TaskRemoveObj.h"
#include "../../../Processor/Processor.h"

#include "../../Signals/SignalEnterDevClient.h"

#include "../../Messages/MessageProjectileStats.h"


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
		case MESSAGE::ProjectileStats:{
			
			
			MessageProjectileStats* msg = (MessageProjectileStats*)data;
			cout<<"Projectile Hit"<<endl;
			int32_t  level, attack, missP, critP, damageNormal, damageCrit;
			DAMAGETYPES::Enum dmgtype;
			int32_t def_hp, def_dodge, def_parry, def_block, def_level, def_AC;
			
			int32_t miss;
			int32_t glancing;
			if(_obj->getData(OBJDATA::hp, &def_hp)
				&& _obj->getData(OBJDATA::level, &def_level) )
			{
				_obj->getData(OBJDATA::dodgeP, &def_dodge, 0);
				_obj->getData(OBJDATA::parryP, &def_parry, 0);
				_obj->getData(OBJDATA::blockP, &def_block, 0);
				_obj->getData(OBJDATA::AC, &def_AC, 1);
				
				if(msg->_stats.find(PROJECTILESTATS::type) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::level) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::attack) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::critP) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::missP) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::whiteDamage) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::whiteDamageCrit) != msg->_stats.end())
				{
					dmgtype = (DAMAGETYPES::Enum)msg->_stats[PROJECTILESTATS::type];
					level = msg->_stats[PROJECTILESTATS::level];
					attack = msg->_stats[PROJECTILESTATS::attack];
					critP = msg->_stats[PROJECTILESTATS::critP];
					missP = msg->_stats[PROJECTILESTATS::missP];
					damageNormal = msg->_stats[PROJECTILESTATS::whiteDamage];
					damageCrit = msg->_stats[PROJECTILESTATS::whiteDamageCrit];


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
					cout<<"projectile apply objid="<<_obj->getId()<<" roll="<<roll<<" result="<<result<<" damage="<<damage<<endl;
				}
					
			}
			this->_obj->sendEventTargetStatChange(data->_fromId, STATS::hp, 10, 5, powerResults::hit);
			//TaskRemoveObj* task = new TaskRemoveObj(_obj->getId());
			//_obj->getProcessor()->addTask(task);
			break;
		}

	}
}

void CompTargeted::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompTargeted::~CompTargeted() {
}

