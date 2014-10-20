
#include "CompPowerActivateTimed.h"

CompPowerActivateTimed::CompPowerActivateTimed(OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerActivateTimed){
	init();
}

void CompPowerActivateTimed::dbSave(){

}

void CompPowerActivateTimed::dbInit(){

}

void CompPowerActivateTimed::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comppoweractivatetimed');");
	if(!r[0][0].as<bool>()){
		cerr<<"comppoweractivatetimed::dbInit comppoweractivatetimed do not exist create"<<endl;
		w.exec("create table comppoweractivatetimed (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
}

void CompPowerActivateTimed::dbDelete(){

}
