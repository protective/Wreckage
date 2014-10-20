
#include "CompPowerActivateInstant.h"

CompPowerActivateInstant::CompPowerActivateInstant() :
SComponent(COMPID::powerActivateInstant){
	init();
}

CompPowerActivateInstant::CompPowerActivateInstant(const CompPowerActivateInstant& orig) :
SComponent(COMPID::powerActivateInstant){
	init();
}

void CompPowerActivateInstant::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompPowerActivateInstant::acceptMessage(MESSAGE::Enum type, Message* data){

}

void CompPowerActivateInstant::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompPowerActivateInstant::~CompPowerActivateInstant() {
}

