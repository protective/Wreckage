/* 
 * File:   Signal.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 21:52
 */

#ifndef SIGNAL_H
#define	SIGNAL_H
#include "../../BInclude.h"

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

