/* 
 * File:   MessageSpellbookClone.h
 * Author: karsten
 *
 * Created on 31. oktober 2016, 23:16
 */

#ifndef MESSAGESPELLBOOKCLONE_H
#define	MESSAGESPELLBOOKCLONE_H

#include "../MessageReCloneComp.h"
#include "../../Components/SComponent.h"

struct MessageSpellbookClone : public MessageReCloneComp {
	MessageSpellbookClone(
		OBJID from,
		list<OBJID> powers):
	MessageReCloneComp(from)
	{
		_powers = powers;
	}
	MessageSpellbookClone(MessageSpellbookClone& m):
	MessageReCloneComp(m._fromId){
		_powers = m._powers;
	}
	~MessageSpellbookClone(){}
	list<OBJID> _powers;
};
#endif	/* MESSAGESPELLBOOKCLONE_H */

