
#include "CompProgramable.h"

#include "../../../NetworkLayer/NetworkControler.h"

#include "../../../NetworkLayer/Components/CompProgramable/CompProgramable.h"


void CompProgramable::acceptNetwork(SerialInputPayload* data){
	//cerr<<"CompProgramable::acceptNetwork type="<<data->_type<<endl;
	switch(data->_type) {
	}

}

void CompProgramable::sendFull(uint32_t clientId){
	//cerr<<"CompProgramable::sendFull obj "<<this->_obj->getId()<<endl;
	SerialCompProgramable::SerialSendFull* tmp = SerialCompProgramable::allocSendFull(
			this->_obj->getId());
	
	networkControl->sendToC(clientId, tmp, tmp->_size);
	free(tmp);
}

