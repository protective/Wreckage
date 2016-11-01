
#include <pqxx/transaction.hxx>
#include "CompModelStatic.h"

#include "../../../Processor/Processor.h"

CompModelStatic::CompModelStatic(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::modelStatic, obj){
	init();
	pqxx::work w(con);
	stringstream s; 
	s<<"select modelid from CompModelStatic where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	if(r.size() != 1){
		cerr<<"ERROR CompModelStatic loadsize="<<r.size()<<endl;
		_modelId = 0;
	}else{
		_modelId = r[0][0].as<uint32_t>();
	}
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompModelStatic::dbSave(){
	
	if(_obj->getProcessor()){
		if(isInit()){
			pqxx::work w(_obj->getProcessor()->getDB());
			stringstream s; 
			s<<"update CompModelStatic set "
				"modelId = "<<_modelId<<" "
				"where objId = "<<_obj->getId()<<"";
			w.exec(s);
			w.commit();
		}else{
			dbInit();
		}
		
	}
}

void CompModelStatic::dbInit(){
	if(!_obj){
		cerr<<"ERROR CompModelStatic::init no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"insert into CompModelStatic values( "
		<<_obj->getId()<<", "
		<<_modelId<<");";
	w.exec(s);
	w.commit();
	_flags |= COMPFLAGINIT;
}

void CompModelStatic::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compmodelstatic');");
	if(!r[0][0].as<bool>()){
		cerr<<"CompModelStatic::dbInit CompModelStatic do not exist create"<<endl;
		w.exec("create table CompModelStatic (objId BIGINT PRIMARY KEY, modelId INT);");
		w.commit();
	}else{
		w.exec("delete from CompModelStatic where objid NOT IN (select objid from objs);");
		w.commit();
	}
}


void CompModelStatic::dbDelete(){
	if(!_obj){
		cerr<<"ERROR CompModelStatic::delete no obj"<<endl;
		return;
	}
	pqxx::work w(_obj->getProcessor()->getDB());
	stringstream s; 
	s<<"delete from CompModelStatic where "
		"objid = "<<_obj->getId()<<";";
	w.exec(s);
	w.commit();
	_flags &= ~COMPFLAGINIT;
}