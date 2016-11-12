
#ifndef COMPSPELLBOOKSERIAL_H
#define	COMPSPELLBOOKSERIAL_H

#include "../CompSerialize.h"

namespace SerialCompSpellBook{
	enum Enum{
		Invalid = 0,
		SendFull = 1,
		ObjExit  = 2
	};

struct SerialSetField {
	enum Enum {
		Invalid = 0,
		knownpowers = 1
	};
	uint16_t _field;
}__attribute__((__packed__));

struct SerialAddKnownpower : public SerialSetField {
	OBJID _power;
}__attribute__((__packed__));

struct SerialRemoveKnownpower : public SerialSetField {
	OBJID _power;
}__attribute__((__packed__));


struct SerialPower{
	OBJID power;
    OBJID templatePower;
    uint32_t trainedFlags;
	uint16_t level;
}__attribute__((__packed__));


struct SerialSendFull : public SerialComp{
	uint16_t _xPowers;
	SerialPower _powers[1];
}__attribute__((__packed__));


void addValue(CompSpellBook* comp, SerialSetField* msg){
	switch((SerialSetField::Enum)msg->_field){
		//TODO Check Security
		case SerialSetField::Enum::knownpowers: {
			SerialAddKnownpower* st = (SerialAddKnownpower*)msg;
			comp->addPower(st->_power);
			break;
		}
    }
}

void removeValue(CompSpellBook* comp, SerialSetField* msg){
	switch((SerialSetField::Enum)msg->_field){
		//TODO Check Security
		case SerialSetField::Enum::knownpowers: {
			SerialAddKnownpower* st = (SerialAddKnownpower*)msg;
			comp->removePower(st->_power);
			break;
		}
    }
}

SerialSendFull* allocSendFull(OBJID objId, list<SerialPower>& powers){

	size_t size = sizeof(SerialSendFull) + (powers.size() * sizeof(SerialPower));
	SerialSendFull* s = (SerialSendFull*)malloc(size);
	s->_type = SerialType::SerialComp;
	s->_size = size;
	s->objid = objId;
	s->compId = COMPID::spellbook;
	s->op = (uint32_t)SerialCompSpellBook::SendFull;
	s->_xPowers = powers.size();
	int i = 0;
	for(auto power: powers){
		s->_powers[i++] = power;
	}
	return s;
}
}

#endif	/* COMPSPELLBOOKSERIAL_H */

