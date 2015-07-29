
#ifndef COMPTARGETED_H
#define	COMPTARGETED_H

#include "../SComponent.h"

#include "../../../wkl/Compiler/systemCallLib.h"
#include "../../../wkl/ProgramExecutor.h"

#include "../../../wkl/Program.h"

class CompTargeted  : public SComponent {
public:
	CompTargeted();
	//CompTargeted(OBJID spawner);
	CompTargeted(const CompTargeted& orig);
	CompTargeted(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
	
	virtual map<uint32_t, wkl::systemCallFunc> getSyscalls();

	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompTargeted();
private:
	virtual void init();
	
	//systemCalls implemented by this component
	static wkl::Variable phycicalDamage(SComponent* _this, wkl::ProgramExecutor* programExe, void* arg);
};


#endif	/* COMPTARGETED_H */

