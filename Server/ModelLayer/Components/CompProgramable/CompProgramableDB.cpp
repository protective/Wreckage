
#include "CompProgramable.h"

#include "../../../Processor/Processor.h"

CompProgramable::CompProgramable(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::programable, obj){

	init();
	pqxx::work w(con);
	stringstream s; 
	/*
	s<<"select name, description, source, sym, bin from CompPowerBase where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	if(r.size() != 1){
		cerr<<"ERROR CompPowerBase loadsize="<<r.size()<<endl;
		_name = "";
		_description = "";
	}else{
		_name = r[0][0].as<string>();
		_description = r[0][1].as<string>();
		_programSource = r[0][2].as<string>();
		_sym = r[0][3].as<string>();
		
		pqxx::binarystring blob( r[0][4] );
		INSTRUCTION* ptr = (INSTRUCTION*)blob.data();
		size_t len = blob.size();
		if(len > 0)
			_program = new wkl::Program(_name, wkl::PROGRAM(ptr,ptr + (len/sizeof(INSTRUCTION))));


	}
	*/
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompProgramable::dbSave(){
	if(_obj->getProcessor()){
		/*
		if(isInit()){
			
			_obj->getProcessor()->getDB().prepare(
				"update CompPowerBase set "
					"name= $2, "
					"description= $3, "
					"source= $4, "
					"sym= $5, "
					"bin= $6"
				"where objId = $1"
			);
			pqxx::work w(_obj->getProcessor()->getDB());
			if(_program){
				pqxx::binarystring blob( &(_program->program()[0]), _program->program().size() * sizeof(wkl::INSTRUCTION) );
				w.prepared()(_obj->getId())( _name )( _description )(_programSource)(_sym)(blob).exec();
			}else{
				pqxx::binarystring blob("");
				w.prepared()(_obj->getId())( _name )( _description )(_programSource)(_sym)(blob).exec();
			}
			w.commit();
		}else{
			dbInit();
		}
		*/
	}
}

void CompProgramable::dbInit(){
	if(!_obj){
		cerr<<"ERROR CompProgramable::init no obj"<<endl;
		return;
	}
	/*
	_obj->getProcessor()->getDB().prepare(
		"insert into CompPowerBase values($1,$2,$3,$4,$5,$6);"
	);
	pqxx::work w(_obj->getProcessor()->getDB());
		if(_program){
			pqxx::binarystring blob( &(_program->program()[0]), _program->program().size() * sizeof(wkl::INSTRUCTION) );
			w.prepared()(_obj->getId())( _name )( _description )(_programSource)(_sym)(blob).exec();
		}else{
			pqxx::binarystring blob("");
			w.prepared()(_obj->getId())( _name )( _description )(_programSource)("sym")(blob).exec();
		}
	w.commit();	
	*/
	_flags |= COMPFLAGINIT;
}

void CompProgramable::dbTableInit(pqxx::connection& con){
	/*
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comppowerbase');");
	if(!r[0][0].as<bool>()){
		cerr<<"comppowerbase::dbInit comppowerbase do not exist create"<<endl;
		w.exec("create table comppowerbase (objId BIGINT PRIMARY KEY, "
		"name TEXT, "
		"description TEXT, "
		"source TEXT, "
		"sym TEXT, "
		"bin BYTEA);");
		//w.commit();
	}
	w.exec("delete from comppowerbase where objid NOT IN (select objid from objs);");
	w.commit();
	*/
}

void CompProgramable::dbDelete(){

}
