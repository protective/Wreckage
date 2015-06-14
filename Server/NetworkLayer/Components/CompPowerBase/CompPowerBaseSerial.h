
#ifndef COMPPOWERBASESERIAL_H
#define	COMPPOWERBASESERIAL_H

#include "../CompSerialize.h"


namespace SerialCompPowerBase{
	enum Enum{
		Invalid = 0,
		SendFull = 1,
		ObjExit  = 2,
	};

struct SerialSendFull : public SerialComp{
	SerialSendFull(OBJID objId, string name, string description):
		SerialComp(objId, COMPID::powerBase, (uint32_t)SendFull, sizeof(SerialSendFull)){}
	
	uint16_t _lenName;
	uint16_t _lenDescription;
}__attribute__((__packed__));

SerialSendFull* allocSendFull(OBJID objId, string name, string description){

	size_t size = sizeof(SerialSendFull) + name.length() + description.length();
	SerialSendFull* s = (SerialSendFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::powerBase;
	s->op = (uint32_t)SerialCompPowerBase::SendFull;
	s->_lenName = name.length();
	s->_lenDescription = description.length();
	memcpy(s + sizeof(SerialSendFull), name.c_str(), name.size());
	memcpy(s + sizeof(SerialSendFull) + name.size(), description.c_str(),description.size());
	return s;
}

}
#endif	/* COMPPOWERBASESERIAL_H */

