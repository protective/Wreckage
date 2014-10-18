
#include "CompSpawnNode.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"

CompSpawnNode::CompSpawnNode() :
SComponent(COMPID::spawnNode){
	init();
	_spawnTime = 0;
	_spawn = 0;
	_spwanTemplate = 0;
}

CompSpawnNode::CompSpawnNode(TIME spawnTime, OBJTPID spwanTemplate, OBJID spawn) :
SComponent(COMPID::spawnNode){
	init();
	_spawnTime = spawnTime;
	_spawn = spawn;
	_spwanTemplate = spwanTemplate;
}

CompSpawnNode::CompSpawnNode(const CompSpawnNode& orig) :
SComponent(COMPID::spawnNode){
	init();
	_spawnTime = orig._spawnTime;
	_spawn = orig._spawn;
	_spwanTemplate = orig._spwanTemplate;
}


void CompSpawnNode::init(){

}

void CompSpawnNode::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::process:{
			SignalProcess* dataP;
			_spawnTime -= dataP->_delta;
			break;
		}
	}
}

void CompSpawnNode::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::killed:{
			cerr<<"CompSpawnNode::acceptMessage MESSAGE::killed"<<endl;
			
			if(data->_fromId == _spawn){
				cerr<<"CompSpawnNode::acceptMessage ID matches"<<endl;			
			
			}
			break;
		}
	}
}


CompSpawnNode::~CompSpawnNode() {
}

