
#ifndef COMPCASTER_H
#define	COMPCASTER_H

#include "SComponent.h"
class CompCaster : public SComponent {
public:
	CompCaster();
	void acceptSignal(SIGNAL::Enum type, Signal* data);
	void virtual init();
	virtual ~CompCaster();
private:

};

#endif	/* COMPCASTER_H */

