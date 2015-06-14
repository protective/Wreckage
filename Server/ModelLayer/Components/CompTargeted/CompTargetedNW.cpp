
#include "CompTargeted.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompTargeted/CompTargetedSerial.h"

void CompTargeted::sendFull(uint32_t clientId){
	cerr<<"CompTargeted::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompTargeted::SerialSendFull* tmp = SerialCompTargeted::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

