
#ifndef COMPHITMECHANIC_H
#define	COMPHITMECHANIC_H

#include "SComponent.h"

class CompHitMechanic : public SComponent {
public:
	CompHitMechanic();
	CompHitMechanic(const CompHitMechanic& orig);
	void acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual init();
	virtual ~CompHitMechanic();
private:

};

#endif	/* COMPHITMECHANIC_H */

