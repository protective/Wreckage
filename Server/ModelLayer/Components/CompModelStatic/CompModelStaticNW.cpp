
#include "CompModelStatic.h"
#include "../../../Processor/Processor.h"

#include "../../../NetworkLayer/Components/CompModelStatic/CompModelStaticSerial.h"
#include "../../../NetworkLayer/NetworkControler.h"

void CompModelStatic::sendEnter(uint32_t clientId){
	cerr<<"CompModelStatic::sendEnter obj"<<_obj<<endl;
	if(_obj->getPos()){
		SerialObjEnter s(_obj->getId(),_obj->getPos(),_modelId);
		networkControl->sendToC(clientId, &s, sizeof(s));
		cerr<<"send enter"<<endl;
	}else
		cerr<<"ERROR CompModelStatic::sendEnter no pos"<<endl;
}
void CompModelStatic::sendExit(uint32_t clientId){
	if(_obj->getPos()){
		SerialObjExit s(_obj->getId(), _obj->getPos(), 1000); //TODO fix fadetimer
		networkControl->sendToC(clientId, &s, sizeof(s));
	}else
		cerr<<"ERROR CompModelStatic::sendExit no pos"<<endl;

}