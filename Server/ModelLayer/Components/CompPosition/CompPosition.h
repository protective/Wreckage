
#ifndef COMPPOSITION_H
#define	COMPPOSITION_H

#include "../SComponent.h"
class CompPosition : public SComponent  {
public:
	CompPosition(SObj* obj);
	CompPosition(uint32_t modelId, SObj* obj);
	CompPosition(const CompPosition& orig, SObj* obj);
	CompPosition(SObj* obj, OBJID id, pqxx::connection& con);	
	CompPosition* clone(SObj* obj){return new CompPosition(*this, obj);}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompPosition();
private:
	virtual void init();
};

#endif	/* COMPPOSITION_H */

