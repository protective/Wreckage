
#ifndef COMPSPELLBOOK_H
#define	COMPSPELLBOOK_H

#include "../SComponent.h"

#include "../../../wkl/Compiler/systemCallLib.h"
#include "../../../wkl/ProgramExecutor.h"

#include "../../../wkl/Program.h"

class CompSpellBook  : public SComponent {
public:
	CompSpellBook();
	CompSpellBook(const CompSpellBook& orig);
	CompSpellBook(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	void virtual acceptNetwork(SerialInputPayload* data);
	
	void sendFull(uint32_t clientId);
	
	virtual map<uint32_t, wkl::systemCallFunc> getSyscalls();

		
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
	
	//systemCalls implemented by this component
	static wkl::Variable consume(SComponent* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable channel(SComponent* _this, wkl::ProgramExecutor* programExe, void* arg);
};

#endif	/* COMPSPELLBOOK_H */

