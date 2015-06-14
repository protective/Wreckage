
#include "CompPowerDealDamage.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompPowerDealDamage/CompPowerDealDamageSerial.h"

void CompPowerDealDamage::sendFull(uint32_t clientId){
	cerr<<"CompPowerDealDamage::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompPowerDealDamage::SerialSendFull* tmp = SerialCompPowerDealDamage::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

