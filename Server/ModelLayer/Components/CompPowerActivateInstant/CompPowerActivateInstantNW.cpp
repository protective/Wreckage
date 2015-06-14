
#include "CompPowerActivateInstant.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompPowerActivateInstant/CompPowerActivateInstantSerial.h"

void CompPowerActivateInstant::sendFull(uint32_t clientId){
	cerr<<"CompTargeted::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompPowerActivateInstant::SerialSendFull* tmp = SerialCompPowerActivateInstant::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}
