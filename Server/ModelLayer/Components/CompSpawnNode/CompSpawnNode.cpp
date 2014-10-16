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

void CompSpawnNode::dbInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspawnnode');");
	cerr<<"hest>>"<<r[0][0].as<bool>()<<endl;
	if(!r[0][0].as<bool>()){
		cerr<<"CompSpawnNode::dbInit CompSpawnNode do not exist create"<<endl;
		w.exec("create table compspawnnode (objId BIGINT PRIMARY KEY, spawnid BIGINT, spawnTime BIGINT, spawnTemplate BIGINT);");
		w.commit();
	}
}

CompSpawnNode::CompSpawnNode(OBJID id, pqxx::connection& con) :
SComponent(COMPID::spawnNode){
	pqxx::work w(con);
	stringstream s; 
	s<<"select spawnid, spawnTime, spawnTemplate from CompSpawnNode where objId = "<<id<<";)";
	pqxx::result r = w.exec(s);
	if(r.size() != 1)
		cerr<<"ERROR CompSpawnNode loadsize="<<r.size()<<endl;

	_spawn = r[0][0].as<OBJID>();
	_spawnTime = r[0][1].as<TIME>();
	_spwanTemplate = r[0][2].as<OBJTPID>();

}

void CompSpawnNode::dbSave(){
	if(_obj->getProcessor()){
		pqxx::work w(_obj->getProcessor()->getDB());
		stringstream s; 
		s<<"update CompSpawnNode set "
			"spawnid = "<<_spawn<<", "
			"spawnTime = "<<_spawnTime<<", "
			"spawnTemplate = "<<_spwanTemplate<<", "
			"where objId = "<<_obj->getId()<<";)";
		w.exec(s);
		w.commit();		
	}
}

void CompSpawnNode::init(){
}

CompSpawnNode::~CompSpawnNode() {
}

