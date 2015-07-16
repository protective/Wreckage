
#ifndef COMPSPELLBOOK_H
#define	COMPSPELLBOOK_H

#include "../SComponent.h"

#include "../../../wkl/Compiler/systemCallLib.h"

class CompSpellBook  : public SComponent {
public:
	CompSpellBook();
	CompSpellBook(const CompSpellBook& orig);
	CompSpellBook(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	void virtual acceptNetwork(SerialInputPayload* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompSpellBook();
private:
	virtual void init();

	list<OBJID> _knownPowers;
	vector<OBJID> _loadedPowers;
	
	//systemCalls implemented by this component
	static map<uint32_t, wkl::systemCallFunc> _syscall;
	static wkl::Variable consume(SComponent* _this, wkl::Program* program, map<uint32_t, wkl::Variable> envContext, void* arg);
	static wkl::Variable channel(SComponent* _this, wkl::Program* program, map<uint32_t, wkl::Variable> envContext, void* arg);
};

#endif	/* COMPSPELLBOOK_H */

