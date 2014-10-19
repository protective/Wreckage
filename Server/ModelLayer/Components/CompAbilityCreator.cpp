/* 
 * File:   CompAbilityCreator.cpp
 * Author: karsten
 * 
 * Created on 15. oktober 2014, 20:06
 */

#include "CompAbilityCreator.h"

CompAbilityCreator::CompAbilityCreator() :
SComponent(COMPID::abilityCreator){
	
}

CompAbilityCreator::CompAbilityCreator(const CompAbilityCreator& orig) :
SComponent(COMPID::abilityCreator){
	
}

void CompAbilityCreator::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompAbilityCreator::init(){
}


CompAbilityCreator::~CompAbilityCreator() {
}

