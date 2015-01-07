
#include "CompPowerBase.h"

#include "../../../NetworkLayer/Components/CompPowerBase/CompPowerBaseSerial.h"

void CompPowerBase::acceptNetwork(SerialInputPayload* data){
	cerr<<"CompPowerBase::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
		case SERIALINPUT::SerialInputCastPower :{
			break;
		}
	}

}

void CompPowerBase::sendPowerFull(uint32_t clientId){
	cerr<<"CompModelStatic::sendPowerFull obj"<<_obj<<endl;
	if(_obj->getPos()){
		cerr<<_obj->getId()<<endl;
		//SerialPowerFull s(_obj->getId(),_obj->getPos(),_modelId);
		//networkControl->sendToC(clientId, &s, sizeof(s));
		cerr<<"send enter"<<endl;
	}else
		cerr<<"ERROR CompModelStatic::sendEnter no pos"<<endl;
}

