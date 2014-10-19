
#include "CompReSpawnable.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"
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
		case SIGNAL::killed:{
			if(_spawner){
				//cerr<<"CompReSpawnable::acceptSignal SIGNAL::killed"<<endl;
				MessageKilled* msg = new MessageKilled(_obj->getId());
				_obj->getProcessor()->sendMessage(_spawner, msg);
				_spawner = 0; //my task is done
			}
			break;
		}
		case SIGNAL::process:{
			//cerr<<"CompReSpawnable::acceptSignal SIGNAL::process"<<endl;
			
			//cerr<<"obj "<<_obj->getId()<<" hp="<<_obj->getData(OBJDATA::hp)<<endl;
			//_obj->signal(SIGNAL::killed, NULL);
			break;
		}
	}
}

void CompReSpawnable::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::HeartBeatReq:{
			//cerr<<"obj "<<_obj->getId()<<" rec MESSAGE::HeartBeatReq send resp to "<<data->_fromId<<endl;
			MessageHeartBeatRsp* msg = new MessageHeartBeatRsp(_obj->getId());
			_obj->getProcessor()->sendMessage(data->_fromId, msg);
			break;
		}
	}
}


CompReSpawnable::~CompReSpawnable() {
}

