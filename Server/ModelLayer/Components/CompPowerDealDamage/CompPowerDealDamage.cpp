
#include "CompPowerDealDamage.h"

CompPowerDealDamage::CompPowerDealDamage() :
SComponent(COMPID::powerDealDamage){
	init();
}

CompPowerDealDamage::CompPowerDealDamage(const CompPowerDealDamage& orig) :
SComponent(COMPID::abilityInput){
	init();
}



void CompPowerDealDamage::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompPowerDealDamage::acceptMessage(MESSAGE::Enum type, Message* data){

}



void CompPowerDealDamage::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompPowerDealDamage::~CompPowerDealDamage() {
}

