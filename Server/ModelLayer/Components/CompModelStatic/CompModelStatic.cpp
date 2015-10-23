
#include "CompModelStatic.h"

#include "../../Signals/SignalEnterClient.h"
#include "../../Signals/SignalExitClient.h"

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
	
	switch(type){
		case SIGNAL::enterClient:{
			//cerr<<"signal enter"<<endl;
			SignalEnterClient* s = (SignalEnterClient*)data;
			sendEnter(s->_clientId);
			break;
		}
		case SIGNAL::exitClient:{
			SignalExitClient* s = (SignalExitClient*)data;
			sendEnter(s->_clientId);
			break;
		}
	}
}

void CompModelStatic::acceptMessage(MESSAGE::Enum type, Message* data){
	
}


CompModelStatic::~CompModelStatic() {
}

