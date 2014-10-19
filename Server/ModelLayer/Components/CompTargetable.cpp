
#include "CompTargetable.h"

CompTargetable::CompTargetable() :
SComponent(COMPID::targetable){
	
}

CompTargetable::CompTargetable(const CompTargetable& orig) :
SComponent(COMPID::targetable){

}

void CompTargetable::acceptSignal(SIGNAL::Enum type, Signal* data){

}
void CompTargetable::init(){
}

CompTargetable::~CompTargetable() {
}

