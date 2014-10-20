
#include "CompPowerDealDamage.h"

CompPowerDealDamage::CompPowerDealDamage() :
SComponent(COMPID::powerDealDamage){
	init();
}

CompPowerDealDamage::CompPowerDealDamage(const CompPowerDealDamage& orig) :
SComponent(COMPID::abilityInput){
	init();
}

CompPowerDealDamage::CompPowerDealDamage(OBJID spawner) :
SComponent(COMPID::powerDealDamage){
	init();

}
void CompPowerDealDamage::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompPowerDealDamage::~CompPowerDealDamage() {
}

