
#include "CompPosition.h"

#include "../../../Processor/Processor.h"

#include "../../Messages/MessageDestUpdate.h"

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
	switch(type){
		case SIGNAL::created:{
			if (_obj->getPos()){
				MessageDestUpdate* outmsg = new MessageDestUpdate( _obj->getId(), *_obj->getPos());

				_obj->getProcessor()->sendMessage(0, outmsg);
			}
			break;
		}
	}
}

void CompPosition::acceptMessage(MESSAGE::Enum type, Message* data){
	
}


CompPosition::~CompPosition() {
}

