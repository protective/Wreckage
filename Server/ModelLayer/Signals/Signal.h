#ifndef SIGNAL_H
#define	SIGNAL_H

#include "../../BInclude.h"
#include "../enums.h"

struct Signal {
	Signal(SIGNAL::Enum type){
		_type = type;
	}
	Signal(Signal& s){
		_type = s._type;
	}
	SIGNAL::Enum _type;
};

#endif	/* SIGNAL_H */

