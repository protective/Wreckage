
#ifndef COMPRESPAWNABLE_H
#define	COMPRESPAWNABLE_H

#include "../SComponent.h"
class CompReSpawnable : public SComponent {
public:
	CompReSpawnable();
	CompReSpawnable(OBJID spawner);
	CompReSpawnable(const CompReSpawnable& orig);
	CompReSpawnable(SObj* obj, OBJID id, pqxx::connection& con);
	CompReSpawnable* clone(){return new CompReSpawnable( *this );}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
	
	void sendFull(uint32_t clientId);
	
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	
	virtual ~CompReSpawnable();
private:
	virtual void init();
	OBJID _spawner;
};

#endif	/* COMPRESPAWNABLE_H */

