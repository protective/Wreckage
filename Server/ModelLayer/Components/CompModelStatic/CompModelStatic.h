
#ifndef COMPMODELSTATIC_H
#define	COMPMODELSTATIC_H

#include "../SComponent.h"
class CompModelStatic : public SComponent  {
public:
	CompModelStatic(SObj* obj);
	CompModelStatic(uint32_t modelId, SObj* obj);
	CompModelStatic(const CompModelStatic& orig, SObj* obj);
	CompModelStatic(SObj* obj, OBJID id, pqxx::connection& con);	
	CompModelStatic* clone(SObj* obj){return new CompModelStatic(*this, obj);}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompModelStatic();
private:
	virtual void init();
	void sendEnter(uint32_t clientId);
	void sendExit(uint32_t clientId);
	uint32_t _modelId; 
};

#endif	/* COMPMODELSTATIC_H */

