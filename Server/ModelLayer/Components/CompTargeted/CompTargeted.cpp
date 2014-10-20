
#include "CompTargeted.h"

CompTargeted::CompTargeted() :
SComponent(COMPID::targeted){
	init();
}

CompTargeted::CompTargeted(const CompTargeted& orig) :
SComponent(COMPID::targeted){
	init();
}

void CompTargeted::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompTargeted::acceptMessage(MESSAGE::Enum type, Message* data){

}

void CompTargeted::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompTargeted::~CompTargeted() {
}

