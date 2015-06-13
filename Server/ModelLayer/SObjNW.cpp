
#include "SObj.h"

#include "../NetworkLayer/ObjSerial.h"
#include "../NetworkLayer/NetworkControler.h"

void SObj::sendall(uint32_t clientId){
	cerr<<"SObj::sendall obj "<<this->_id<<endl;
	uint32_t size = SerialObjAll::getMallocSize(this);
	char* tmp = (char*)malloc(size);
	SerialObjAll::pack(tmp, this, size);
	networkControl->sendToC(clientId, tmp, size);
	free(tmp);
}