
#include "CompReSpawnable.h"
#include "../../../Processor/Processor.h"

#include "../../Signals/SignalProcess.h"
#include "../../Signals/SignalEnterDevClient.h"

#include "../../Messages/MessageKilled.h"
#include "../../Messages/MessageHeartBeatReq.h"
#include "../../Messages/MessageHeartBeatRsp.h"

CompReSpawnable::CompReSpawnable() :
SComponent(COMPID::reSpawnable){
	init();
	_spawner = 0;
}

CompReSpawnable::CompReSpawnable(const CompReSpawnable& orig) :
SComponent(COMPID::reSpawnable){
	init();
	_spawner = orig._spawner;

}

CompReSpawnable::CompReSpawnable(OBJID spawner) :
SComponent(COMPID::reSpawnable){
	init();
	_spawner = spawner;

}

void CompReSpawnable::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


void CompReSpawnable::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::enterDevClient:{
			SignalEnterDevClient* s = (SignalEnterDevClient*)data;
			this->sendFull(s->_clientId);
			break;
		}
		case SIGNAL::killed:{
			if(_spawner){
				MessageKilled* msg = new MessageKilled(_obj->getId());
				_obj->getProcessor()->sendMessage(_spawner, msg);
				_spawner = 0; //my task is done
			}
			break;
		}
		case SIGNAL::process:{

			break;
		}
	}
}

void CompReSpawnable::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::HeartBeatReq:{
			MessageHeartBeatRsp* msg = new MessageHeartBeatRsp(_obj->getId(), true);
			_obj->getProcessor()->sendMessage(data->_fromId, msg);
			break;
		}
	}
}


CompReSpawnable::~CompReSpawnable() {
}

