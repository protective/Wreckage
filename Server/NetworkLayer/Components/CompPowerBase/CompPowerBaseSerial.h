
#ifndef COMPPOWERBASESERIAL_H
#define	COMPPOWERBASESERIAL_H

#include "../CompSerialize.h"
#include <sstream>

namespace SerialCompPowerBase{
	enum Enum{
		Invalid = 0,
		SendFull = 1,
		ObjExit  = 2,
	};

struct SerialSetField {
	enum Enum {
		Invalid = 0,
		name = 1,
		description = 2,
		program = 3,
	};
	uint16_t _field;
}__attribute__((__packed__));

struct SerialSetString : public SerialSetField {
	uint32_t _len;
	char _text[1];
}__attribute__((__packed__));

void setvalue(CompPowerBase* comp, SerialSetField* msg){
	switch((SerialSetField::Enum)msg->_field){
		//TODO Check Security
		case SerialSetField::Enum::name:{
			SerialSetString* st = (SerialSetString*)msg;
			comp->setName(string(st->_text,st->_len));
			break;
		}
		case SerialSetField::Enum::description:{
			SerialSetString* st = (SerialSetString*)msg;
			comp->setDescription(string(st->_text,st->_len));
			break;
		}
		case SerialSetField::Enum::program:{
			stringstream maskstream;
			for (uint32_t i = 0; i < 8; i+=1){
				maskstream <<std::hex <<setfill('0')<<setw( 2 ) << (uint16_t)(((char*)msg)[i] & 0x00FF) << " ";
			}
			SerialSetString* st = (SerialSetString*)msg;
			comp->compileProgram(string(st->_text, st->_len));
			break;
		}
	}
    comp->dbSave();
}

struct SerialSendFull : public SerialComp{
	SerialSendFull(OBJID objId, string name, string description, string programSrc):
		SerialComp(objId, COMPID::powerBase, (uint32_t)SendFull, sizeof(SerialSendFull)){}

	uint16_t _lenName;
	uint16_t _lenDescription;
	uint16_t _lenProgramSrc;
}__attribute__((__packed__));

SerialSendFull* allocSendFull(OBJID objId, string name, string description, string programSrc){

	size_t size = sizeof(SerialSendFull) + name.size() + description.size() + programSrc.size();
	SerialSendFull* s = (SerialSendFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::powerBase;
	s->op = (uint32_t)SerialCompPowerBase::SendFull;
	s->_lenName = name.size();
	s->_lenDescription = description.size();
	s->_lenProgramSrc = programSrc.size();

	memcpy((char*)s + sizeof(SerialSendFull), name.c_str(), name.size());
	memcpy((char*)s + sizeof(SerialSendFull) + name.size(), description.c_str(),description.size());
	memcpy((char*)s + sizeof(SerialSendFull) + name.size() + description.size(), programSrc.c_str(), programSrc.size());

	return s;
}

}
#endif	/* COMPPOWERBASESERIAL_H */

