
#ifndef COMPPOWERACTIVATEINSTANT_H
#define	COMPPOWERACTIVATEINSTANT_H

#include "../SComponent.h"

class CompPowerActivateInstant : public SComponent {
public:
	CompPowerActivateInstant();
	//CompPowerActivateInstant(OBJID spawner);
	CompPowerActivateInstant(const CompPowerActivateInstant& orig);
	CompPowerActivateInstant(SObj* obj, OBJID id, pqxx::connection& con);
	CompPowerActivateInstant* clone(){return new CompPowerActivateInstant( *this );}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerActivateInstant();
private:
	virtual void init();

	
};

#endif	/* COMPPOWERACTIVATEINSTANT_H */

