
#include <pqxx/transaction.hxx>
#include "CompPosition.h"

#include "../../../Processor/Processor.h"

CompPosition::CompPosition(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::position){
	init();
	/*
	pqxx::work w(con);
	stringstream s; 
	s<<"select modelid from CompPosition where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	if(r.size() != 1){
		cerr<<"ERROR CompPosition loadsize="<<r.size()<<endl;
		//_modelId = 0;
	}else{
		//_modelId = r[0][0].as<uint32_t>();
	}
	 * */
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompPosition::dbSave(){
	/*
	if(_obj->getProcessor()){
		if(isInit()){
			pqxx::work w(_obj->getProcessor()->getDB());
			stringstream s; 
			s<<"update CompPosition set "
				"modelId = "<<0<<" "
				"where objId = "<<_obj->getId()<<"";
			w.exec(s);
			w.commit();
		}else{
			dbInit();
		}
		
	}
	*/
}

void CompPosition::dbInit(){
	/*
	if(!_obj){
		cerr<<"ERROR CompPosition::init no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"insert into CompPosition values( "
		<<_obj->getId()<<", "
		<<0<<");";
	w.exec(s);
	w.commit();
	 * */
	_flags |= COMPFLAGINIT;
}

void CompPosition::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='Compposition');");
	if(!r[0][0].as<bool>()){
		cerr<<"CompPosition::dbInit CompPosition do not exist create"<<endl;
		w.exec("create table compposition (objId BIGINT PRIMARY KEY, modelId INT);");
		w.commit();
	}else{
		w.exec("delete from CompPosition where objid NOT IN (select objid from objs);");
		w.commit();
	}
}


void CompPosition::dbDelete(){
	if(!_obj){
		cerr<<"ERROR CompPosition::delete no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"delete from CompPosition where "
		"objid = "<<_obj->getId()<<";";
	w.exec(s);
	w.commit();
	_flags &= ~COMPFLAGINIT;
}