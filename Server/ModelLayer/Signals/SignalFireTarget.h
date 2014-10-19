/* 
 * File:   SignalFireTarget.h
 * Author: karsten
 *
 * Created on 15. oktober 2014, 20:07
 */

#ifndef SIGNALFIRETARGET_H
#define	SIGNALFIRETARGET_H

#include "Signal.h"

struct SignalFireTarget : public Signal {
	SignalFireTarget(uint32_t powerid, OBJID target):
	Signal(SIGNAL::fireTarget){
		_powerid = powerid;
		_target = target;
	}
	SignalFireTarget(SignalFireTarget& s):
	Signal(s._type){
		_powerid = s._powerid;
		_target = s._target;
	}
	SIGNAL::Enum _type;
	uint32_t _powerid;
	OBJID _target;
};


#endif	/* SIGNALFIRETARGET_H */

