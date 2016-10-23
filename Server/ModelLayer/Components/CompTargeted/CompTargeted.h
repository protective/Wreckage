
#ifndef COMPTARGETED_H
#define	COMPTARGETED_H

#include "../SComponent.h"

#include "../../../wkl/Compiler/systemCallLib.h"
#include "../../../wkl/ProgramInstance.h"

#include "../../../wkl/Program.h"
#include "../../../wkl/ProgramExecutor.h"

struct BuffIterator {
	uint32_t iteratorId;
	uint32_t interrupt_functionId;
	list<uint32_t> buffs;
	wkl::ProgramExecutor* callback_programExe;
	systemCallFunc callback_function;
	vector<Variable> callback_args;
};

class CompTargeted  : public SComponent {
public:
	CompTargeted();
	//CompTargeted(OBJID spawner);
	CompTargeted(const CompTargeted& orig);
	CompTargeted(SObj* obj, OBJID id, pqxx::connection& con);
	CompTargeted* clone(){return new CompTargeted( *this );}

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

	map<uint32_t, wkl::ProgramInstance*>& getBuffs(){return _buffs;}
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompTargeted();
private:
	virtual void init();
	uint32_t _buffIdSequence;
	map<uint32_t, wkl::ProgramInstance*> _buffs;
	uint32_t _asyncIteratorCount;
	map<uint32_t, void*> _asyncIterators;
	
	//systemCalls implemented by this component
	void foreachbuff(uint32_t interrupt_functionId, wkl::ProgramExecutor* callback_programExe, vector<Variable> args, systemCallFunc callback);
	static void _foreachbuff(SObj* _this, void* block);
	static wkl::Variable phycicalDamage(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable takeDamage(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable gainBuff(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable updateBuff(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);
	static wkl::Variable loseBuff(SObj* _this, wkl::ProgramExecutor* programExe, void* arg);

};


#endif	/* COMPTARGETED_H */

