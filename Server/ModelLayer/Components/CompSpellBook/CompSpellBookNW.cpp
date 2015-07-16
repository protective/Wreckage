
#include "CompSpellBook.h"
#include "../../../Processor/Processor.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../../Network/InputSerial.h"
#include "../../Messages/MessageActivatePowerOnTarget.h"
#include "../../Messages/MessagePowerStats.h"

#include "../../../NetworkLayer/Components/CompSpellBook/CompSpellBookSerial.h"



void CompSpellBook::acceptNetwork(SerialInputPayload* data){
	cerr<<"CompSpellBook::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
		case SERIALINPUT::SerialInputCastPower :{
			SerialInputCastPower* d = (SerialInputCastPower*)data;
			
			MessagePowerStats* msg = new MessagePowerStats(_obj->getId(),d->_target);
			//_loadedPowers[d->_power];
			cerr<<"send msg"<<endl;

			_obj->getProcessor()->sendMessage(d->_power, msg);
			break;
		}
	}

}


void CompSpellBook::sendFull(uint32_t clientId){
	cerr<<"CompSpellBook::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompSpellBook::SerialSendFull* tmp = SerialCompSpellBook::allocSendFull(
			this->_obj->getId());

	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}
