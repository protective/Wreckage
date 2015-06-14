

#include "CompPowerUseCheck.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompPowerUseCheck/CompPowerUseCheckSerial.h"

void CompPowerUseCheck::sendFull(uint32_t clientId){
	cerr<<"CompPowerUseCheck::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompPowerUseCheck::SerialSendFull* tmp = SerialCompPowerUseCheck::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

