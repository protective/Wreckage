
#include "CompPowerUseCheck.h"

CompPowerUseCheck::CompPowerUseCheck() :
SComponent(COMPID::powerUseCheck){
	
}

CompPowerUseCheck::CompPowerUseCheck(const CompPowerUseCheck& orig) :
SComponent(COMPID::powerUseCheck){

}


void CompPowerUseCheck::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompPowerUseCheck::acceptMessage(MESSAGE::Enum type, Message* data){

}


void CompPowerUseCheck::init(){
}

CompPowerUseCheck::~CompPowerUseCheck() {
}

