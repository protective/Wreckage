
#include "CompPowerUseCheck.h"

CompPowerUseCheck::CompPowerUseCheck(OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerUseCheck){
	init();
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
}

void CompPowerUseCheck::dbDelete(){

}
