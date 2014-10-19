/* 
 * File:   SignalProcess.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 23:09
 */

#ifndef SIGNALPROCESS_H
#define	SIGNALPROCESS_H

#include "Signal.h"

struct SignalProcess : public Signal {
	SignalProcess(SIGNAL::Enum type, TIME delta):
	Signal(type){
		_delta = delta;
	}
	SignalProcess(SignalProcess& s):
	Signal(s._type){
		_delta = s._delta;
	}
	SIGNAL::Enum _type;
	TIME _delta;
};


#endif	/* SIGNALPROCESS_H */

