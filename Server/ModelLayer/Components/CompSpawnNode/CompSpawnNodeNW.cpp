
#include "CompSpawnNode.h"

CompSpawnNode::CompSpawnNode(SerialCompSpawnNode* sc, int32_t* size):
SComponent(COMPID::spawnNode){
	init();
	if(*size >= sizeof(SerialCompSpawnNode)){
		this->_spawn = sc->_spawn;
		this->_spawnTemplate = sc->_spawnTemplate;
		this->_spawnTime = sc->_spawnTime;
		*size = sizeof(SerialCompSpawnNode);
	}else{
		cerr<<"ERROR CompSpawnNode::CompSpawnNode invalid buffer size"<<endl;
		*size = 0;
	}
}
