
#ifndef COMPPOWERACTIVATE_H
#define	COMPPOWERACTIVATE_H

#include "../SComponent.h"

class CompPowerUseCheck  : public SComponent {
public:
	CompPowerUseCheck();
	CompPowerUseCheck(OBJID spawner);
	CompPowerUseCheck(const CompPowerUseCheck& orig);
	CompPowerUseCheck(OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerUseCheck();
private:
	virtual void init();

	
};

#endif	/* COMPPOWERACTIVATE_H */

