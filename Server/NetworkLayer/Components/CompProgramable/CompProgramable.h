
#ifndef COMPPROGRAMABLESERIAL_H
#define	COMPPROGRAMABLESERIAL_H

#include "../CompSerialize.h"
#include <sstream>

namespace SerialCompProgramable{
	enum Enum{
		Invalid = 0,
		SendFull = 1,
	};

struct SerialSetField {
	enum Enum {
		Invalid = 0
	};
	uint16_t _field;
}__attribute__((__packed__));

struct SerialSetString : public SerialSetField {
	uint32_t _len;
	char _text[1];
}__attribute__((__packed__));

void setvalue(CompProgramable* comp, SerialSetField* msg){
	switch((SerialSetField::Enum)msg->_field){
	
	}
}


struct SerialSendFull : public SerialComp{
	SerialSendFull(OBJID objId):
		SerialComp(objId, COMPID::programable, (uint32_t)SendFull, sizeof(SerialSendFull)){}
	
}__attribute__((__packed__));

SerialSendFull* allocSendFull(OBJID objId){

	size_t size = sizeof(SerialSendFull);
	SerialSendFull* s = (SerialSendFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::programable;
	s->op = (uint32_t)SerialCompProgramable::SendFull;
	
	return s;
}

}
#endif	/* COMPPROGRAMABLESERIAL_H */

