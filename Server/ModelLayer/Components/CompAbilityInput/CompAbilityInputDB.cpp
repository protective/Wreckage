
#include "CompAbilityInput.h"

CompAbilityInput::CompAbilityInput(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::abilityInput, obj){
	init();
	
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompAbilityInput::dbSave(){

}

void CompAbilityInput::dbInit(){

}

void CompAbilityInput::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compabilityinput');");
	if(!r[0][0].as<bool>()){
		cerr<<"compabilityinput::dbInit compabilityinput do not exist create"<<endl;
		w.exec("create table compabilityinput (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
	w.exec("delete from compabilityinput where objid NOT IN (select objid from objs);");
	w.commit();
}

void CompAbilityInput::dbDelete(){

}

