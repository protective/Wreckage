/* 
 * File:   CompCaster.cpp
 * Author: karsten
 * 
 * Created on 14. oktober 2014, 22:35
 */

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

