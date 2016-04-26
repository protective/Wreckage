
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
	void sendEventTargetGainBuff(
		OBJID target,
		OBJID caster,
		uint32_t buffIndex,
		uint32_t duration,
		uint32_t maxduration,
		uint32_t charges,
		uint32_t image,
		uint32_t nameSIndex);
		void sendEventTargetLoseBuff(
		OBJID target,
		uint32_t buffIndex);
	virtual map<uint32_t, wkl::systemCallFunc> getSyscalls();

	map<uint32_t, wkl::ProgramExecutor*>& getBuffs(){return _buffs;}
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompTargeted();
private:
	virtual void init();
	uint32_t _buffIdSequence;
	map<uint32_t, wkl::ProgramExecutor*> _buffs;
	//systemCalls implemented by this component
	static wkl::Variable phycicalDamage(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable gainBuff(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable updateBuff(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable loseBuff(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);

};


#endif	/* COMPTARGETED_H */

