
#ifndef SIGNALKILLED_H
#define	SIGNALKILLED_H

#include "Signal.h"

struct SignalKilled : public Signal {
	SignalProcess():
	Signal(SIGNAL::killed){
	}
	SignalProcess(SignalProcess& s):
	Signal(s._type){
	}
};


#endif	/* SIGNALKILLED_H */

