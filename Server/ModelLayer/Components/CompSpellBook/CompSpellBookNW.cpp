
#include "CompSpellBook.h"
#include "../../../Processor/Processor.h"

#include "../../../../Network/InputSerial.h"
#include "../../Messages/MessageActivatePowerOnTarget.h"

void CompSpellBook::acceptNetwork(SerialInputPayload* data){
	cerr<<"CompSpellBook::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
		case SERIALINPUT::SerialInputCastPower :{
			SerialInputCastPower* d = (SerialInputCastPower*)data;
			MessageActivatePowerOnTarget* msg = new MessageActivatePowerOnTarget(_obj->getId(),d->_target);
			_loadedPowers[d->_power];
			cerr<<"send msg"<<endl;
			_obj->getProcessor()->sendMessage(d->_power, msg);
			break;
		}
	}

}