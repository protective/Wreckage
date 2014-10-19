
#ifndef COMPABILITYCREATOR_H
#define	COMPABILITYCREATOR_H

#include "SComponent.h"
class CompAbilityCreator : public SComponent {
public:
	CompAbilityCreator();
	CompAbilityCreator(const CompAbilityCreator& orig);
	void acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual init();
	virtual ~CompAbilityCreator();
private:

};

#endif	/* COMPABILITYCREATOR_H */

