
#include "CompSpawnNode.h"

#include "../../../ModelLayer/SWorld.h"

#include "../../../Processor/Processor.h"

#include "../../../Tasks/TaskAddComponent.h"
#include "../../../Tasks/TaskCreateObj.h"

#include "../../Signals/SignalProcess.h"
#include "../../Messages/MessageHeartBeatReq.h"
#include "../../Messages/MessageHeartBeatRsp.h"

#include "../CompReSpawnable/CompReSpawnable.h"

CompSpawnNode::CompSpawnNode() :
SComponent(COMPID::spawnNode){
	init();
	_spawnTime = 0;
	_spawn = 0;
	_spawnTemplate = 0;
}

CompSpawnNode::CompSpawnNode(TIME spawnTime, OBJTPID spawnTemplate, OBJID spawn) :
SComponent(COMPID::spawnNode){
	init();
	_spawnTime = spawnTime;
	_spawn = spawn;
	_spawnTemplate = spawnTemplate;
}

CompSpawnNode::CompSpawnNode(const CompSpawnNode& orig) :
SComponent(COMPID::spawnNode){
	init();
	_spawnTime = orig._spawnTime;
	_spawn = orig._spawn;
	_spawnTemplate = orig._spawnTemplate;
}


void CompSpawnNode::init(){
	__timeout = 10000;
}

void CompSpawnNode::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::process:{
			
			if(__timeout < 5000 && _spawn){
				MessageHeartBeatReq* msg = new MessageHeartBeatReq(_obj->getId());
				_obj->getProcessor()->sendMessage(_spawn, msg);
			}
			if(_spawn == 0){
				if( world->getTime() > _spawnTime){
					
					OBJID id = _obj->getProcessor()->getFreeID();
					cerr<<"Spwan new unit id ="<<id<<endl;
					TaskCreateObj* task = new TaskCreateObj(id,1,true);
					CompReSpawnable* cmp = new CompReSpawnable(_obj->getId());
					if(!task->addComponent(cmp))
						delete cmp;
					_obj->getProcessor()->addTask(task);
					_spawn = id;
					__timeout = 10000;
					this->dbSave();
				}
			}
			SignalProcess* dataP = (SignalProcess*)data;
			if(dataP->_delta >= __timeout){
				__timeout = 0;
				_spawn = 0;
			}else{
				__timeout -= dataP->_delta;
			}
			break;
		}
	}
}

void CompSpawnNode::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::killed:{
			//cerr<<"CompSpawnNode::acceptMessage MESSAGE::killed"<<endl;
			
			if(data->_fromId == _spawn){
				//cerr<<"CompSpawnNode::acceptMessage ID matches"<<endl;			
			
			}
			break;
		}
		case MESSAGE::HeartBeatRsp:{
			//cerr<<"CompSpawnNode::acceptMessage MESSAGE::HeartBeatRsp"<<endl;
			//cerr<<"data->_fromId ="<<data->_fromId<<" _spawn="<<_spawn<<endl;
			if(data->_fromId == _spawn){
				__timeout = 10000;
			}
			break;
		}
	}
}


CompSpawnNode::~CompSpawnNode() {
}

