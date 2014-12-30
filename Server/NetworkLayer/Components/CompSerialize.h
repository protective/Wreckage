/* 
 * File:   CompSerialize.h
 * Author: karsten
 *
 * Created on 8. november 2014, 00:41
 */

#ifndef COMPSERIALIZE_H
#define	COMPSERIALIZE_H
#include "../Network/Serialize.h"

#include "../../ModelLayer/enums.h"

struct SerialComp : public SerialData{
	SerialComp(OBJID objid, uint32_t compId, uint32_t op, uint32_t size):
	SerialData(SerialType::SerialComp, size){
		this->objid = objid;
		this->compId = compId;
		this->op = op;
	}
	OBJID objid;
	uint32_t compId;
	uint32_t op;
}__attribute__((__packed__));

#endif	/* COMPSERIALIZE_H */

