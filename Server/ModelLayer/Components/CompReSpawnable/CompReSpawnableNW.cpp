
#include "CompReSpawnable.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompReSpawnable/CompReSpawnableSerial.h"

void CompReSpawnable::sendFull(uint32_t clientId){
	//cerr<<"CompReSpawnable::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompReSpawnable::SerialSendFull* tmp = SerialCompReSpawnable::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}


