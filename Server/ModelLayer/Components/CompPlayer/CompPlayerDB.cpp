
#include "CompPlayer.h"

CompPlayer::CompPlayer(SObj* obj, OBJID id, pqxx::connection& con) :
SComponent(COMPID::player){
	init();
	
	if(obj->getId() == id)
		_flags = COMPFLAGINIT;
}

void CompPlayer::dbSave(){

}

void CompPlayer::dbInit(){

}

void CompPlayer::dbTableInit(pqxx::connection& con){
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='compplayer');");
	if(!r[0][0].as<bool>()){
		cerr<<"compplayer::dbInit compplayer do not exist create"<<endl;
		w.exec("create table compplayer (objId BIGINT PRIMARY KEY);");
		w.commit();
	}else{
		w.exec("delete from compplayer where objid NOT IN (select objid from objs);");
		w.commit();
	}
}

void CompPlayer::dbDelete(){

}

