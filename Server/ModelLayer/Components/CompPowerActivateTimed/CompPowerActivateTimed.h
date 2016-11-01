
#ifndef COMPPOWERACTIVATETIMED_H
#define	COMPPOWERACTIVATETIMED_H

#include "../SComponent.h"

class CompPowerActivateTimed  : public SComponent {
public:
	CompPowerActivateTimed(SObj* obj);
	CompPowerActivateTimed(OBJID spawner, SObj* obj);
	CompPowerActivateTimed(const CompPowerActivateTimed& orig, SObj* obj);
	CompPowerActivateTimed(SObj* obj, OBJID id, pqxx::connection& con);
	CompPowerActivateTimed* clone(SObj* obj){return new CompPowerActivateTimed(*this, obj);}

    void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerActivateTimed();
private:
	virtual void init();

	
};

#endif	/* COMPPOWERACTIVATETIMED_H */

