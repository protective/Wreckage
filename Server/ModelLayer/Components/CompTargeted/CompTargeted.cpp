
#include "CompTargeted.h"
#include "../../../Tasks/TaskRemoveObj.h"
#include "../../../Processor/Processor.h"
#include "../../Messages/MessageProjectileStats.h"
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

}

void CompTargeted::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::ProjectileStats:{
			
			
			MessageProjectileStats* msg = (MessageProjectileStats*)data;

			int32_t type, level, attackRoll, critP, damageRoll;
			
			int32_t def_hp, def_dodge, def_parry, def_block, def_level;
			
			int32_t miss;
			if(_obj->getData(OBJDATA::hp, &def_hp)
				&& _obj->getData(OBJDATA::level, &def_level) )
			{
				_obj->getData(OBJDATA::dodgeP, &def_dodge, 0);
				_obj->getData(OBJDATA::parryP, &def_parry, 0);
				_obj->getData(OBJDATA::blockP, &def_block, 0);
			
				if(msg->_stats.find(PROJECTILESTATS::type) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::level) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::attackRoll) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::critP) != msg->_stats.end()
					&& msg->_stats.find(PROJECTILESTATS::whitedamageRoll) != msg->_stats.end())
				{
					type = msg->_stats[PROJECTILESTATS::type];
					level = msg->_stats[PROJECTILESTATS::level];
					attackRoll = msg->_stats[PROJECTILESTATS::attackRoll];
					critP = msg->_stats[PROJECTILESTATS::critP];
					damageRoll = msg->_stats[PROJECTILESTATS::whitedamageRoll];

					if(def_level < level)
						miss = max((int32_t)1, (int32_t)5 - (level - def_level));
					else if(def_level == level)
						miss = 5;
					else
						miss = min((int32_t)99, (int32_t)(6 + pow(def_level - level, 2)));
					
					
					
				}	
			}
			
			

			
			TaskRemoveObj* task = new TaskRemoveObj(_obj->getId());
			_obj->getProcessor()->addTask(task);
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

