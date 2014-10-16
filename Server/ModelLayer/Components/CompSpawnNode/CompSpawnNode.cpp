/* 
 * File:   CompSpawnNode.cpp
 * Author: karsten
 * 
 * Created on 16. oktober 2014, 18:22
 */

#include <pqxx/transaction.hxx>

#include "CompSpawnNode.h"
#include "../../../Processor/Processor.h"

#include "../../Signals/SignalProcess.h"

CompSpawnNode::CompSpawnNode() :
SComponent(COMPID::spawnNode){
}
CompSpawnNode::CompSpawnNode(const CompSpawnNode& orig) :
SComponent(COMPID::spawnNode){
}

CompSpawnNode::CompSpawnNode(pqxx::connection& con) :
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

void CompSpawnNode::dbInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspawnnode');");
	cerr<<"hest>>"<<r[0][0].as<bool>()<<endl;
	if(!r[0][0].as<bool>()){
		cerr<<"CompSpawnNode::dbInit CompSpawnNode do not exist create"<<endl;
		w.exec("create table compspawnnode (objId BIGINT PRIMARY KEY, spawnid BIGINT, spawnTemplate BIGINT, spawnTime BIGINT );");
		w.commit();
	}
}

void CompSpawnNode::dbSave(){
	if(_obj->getProcessor()){
		pqxx::work w(_obj->getProcessor()->getDB());
		stringstream s; 
		s<<"update CompSpawnNode set spawnid = "<<_spawn<<", spawnTime = "<<_spawnTime<<" where objId = "<<_obj->getId()<<";)";
		w.exec(s);
		w.commit();		
	}
}

void CompSpawnNode::init(){
}

CompSpawnNode::~CompSpawnNode() {
}

