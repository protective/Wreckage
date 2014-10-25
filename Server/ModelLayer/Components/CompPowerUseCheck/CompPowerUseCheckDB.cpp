
#include "CompPowerUseCheck.h"

CompPowerUseCheck::CompPowerUseCheck(OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerUseCheck){
	init();
	
	
	_flags = COMPFLAGINIT;
}

void CompPowerUseCheck::dbSave(){

}

void CompPowerUseCheck::dbInit(){

}

void CompPowerUseCheck::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comppowerusecheck');");
	if(!r[0][0].as<bool>()){
		cerr<<"comppowerusecheck::dbInit comppowerusecheck do not exist create"<<endl;
		w.exec("create table comppowerusecheck (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
	w.exec("delete from comppowerusecheck where objid NOT IN (select objid from objs);");
	w.commit();
	
}

void CompPowerUseCheck::dbDelete(){

}
