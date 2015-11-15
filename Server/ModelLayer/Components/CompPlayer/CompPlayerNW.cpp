
#include "CompPlayer.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompPlayer/CompPlayerSerial.h"

void CompPlayer::sendFull(uint32_t clientId){
	//cerr<<"CompPowerDealDamage::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompPlayer::SerialSendFull* tmp = SerialCompPlayer::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

