
#include "CompPosition.h"


CompPosition::CompPosition() :
SComponent(COMPID::position){
	init();
}

CompPosition::CompPosition(uint32_t modelId) :
SComponent(COMPID::position){
	init();
}

CompPosition::CompPosition(const CompPosition& orig) :
SComponent(COMPID::position){
	init();
}


void CompPosition::init(){
}

void CompPosition::acceptSignal(SIGNAL::Enum type, Signal* data){
	
}

void CompPosition::acceptMessage(MESSAGE::Enum type, Message* data){
	
}


CompPosition::~CompPosition() {
}

