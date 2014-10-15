
#include "CompCaster.h"

CompCaster::CompCaster() :
SComponent(COMPID::caster){
	
}

void CompCaster::acceptSignal(SIGNAL::Enum type, Signal* data){

}
void CompCaster::init(){
	_obj->subscribeSignal(SIGNAL::castTarget,this);
}

CompCaster::~CompCaster() {
}

