
#ifndef COMPTARGETABLE_H
#define	COMPTARGETABLE_H
#include "SComponent.h"
class CompTargetable  : public SComponent {
public:
	CompTargetable();
	CompTargetable(const CompTargetable& orig);
	void acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual init();
	virtual ~CompTargetable();
private:

};

#endif	/* COMPTARGETABLE_H */

