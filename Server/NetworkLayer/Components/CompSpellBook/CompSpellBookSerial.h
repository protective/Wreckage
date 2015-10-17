
#ifndef COMPSPELLBOOKSERIAL_H
#define	COMPSPELLBOOKSERIAL_H

#include "../CompSerialize.h"

namespace SerialCompSpellBook{
	enum Enum{
		Invalid = 0,
		SendFull = 1
	};

struct SerialSendFull : public SerialComp{
	uint16_t _xPowers;
	OBJID _powers[1];
}__attribute__((__packed__));

SerialSendFull* allocSendFull(OBJID objId, list<OBJID> powers){

	size_t size = sizeof(SerialSendFull) + (powers.size() * sizeof(OBJID));
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

