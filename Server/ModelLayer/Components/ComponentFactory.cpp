/* 
 * File:   ComponentFactory.cpp
 * Author: karsten
 * 
 * Created on 16. oktober 2014, 20:51
 */

#include "ComponentFactory.h"
#include "CompSpawnNode/CompSpawnNode.h"
#include "CompReSpawnable/CompReSpawnable.h"

SComponent* createComponent(COMPID::Enum type, OBJID id, pqxx::connection& con){
	switch(type){
		case COMPID::spawnNode: {
			return new CompSpawnNode(id,con);
		}
		case COMPID::reSpawnable: {
			return new CompReSpawnable(id,con);
		}
		default:{
			cerr<<"ERROR ComponentFactory::createComponent component not known"<<endl;			
		}
	}
}

