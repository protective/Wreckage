

#include "CompTargeted.h"

CompTargeted::CompTargeted(OBJID id, pqxx::connection& con) :
SComponent(COMPID::targeted){
	init();
}

void CompTargeted::dbSave(){

}

void CompTargeted::dbInit(){

}

void CompTargeted::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comptargeted');");
	if(!r[0][0].as<bool>()){
		cerr<<"comptargeted::dbInit comptargeted do not exist create"<<endl;
		w.exec("create table comptargeted (objId BIGINT PRIMARY KEY);");
		w.commit();
	}
}

void CompTargeted::dbDelete(){

}

