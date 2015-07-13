
#ifndef COMPPOWERBASE_H
#define	COMPPOWERBASE_H

#include "../SComponent.h"
#include "../../../wkl/Program.h"
typedef uint16_t CID;

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
	
	map<CID, map<STATS::Enum, int32_t> > _base;
	map<CID, map<STATS::Enum, STATS::Enum> > _projectileForward;
	wkl::Program* _program;
};

#endif	/* COMPPOWERBASE_H */

