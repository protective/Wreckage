
#ifndef COMPTIMEDHIT_H
#define	COMPTIMEDHIT_H

#include "SComponent.h"
class CompTimedHit : public SComponent  {
public:
	CompTimedHit();
	CompTimedHit(const CompTimedHit& orig);
	void acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual init();
	virtual ~CompTimedHit();
private:

};

#endif	/* COMPTIMEDHIT_H */

