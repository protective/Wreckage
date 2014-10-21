
#ifndef COMPSPELLBOOK_H
#define	COMPSPELLBOOK_H

#include "../SComponent.h"

class CompSpellBook  : public SComponent {
public:
	CompSpellBook();
	CompSpellBook(const CompSpellBook& orig);
	CompSpellBook(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompSpellBook();
private:
	virtual void init();

	list<OBJID> _knownPowers;
	list<OBJID> _loadedPowers;
};

#endif	/* COMPSPELLBOOK_H */

