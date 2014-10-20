
#include "CompPowerActivate.h"

CompPowerActivate::CompPowerActivate() :
SComponent(COMPID::powerActivate){
	init();
}

CompPowerActivate::CompPowerActivate(const CompPowerActivate& orig) :
SComponent(COMPID::powerActivate){
	init();
}

CompPowerActivate::CompPowerActivate(OBJID spawner) :
SComponent(COMPID::powerActivate){
	init();

}
void CompPowerActivate::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompPowerActivate::~CompPowerActivate() {
}

