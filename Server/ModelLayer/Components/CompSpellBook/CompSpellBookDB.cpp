
#include "CompSpellBook.h"
#include "../../../Processor/Processor.h"
#include "../../../Tasks/TaskCreateObj.h"

#include "../../Messages/MessageObjDeleted.h"
#include "../../Messages/MessageRequestRefObj.h"


CompSpellBook::CompSpellBook(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::spellbook){
	pqxx::work w(con);
	stringstream s; 
	s<<"select powerTemplateID from compspellbook_knownpowers where objId = "<<id<<"";
	pqxx::result r = w.exec(s);
	for (int i = 0; i < r.size(); i++) {
		
		OBJID templateId = r[i][0].as<OBJID>();
		if(!obj->isTemplate()){
			OBJID tmp = obj->getProcessor()->getFreeID();
			TaskCreateObj* task = new TaskCreateObj(tmp, templateId, false);
			task->addData(OBJDATA::owner, obj->getId());
			_loadedPowers.push_back(tmp);
			obj->getProcessor()->addTask(task);
		}else{
			_loadedPowers.push_back(templateId);
		}
		_knownPowers.push_back(templateId);
	}
	
	for (list<OBJID>::iterator it = _knownPowers.begin(); it != _knownPowers.end(); it++){
		networkControl->sendMessage(*it, new MessageRequestRefObj(obj->getId()));
	}
	
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
	init();
}

void CompSpellBook::dbSave(){
	if(_obj->getProcessor()){
		
		pqxx::work w(_obj->getProcessor()->getDB());
		stringstream s; 
		s<<"delete from compspellbook_knownpowers where objId = "
		<<_obj->getId()<< ";";
		w.exec(s);
		s.clear();
		for(list<OBJID>::iterator it = _knownPowers.begin();it!=_knownPowers.end();it++){
			s<<"insert into compspellbook_knownpowers values("
				<<_obj->getId()<<","
				<<*it<<")";
			w.exec(s);
			w.commit();
			s.clear();
		}
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

	pqxx::result r2 = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspellbook_knownpowers');");
	if(!r2[0][0].as<bool>()){
		cerr<<"compspellbook_knownpower::dbInit compspellbook_knownpower do not exist create"<<endl;
		w.exec("create table compspellbook_knownpowers (objId BIGINT, powerTemplateID BIGINT);");
		w.commit();
	}
	w.exec("delete from compspellbook where objid NOT IN (select objid from objs);");
	w.exec("delete from compspellbook_knownpowers where objid NOT IN (select objid from objs);");
	w.commit();
	
}

void CompSpellBook::dbDelete(){

}
