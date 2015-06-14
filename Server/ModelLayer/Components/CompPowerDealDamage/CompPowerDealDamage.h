
#ifndef COMPDEALDAMAGE_H
#define	COMPDEALDAMAGE_H

#include "../SComponent.h"

class CompPowerDealDamage  : public SComponent {
public:
	CompPowerDealDamage();
	//CompPowerDealDamage(OBJID spawner);
	CompPowerDealDamage(const CompPowerDealDamage& orig);
	CompPowerDealDamage(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerDealDamage();
private:
	virtual void init();

	
};

#endif	/* COMPDEALDAMAGE_H */

