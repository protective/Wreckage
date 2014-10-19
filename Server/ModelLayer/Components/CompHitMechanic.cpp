
#include "CompHitMechanic.h"

CompHitMechanic::CompHitMechanic() :
SComponent(COMPID::hitMechanic){
}

CompHitMechanic::CompHitMechanic(const CompHitMechanic& orig) :
SComponent(COMPID::hitMechanic){
}

void CompHitMechanic::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompHitMechanic::init(){
}

CompHitMechanic::~CompHitMechanic() {
}

