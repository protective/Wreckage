
#include "CompModelStatic.h"

CompModelStatic::CompModelStatic() :
SComponent(COMPID::modelStatic){
	init();
	_modelId = 0;
}

CompModelStatic::CompModelStatic(uint32_t modelId) :
SComponent(COMPID::modelStatic){
	init();
	_modelId = modelId;
}

CompModelStatic::CompModelStatic(const CompModelStatic& orig) :
SComponent(COMPID::modelStatic){
	init();
	_modelId = orig._modelId;
}


void CompModelStatic::init(){
}

void CompModelStatic::acceptSignal(SIGNAL::Enum type, Signal* data){

}

void CompModelStatic::acceptMessage(MESSAGE::Enum type, Message* data){
	
}


CompModelStatic::~CompModelStatic() {
}

