
#include "CompPowerActivateTimed.h"

CompPowerActivateTimed::CompPowerActivateTimed(SObj* obj) :
SComponent(COMPID::powerActivateTimed, obj){
	
}

CompPowerActivateTimed::CompPowerActivateTimed(const CompPowerActivateTimed& orig, SObj* obj) :
SComponent(COMPID::powerActivateTimed, obj){

}


void CompPowerActivateTimed::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompPowerActivateTimed::acceptMessage(MESSAGE::Enum type, Message* data){

}


void CompPowerActivateTimed::init(){
}

CompPowerActivateTimed::~CompPowerActivateTimed() {
}

