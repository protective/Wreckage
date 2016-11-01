
#include "CompSpawnNode.h"

#include "../../../ModelLayer/SWorld.h"

#include "../../../Processor/Processor.h"

#include "../../../Tasks/TaskAddComponent.h"
#include "../../../Tasks/TaskCreateObj.h"

#include "../../Signals/SignalProcess.h"
#include "../../Messages/MessageHeartBeatReq.h"
#include "../../Messages/MessageHeartBeatRsp.h"
#include "../../Messages/MessageSystemBroadcast.h"

#include "../CompReSpawnable/CompReSpawnable.h"

CompSpawnNode::CompSpawnNode(SObj* obj) :
SComponent(COMPID::spawnNode, obj){
	init();
	_spawnTime = 0;
	_spawn = 0;
	_spawnTemplate = 0;
}

CompSpawnNode::CompSpawnNode(TIME spawnTime, OBJTPID spawnTemplate, OBJID spawn, SObj* obj) :
SComponent(COMPID::spawnNode, obj){
	init();
	_spawnTime = spawnTime;
	_spawn = spawn;
	_spawnTemplate = spawnTemplate;
}

CompSpawnNode::CompSpawnNode(const CompSpawnNode& orig, SObj* obj) :
SComponent(COMPID::spawnNode, obj){
	init();
	_spawnTime = orig._spawnTime;
	_spawn = orig._spawn;
	_spawnTemplate = orig._spawnTemplate;
}


void CompSpawnNode::init(){
	__initDone = false;
}

void CompSpawnNode::acceptSignal(SIGNAL::Enum type, Signal* data){
	switch(type){
		case SIGNAL::process:{		

		}
	}
}

void CompSpawnNode::acceptMessage(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::systemBroadcast: {
			MessageSystemBroadcast* msg = (MessageSystemBroadcast*)data;
			
			
			if (msg->_message == MessageSystemBroadcast::dbloadObjComplete){
				if(_spawn && __initDone == false) {
					MessageHeartBeatReq* msg = new MessageHeartBeatReq(_obj->getId());
					networkControl->sendMessage(_spawn, msg);
					//_obj->getProcessor()->sendMessage(_spawn, msg);
					__initDone = true;
				}else if(_spawn == 0){
					spawn(_spawnTime);
				}
			}
			break;
		}
		case MESSAGE::killed:{
			//cerr<<"CompSpawnNode::acceptMessage MESSAGE::killed"<<endl;
			
			if(data->_fromId == _spawn){		
				spawn(_spawnTime);
			}
			break;
		}
		case MESSAGE::HeartBeatRsp:{
			MessageHeartBeatRsp* msg = (MessageHeartBeatRsp*)data;
			if(msg->_fromId == _spawn && msg->_alive == false){
				spawn(0);
			}
			break;
		}
	}
}

void CompSpawnNode::spawn(TIME spawnTime){
	_spawn = 0;
	/*
	 * TODO REIMPLEMENT THIS IS BROKEN
	if(_obj->getPos()){
		OBJID id = _obj->getProcessor()->getFreeID();
		cerr<<"Spwan new unit id ="<<id<<" in "<<spawnTime<<" ms"<<endl;
		TaskCreateObj* task = new TaskCreateObj(id,1,true, spawnTime);
		CompReSpawnable* cmp = new CompReSpawnable(_obj->getId());
		if(!task->addComponent(cmp))
			delete cmp;

		task->addPos(new SPos(*(_obj->getPos())));
		_obj->getProcessor()->addTask(task);
		_spawn = id;
	}else
		cerr<<"ERROR CompSpawnNode no pos"<<endl;
	this->dbSave();
	 * */
}

CompSpawnNode::~CompSpawnNode() {
}

