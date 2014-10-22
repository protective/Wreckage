
#include "CompPowerDealDamage.h"

CompPowerDealDamage::CompPowerDealDamage(OBJID id, pqxx::connection& con) :
SComponent(COMPID::powerDealDamage){
	init();
}

void CompPowerDealDamage::dbSave(){

}

void CompPowerDealDamage::dbInit(){

}

void CompPowerDealDamage::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comppowerdealdamage');");
	if(!r[0][0].as<bool>()){
		cerr<<"comppowerdealdamage::dbInit comppowerdealdamage do not exist create"<<endl;
		w.exec("create table comppowerdealdamage (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
	w.exec("delete from comppowerdealdamage where objid NOT IN (select objid from objs);");
	w.commit();
}

void CompPowerDealDamage::dbDelete(){

}

