/* 
 * File:   CompAbilityInput.cpp
 * Author: karsten
 * 
 * Created on 19. oktober 2014, 19:35
 */

#include "CompAbilityInput.h"

CompAbilityInput::CompAbilityInput() :
SComponent(COMPID::abilityInput){
	init();
}

CompAbilityInput::CompAbilityInput(const CompAbilityInput& orig) :
SComponent(COMPID::abilityInput){
	init();

}

void CompAbilityInput::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompAbilityInput::acceptMessage(MESSAGE::Enum type, Message* data){

}

void CompAbilityInput::init(){
	_objDataAcces.push_back(OBJDATA::hp);
	_objDataAcces.push_back(OBJDATA::maxhp);
}


CompAbilityInput::~CompAbilityInput() {
}

