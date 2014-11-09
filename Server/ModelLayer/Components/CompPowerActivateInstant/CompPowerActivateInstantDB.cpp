
#include "CompPowerActivateInstant.h"


CompPowerActivateInstant::CompPowerActivateInstant(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerActivateInstant){
	init();
	
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
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
	w.exec("delete from comppoweractivateinstant where objid NOT IN (select objid from objs);");
	w.commit();
}

void CompPowerActivateInstant::dbDelete(){

}