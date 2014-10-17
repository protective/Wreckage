
#include "CompReSpawnable.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"

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
			//SignalProcess* dataP;
			
		}
	}
}

CompReSpawnable::~CompReSpawnable() {
}

