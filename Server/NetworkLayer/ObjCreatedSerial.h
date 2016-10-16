/* 
 * File:   ObjCreatedSerial.h
 * Author: karsten
 *
 * Created on 16. oktober 2016, 15:17
 */

#ifndef OBJCREATEDSERIAL_H
#define	OBJCREATEDSERIAL_H

#include "../Network/Serialize.h"


namespace SerialEventObjCreated{

struct SerialObjCreated : public SerialData{
	OBJID _objId;
	uint32_t _creationRef;
}__attribute__((__packed__));

SerialObjCreated* alloc(OBJID objId, uint32_t _creationRef){
	size_t size = sizeof(SerialObjCreated);
	SerialObjCreated* s = (SerialObjCreated*)malloc(size);
	s->_type = SerialType::SerialObjCreated;
	s->_size = size;
	s->_objId = objId;
	s->_creationRef = _creationRef;
	return s;
};

}
	


#endif	/* OBJCREATEDSERIAL_H */

