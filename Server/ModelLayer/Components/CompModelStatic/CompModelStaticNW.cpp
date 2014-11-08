
#include "CompModelStatic.h"
#include "../../../Processor/Processor.h"

#include "../../../NetworkLayer/Components/CompModelStatic/CompModelStaticSerial.h"
#include "../../../NetworkLayer/NetworkControler.h"

void CompModelStatic::sendEnter(uint32_t clientId){
	
	SerialObjEnter s(_obj->getId(),_modelId);
	networkControl->sendToC(clientId, &s, sizeof(s));
}
void CompModelStatic::sendExit(uint32_t clientId){
	SerialObjExit s(_obj->getId(),1000); //TODO fix fadetimer
	networkControl->sendToC(clientId, &s, sizeof(s));

}