/* 
 * File:   SignalGainComp.h
 * Author: karsten
 *
 * Created on 16. oktober 2016, 16:54
 */

#ifndef SIGNALGAINCOMP_H
#define	SIGNALGAINCOMP_H

#include "Signal.h"

struct SignalGainComp : public Signal {
	SignalGainComp(SComponent* comp):
	Signal(SIGNAL::gainComp){
		_comp = comp;
	}
	SignalGainComp(SignalGainComp& s):
	Signal(s._type){
		_comp = s._comp;
	}
	SComponent* _comp;
};

#endif	/* SIGNALGAINCOMP_H */

