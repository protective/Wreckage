
#ifndef COMPPOWERBASE_H
#define	COMPPOWERBASE_H

#include "../SComponent.h"

class CompPowerBase  : public SComponent {
public:
	CompPowerBase();
	CompPowerBase(const CompPowerBase& orig);
	CompPowerBase(SObj* obj, OBJID id, pqxx::connection& con);
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	void virtual acceptNetwork(SerialInputPayload* data);

	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerBase();
private:
	virtual void init();
	void sendPowerFull(uint32_t clientId);
	
	string _name;
	string _description;
	
};

#endif	/* COMPPOWERBASE_H */

