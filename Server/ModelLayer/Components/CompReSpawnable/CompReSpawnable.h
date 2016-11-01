
#ifndef COMPRESPAWNABLE_H
#define	COMPRESPAWNABLE_H

#include "../SComponent.h"
class CompReSpawnable : public SComponent {
public:
	CompReSpawnable(SObj* obj);
	CompReSpawnable(OBJID spawner, SObj* obj);
	CompReSpawnable(const CompReSpawnable& orig, SObj* obj);
	CompReSpawnable(SObj* obj, OBJID id, pqxx::connection& con);
	CompReSpawnable* clone(SObj* obj){return new CompReSpawnable(*this, obj);}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void static dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	
	virtual ~CompReSpawnable();
private:
	virtual void init();
	OBJID _spawner;
};

#endif	/* COMPRESPAWNABLE_H */

