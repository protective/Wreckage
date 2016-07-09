
#ifndef COMPROGRAMABLE_H
#define	COMPROGRAMABLE_H

#include "../SComponent.h"
#include "../../../wkl/Program.h"
#include "../../../wkl/ProgramInstance.h"

class CompProgramable : public SComponent {
public:
	CompProgramable();
	CompProgramable(const CompProgramable& orig);
	CompProgramable(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	void virtual acceptNetwork(SerialInputPayload* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompProgramable();
private:
	virtual void init();
	
	uint32_t _programIdCounter;
	map<uint32_t, wkl::ProgramInstance*> _programInst;

	virtual map<uint32_t, wkl::systemCallFunc> getSyscalls();
	static wkl::Variable getObjInRange(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable sleep(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);

	static wkl::Variable min(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable max(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);

};

#endif	/* COMPROGRAMABLE_H */

