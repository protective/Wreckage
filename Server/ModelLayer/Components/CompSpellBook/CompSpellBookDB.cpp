
#include "CompSpellBook.h"
#include "../../../Processor/Processor.h"
#include "../../../Tasks/TaskCreateObj.h"

#include "../../Messages/MessageObjDeleted.h"
#include "../../Messages/MessageRequestRefObj.h"


CompSpellBook::CompSpellBook(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::spellbook, obj){
	pqxx::work w(con);
	stringstream s; 
	s<<"select powerTemplateID from compspellbook_powers where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	w.commit();
	for (int i = 0; i < r.size(); i++) {
		
		OBJID templateId = r[i][0].as<OBJID>();
		this->addPower(templateId);
	}

	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
	init();
}

void CompSpellBook::dbSave(){
	if(_obj->getProcessor()){
		
		pqxx::work w(_obj->getProcessor()->getDB());
		stringstream s; 
		s<<"delete from compspellbook_powers where objId = "
		<<_obj->getId()<< ";";
		w.exec(s);
		s.clear();
		for(auto& it: _powers){
			s<<"insert into compspellbook_powers values("
				<<_obj->getId()<<","
				<<it.first<<");";
			w.exec(s);
			
			s.clear();
		}
		w.commit();
		if(!isInit()){
			dbInit();
		}
		
	}
}

void CompSpellBook::dbInit(){
	if(!_obj){
		cerr<<"ERROR CompSpawnNode::init no obj"<<endl;
		return;
	}		
	_flags |= COMPFLAGINIT;
}

void CompSpellBook::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspellbook');");
	if(!r[0][0].as<bool>()){
		cerr<<"compspellbook::dbInit compspellbook do not exist create"<<endl;
		w.exec("create table compspellbook (objId BIGINT PRIMARY KEY);");
		w.commit();
	}

	pqxx::result r2 = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspellbook_powers');");
	if(!r2[0][0].as<bool>()){
		cerr<<"compspellbook_knownpower::dbInit compspellbook_power do not exist create"<<endl;
		w.exec("create table compspellbook_powers (objId BIGINT, powerTemplateID BIGINT);");
		w.commit();
	}
	w.exec("delete from compspellbook where objid NOT IN (select objid from objs);");
	w.exec("delete from compspellbook_powers where objid NOT IN (select objid from objs);");
	w.commit();
	
}

void CompSpellBook::dbDelete(){

}
