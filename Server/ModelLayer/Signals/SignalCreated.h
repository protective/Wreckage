/* 
 * File:   SignalCreated.h
 * Author: karsten
 *
 * Created on 29. juli 2015, 19:45
 */

#ifndef SIGNALCREATED_H
#define	SIGNALCREATED_H

#include "Signal.h"

struct SignalCreated : public Signal {
	SignalCreated():
	Signal(SIGNAL::created){
	}
	SignalCreated(SignalCreated& s):
	Signal(s._type){
	}
};


#endif	/* SIGNALCREATED_H */

