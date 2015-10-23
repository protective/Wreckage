
#include "CompPowerBase.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompPowerBase/CompPowerBaseSerial.h"


void CompPowerBase::acceptNetwork(SerialInputPayload* data){
	//cerr<<"CompPowerBase::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
		case SERIALINPUT::SerialInputCastPower :{
			break;
		}
		case SERIALINPUT::SerialIndputSetCompValue : {
			SerialIndputSetCompValue* d = (SerialIndputSetCompValue*)data;
			if(d->_compId == COMPID::powerBase){
				SerialCompPowerBase::setvalue(this, (SerialCompPowerBase::SerialSetField*)&d[1]);
				
			}
		
		}
	}

}

void CompPowerBase::sendFull(uint32_t clientId){
	//cerr<<"CompPowerBase::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompPowerBase::SerialSendFull* tmp = SerialCompPowerBase::allocSendFull(
			this->_obj->getId(),
			this->_name,
			this->_description,
			this->_programSource);
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

