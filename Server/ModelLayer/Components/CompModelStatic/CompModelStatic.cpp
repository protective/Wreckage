
#include "CompModelStatic.h"

#include "../../Signals/SignalEnterClient.h"
#include "../../Signals/SignalExitClient.h"

CompModelStatic::CompModelStatic(SObj* obj) :
SComponent(COMPID::modelStatic, obj){
	init();
	_modelId = 0;
}

CompModelStatic::CompModelStatic(uint32_t modelId, SObj* obj) :
SComponent(COMPID::modelStatic, obj){
	init();
	_modelId = modelId;
}

CompModelStatic::CompModelStatic(const CompModelStatic& orig, SObj* obj) :
SComponent(COMPID::modelStatic, obj){
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

