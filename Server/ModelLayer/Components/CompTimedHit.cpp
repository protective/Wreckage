
#include "CompTimedHit.h"

CompTimedHit::CompTimedHit() :
SComponent(COMPID::timedHit){
	
}

CompTimedHit::CompTimedHit(const CompTimedHit& orig) :
SComponent(COMPID::timedHit){

}


void CompTimedHit::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompTimedHit::init(){
}

CompTimedHit::~CompTimedHit() {
}

