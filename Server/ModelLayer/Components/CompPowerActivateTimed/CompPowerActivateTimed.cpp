
#include "CompPowerActivateTimed.h"

CompPowerActivateTimed::CompPowerActivateTimed() :
SComponent(COMPID::powerActivateTimed){
	
}

CompPowerActivateTimed::CompPowerActivateTimed(const CompPowerActivateTimed& orig) :
SComponent(COMPID::powerActivateTimed){

}


void CompPowerActivateTimed::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompPowerActivateTimed::acceptMessage(MESSAGE::Enum type, Message* data){

}


void CompPowerActivateTimed::init(){
}

CompPowerActivateTimed::~CompPowerActivateTimed() {
}

