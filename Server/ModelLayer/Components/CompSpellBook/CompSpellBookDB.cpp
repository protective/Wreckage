
#include "CompSpellBook.h"

CompSpellBook::CompSpellBook(OBJID id, pqxx::connection& con) :
SComponent(COMPID::spellbook){
	init();
}

void CompSpellBook::dbSave(){

}

void CompSpellBook::dbInit(){

}

void CompSpellBook::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compspellbook');");
	if(!r[0][0].as<bool>()){
		cerr<<"compspellbook::dbInit compspellbook do not exist create"<<endl;
		w.exec("create table compspellbook (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
}

void CompSpellBook::dbDelete(){

}
