
#include "CompPowerBase.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompPowerBase/CompPowerBaseSerial.h"


void CompPowerBase::acceptNetwork(SerialInputPayload* data){
	cerr<<"CompPowerBase::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
		case SERIALINPUT::SerialInputCastPower :{
			break;
		}
	}

}

void CompPowerBase::sendFull(uint32_t clientId){
	cerr<<"SObj::sendall obj "<<this->_obj->getId()<<endl;
	SerialCompPowerBase::SerialSendFull* tmp = SerialCompPowerBase::allocSendFull(
			this->_obj->getId(),
			this->_name,
			this->_description);
	
	networkControl->sendToC(clientId, &tmp, tmp->_size);
	free(tmp);
}

