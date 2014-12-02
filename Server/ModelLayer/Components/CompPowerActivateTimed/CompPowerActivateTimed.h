
#ifndef COMPPOWERACTIVATETIMED_H
#define	COMPPOWERACTIVATETIMED_H

#include "../SComponent.h"

class CompPowerActivateTimed  : public SComponent {
public:
	CompPowerActivateTimed();
	CompPowerActivateTimed(OBJID spawner);
	CompPowerActivateTimed(const CompPowerActivateTimed& orig);
	CompPowerActivateTimed(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerActivateTimed();
private:
	virtual void init();

	
};

#endif	/* COMPPOWERACTIVATETIMED_H */

