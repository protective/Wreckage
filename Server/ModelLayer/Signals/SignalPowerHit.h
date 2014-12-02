/* 
 * File:   SignalPowerHit.h
 * Author: karsten
 *
 * Created on 22. oktober 2014, 22:49
 */

#ifndef SIGNALPOWERHIT_H
#define	SIGNALPOWERHIT_H

#include "Signal.h"

struct SignalPowerHit : public Signal {
	SignalPowerHit(TIME delta):
	Signal(SIGNAL::powerHit){
	}
	SignalPowerHit(SignalProcess& s):
	Signal(s._type){
	}
};

#endif	/* SIGNALPOWERHIT_H */

