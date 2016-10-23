
#ifndef COMPABILITYINPUT_H
#define	COMPABILITYINPUT_H

#include "../SComponent.h"
class CompAbilityInput  : public SComponent {
public:
	CompAbilityInput();
	//CompAbilityInput(OBJID spawner);
	CompAbilityInput(const CompAbilityInput& orig);
	CompAbilityInput(SObj* obj, OBJID id, pqxx::connection& con);
	CompAbilityInput* clone(){return new CompAbilityInput( *this );}

	void virtual acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual acceptMessage(MESSAGE::Enum type, Message* data);
    
	void virtual dbInit();
	void virtual dbTableInit(pqxx::connection& con);
	void virtual dbSave();
	void virtual dbLoad(){}
	void virtual dbDelete();
	virtual ~CompAbilityInput();
private:
	virtual void init();
	
};

#endif	/* COMPABILITYINPUT_H */

