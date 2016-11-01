
#include "CompPosition.h"

#include "../../../Processor/Processor.h"

#include "../../Messages/MessageDestUpdate.h"

CompPosition::CompPosition(SObj* obj) :
SComponent(COMPID::position, obj){
	init();
}

CompPosition::CompPosition(uint32_t modelId, SObj* obj) :
SComponent(COMPID::position, obj){
	init();
}

CompPosition::CompPosition(const CompPosition& orig, SObj* obj) :
SComponent(COMPID::position, obj){
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

