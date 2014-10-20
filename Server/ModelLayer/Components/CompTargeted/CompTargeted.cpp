
#include "CompTargeted.h"

CompTargeted::CompTargeted() :
SComponent(COMPID::targeted){
	init();
}

CompTargeted::CompTargeted(const CompTargeted& orig) :
SComponent(COMPID::targeted){
	init();
}

CompTargeted::CompTargeted(OBJID spawner) :
SComponent(COMPID::powerDealDamage){
	init();

}
void CompTargeted::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompTargeted::~CompTargeted() {
}

