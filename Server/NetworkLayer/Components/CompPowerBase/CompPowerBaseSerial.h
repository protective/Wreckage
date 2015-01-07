/* 
 * File:   CompPowerBase.h
 * Author: karsten
 *
 * Created on 2. januar 2015, 15:03
 */

#ifndef COMPPOWERBASESERIAL_H
#define	COMPPOWERBASESERIAL_H

#include "../CompSerialize.h"


namespace SerialCompPowerBase{
	/** Identifiers for each serializable type
	  */
	enum Enum{
		/** Dummy entry for serialization of incomplete types
		  */
		Invalid = 0,
		SendFull = 1,
		ObjExit  = 2,
		
	};
}



struct SerialPowerFull : public SerialComp{
	SerialPowerFull(OBJID objId, string name, string description):
	SerialComp(objId, COMPID::powerBase, (uint32_t)SerialCompPowerBase::SendFull, sizeof(SerialPowerFull)){

	}
	uint16_t _lenName;
	uint16_t _lenDescription;
	char _strings[1];
}__attribute__((__packed__));

SerialPowerFull* SerialPowerFull_Alloc(OBJID objId, string name, string description){

	size_t size = sizeof(SerialPowerFull) + name.length() + description.length();
	SerialPowerFull* s = (SerialPowerFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::powerBase;
	s->op = (uint32_t)SerialCompPowerBase::SendFull;
	s->_lenName = name.length();
	s->_lenDescription = description.length();
	memcpy(s->_strings, name.c_str(),name.size());
	memcpy(s->_strings + name.size(), description.c_str(),description.size());
	return s;
}

#endif	/* COMPPOWERBASESERIAL_H */

