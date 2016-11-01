
#ifndef COMPPOWERBASE_H
#define	COMPPOWERBASE_H

#include "../SComponent.h"
#include "../../../wkl/Program.h"
typedef uint16_t CID;

class CompPowerBase  : public SComponent {
public:
	CompPowerBase(SObj* obj);
	CompPowerBase(const CompPowerBase& orig, SObj* obj);
	CompPowerBase(SObj* obj, OBJID id, pqxx::connection& con);
	CompPowerBase* clone(SObj* obj){return new CompPowerBase(*this, obj);}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	void virtual acceptNetwork(SerialInputPayload* data);

	void sendFull(uint32_t clientId);

	//setFunctions
	void setName(string name);
	void setDescription(string description);
	void compileProgram(string src);

	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPowerBase();
private:
	virtual void init();
	void sendPowerFull(uint32_t clientId);

	string _name;
	string _description;
	string _programSource;
	string _sym;
	wkl::Program* _program;
};

#endif	/* COMPPOWERBASE_H */

