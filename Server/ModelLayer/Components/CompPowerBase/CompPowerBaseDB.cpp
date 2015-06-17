
#include "CompPowerBase.h"

#include "../../../Processor/Processor.h"

CompPowerBase::CompPowerBase(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerBase){
	init();
	pqxx::work w(con);
	stringstream s; 
	s<<"select name, description from CompPowerBase where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	if(r.size() != 1){
		cerr<<"ERROR CompPowerBase loadsize="<<r.size()<<endl;
		_name = "";
		_description = "";
	}else{
		_name = r[0][0].as<string>();
		_description = r[0][1].as<string>();
	}
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompPowerBase::dbSave(){
	if(_obj->getProcessor()){
		if(isInit()){
			pqxx::work w(_obj->getProcessor()->getDB());
			stringstream s; 
			s<<"update CompPowerBase set "
				"name='"<<_name<<"', "
				"description='"<<_description<<"' "
				"where objId = "<<_obj->getId()<<"";
			w.exec(s);
			w.commit();
		}else{
			dbInit();
		}
	}
}

void CompPowerBase::dbInit(){
	if(!_obj){
		cerr<<"ERROR CompPowerBase::init no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"insert into CompPowerBase values( "
		<<_obj->getId()<<", '"
		<<_name<<"', '"
		<<_description<<"');";
	w.exec(s);
	w.commit();
	_flags |= COMPFLAGINIT;
}

void CompPowerBase::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comppowerbase');");
	if(!r[0][0].as<bool>()){
		cerr<<"comppowerbase::dbInit comppowerbase do not exist create"<<endl;
		w.exec("create table comppowerbase (objId BIGINT PRIMARY KEY, name TEXT, description TEXT);");
		//w.commit();
	}
	w.exec("delete from comppowerbase where objid NOT IN (select objid from objs);");
	w.commit();
	
}

void CompPowerBase::dbDelete(){

}
