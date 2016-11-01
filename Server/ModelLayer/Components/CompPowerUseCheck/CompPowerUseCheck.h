
#ifndef COMPPOWERUSECHECK_H
#define	COMPPOWERUSECHECK_H

#include "../SComponent.h"

class CompPowerUseCheck  : public SComponent {
public:
	CompPowerUseCheck(SObj* obj);
	CompPowerUseCheck(OBJID spawner, SObj* obj);
	CompPowerUseCheck(const CompPowerUseCheck& orig, SObj* obj);
	CompPowerUseCheck(SObj* obj, OBJID id, pqxx::connection& con);
	CompPowerUseCheck* clone(SObj* obj){return new CompPowerUseCheck(*this, obj);}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
		
	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerUseCheck();
private:
	virtual void init();

	
};

#endif	/* COMPPOWERUSECHECK_H */

