
#include <pqxx/transaction.hxx>
#include "CompSpawnNode.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"


CompSpawnNode::CompSpawnNode(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::spawnNode, obj){
	init();
	pqxx::work w(con);
	stringstream s; 
	s<<"select spawnid, spawnTime, spawnTemplate from CompSpawnNode where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	if(r.size() != 1){
		cerr<<"ERROR CompSpawnNode loadsize="<<r.size()<<endl;
		_spawn = 0;
		_spawnTime = 0;
		_spawnTemplate = 0;
	}else{
		_spawn = r[0][0].as<OBJID>();
		_spawnTime = r[0][1].as<TIME>();
		_spawnTemplate = r[0][2].as<OBJTPID>();
	}
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompSpawnNode::dbSave(){
	
	if(_obj->getProcessor()){
		if(isInit()){
			pqxx::work w(_obj->getProcessor()->getDB());
			stringstream s; 
			s<<"update CompSpawnNode set "
				"spawnid = "<<_spawn<<", "
				"spawnTime = "<<_spawnTime<<", "
				"spawnTemplate = "<<_spawnTemplate<<" "
				"where objId = "<<_obj->getId()<<"";
			w.exec(s);
			w.commit();
		}else{
			dbInit();
		}
		
	}
}

void CompSpawnNode::dbInit(){
	if(!_obj){
		cerr<<"ERROR CompSpawnNode::init no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"insert into CompSpawnNode values( "
		<<_obj->getId()<<", "
		<<_spawn<<", "
		<<_spawnTime<<", "
		<<_spawnTemplate<<");";
	w.exec(s);
	w.commit();
	_flags |= COMPFLAGINIT;
}

void CompSpawnNode::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspawnnode');");
	if(!r[0][0].as<bool>()){
		cerr<<"CompSpawnNode::dbInit CompSpawnNode do not exist create"<<endl;
		w.exec("create table compspawnnode (objId BIGINT PRIMARY KEY, spawnid BIGINT, spawnTime BIGINT, spawnTemplate BIGINT);");
		w.commit();
	}
	w.exec("delete from compspawnnode where objid NOT IN (select objid from objs);");
	w.commit();
}


void CompSpawnNode::dbDelete(){
	if(!_obj){
		cerr<<"ERROR CompSpawnNode::delete no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"delete from CompSpawnNode where "
		"objid = "<<_obj->getId()<<";";
	w.exec(s);
	w.commit();
	_flags &= ~COMPFLAGINIT;
}