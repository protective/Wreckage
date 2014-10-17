
#include "CompSpawnNode.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"

CompSpawnNode::CompSpawnNode() :
SComponent(COMPID::spawnNode){
}

CompSpawnNode::CompSpawnNode(TIME spawnTime, OBJTPID spwanTemplate, OBJID spawn) :
SComponent(COMPID::spawnNode){
	_spawnTime = spawnTime;
	_spawn = spawn;
	_spwanTemplate = spwanTemplate;
}


CompSpawnNode::CompSpawnNode(const CompSpawnNode& orig) :
SComponent(COMPID::spawnNode){
}

void CompSpawnNode::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::process:{
			SignalProcess* dataP;
			_spawnTime -= dataP->_delta;
		}
	}
}



CompSpawnNode::~CompSpawnNode() {
}

