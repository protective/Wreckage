
#ifndef COMPMODELSTATIC_H
#define	COMPMODELSTATIC_H

#include "../SComponent.h"
class CompModelStatic : public SComponent  {
public:
	CompModelStatic();
	CompModelStatic(uint32_t modelId);
	CompModelStatic(const CompModelStatic& orig);
	CompModelStatic(OBJID id, pqxx::connection& con);	
	
	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompModelStatic();
private:
	virtual void init();
	uint32_t _modelId; 
};

#endif	/* COMPMODELSTATIC_H */

