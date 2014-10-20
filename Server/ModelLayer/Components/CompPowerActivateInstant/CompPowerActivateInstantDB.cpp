
#include "CompPowerActivateInstant.h"


CompPowerActivateInstant::CompPowerActivateInstant(OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerActivateInstant){
	init();
}

void CompPowerActivateInstant::dbSave(){

}

void CompPowerActivateInstant::dbInit(){

}

void CompPowerActivateInstant::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comppoweractivateinstant');");
	if(!r[0][0].as<bool>()){
		cerr<<"comppoweractivateinstant::dbInit comppoweractivateinstant do not exist create"<<endl;
		w.exec("create table comppoweractivateinstant (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
}

void CompPowerActivateInstant::dbDelete(){

}