
#ifndef COMPTARGETED_H
#define	COMPTARGETED_H

#include "../SComponent.h"

#include "../../../wkl/Compiler/systemCallLib.h"

class CompTargeted  : public SComponent {
public:
	CompTargeted();
	//CompTargeted(OBJID spawner);
	CompTargeted(const CompTargeted& orig);
	CompTargeted(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
		
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompTargeted();
private:
	virtual void init();
	map<uint32_t, wkl::systemCallFunc> _syscall;

};

wkl::Variable doDamage( SObj* target, map<uint32_t, wkl::Variable>, void* arg);

#endif	/* COMPTARGETED_H */

