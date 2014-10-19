
#include <pqxx/transaction.hxx>
#include "CompReSpawnable.h"
#include "../../../Processor/Processor.h"
#include "../../Signals/SignalProcess.h"

CompReSpawnable::CompReSpawnable(OBJID id, pqxx::connection& con) :
SComponent(COMPID::spawnNode){
	init();
	pqxx::work w(con);
	stringstream s; 
	s<<"select spawner from CompReSpawnable where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	if(r.size() != 1){
		cerr<<"ERROR CompReSpawnable loadsize="<<r.size()<<endl;
		_spawner = 0;
	}else{
		_spawner = r[0][0].as<OBJID>();
	}


	_flags = COMPFLAGINIT;
}

void CompReSpawnable::dbSave(){
	
	if(_obj->getProcessor()){
		if(isInit()){
			pqxx::work w(_obj->getProcessor()->getDB());
			stringstream s; 
			s<<"update CompSpawnNode set "
				"spawnid = "<<_spawner<<" "
				"where objId = "<<_obj->getId()<<"";
			w.exec(s);
			w.commit();
		}else{
			dbInit();
		}
	}
}

void CompReSpawnable::dbInit(){
	if(!_obj){
		cerr<<"ERROR CompReSpawnable::init no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"insert into CompReSpawnable values( "
		<<_obj->getId()<<", "
		<<_spawner<<");";
	w.exec(s);
	w.commit();
	_flags |= COMPFLAGINIT;
}

void CompReSpawnable::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comprespawnable');");
	if(!r[0][0].as<bool>()){
		cerr<<"CompReSpawnable::dbInit CompReSpawnable do not exist create"<<endl;
		w.exec("create table comprespawnable (objId BIGINT PRIMARY KEY, spawner BIGINT);");
		w.commit();
	}
}

void CompReSpawnable::dbDelete(){
	if(!_obj){
		cerr<<"ERROR CompReSpawnable::delete no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"delete from CompReSpawnable where "
		"objid = "<<_obj->getId()<<";";
	w.exec(s);
	w.commit();
	_flags &= ~COMPFLAGINIT;
}