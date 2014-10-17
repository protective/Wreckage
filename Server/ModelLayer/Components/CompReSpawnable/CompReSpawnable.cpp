
#include "CompReSpawnable.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"
#include "../../Messages/MessageKilled.h"
CompReSpawnable::CompReSpawnable() :
SComponent(COMPID::reSpawnable){
	_spawner = 0;
}

CompReSpawnable::CompReSpawnable(const CompReSpawnable& orig) :
SComponent(COMPID::reSpawnable){
	_spawner = orig._spawner;
}

CompReSpawnable::CompReSpawnable(OBJID spawner) :
SComponent(COMPID::reSpawnable){
	_spawner = spawner;
}

void CompReSpawnable::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::killed:{
			if(_spawner){
				cerr<<"CompReSpawnable::acceptSignal SIGNAL::killed"<<endl;
				MessageKilled* msg = new MessageKilled(_obj->getId());
				_obj->getProcessor()->sendMessage(_spawner, msg);
				_spawner = 0; //my task is done
			}
			break;
		}
		case SIGNAL::process:{
			cerr<<"CompReSpawnable::acceptSignal SIGNAL::process"<<endl;
			_obj->signal(SIGNAL::killed, NULL);
			break;
		}
	}
}

CompReSpawnable::~CompReSpawnable() {
}

