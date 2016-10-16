#ifndef SIGNALCREATED_H
#define	SIGNALCREATED_H

#include "Signal.h"

struct SignalCreated : public Signal {
	SignalCreated(uint32_t clientId, uint32_t creationRef):
	Signal(SIGNAL::created){
		_clientId = clientId;
		_creationRef = creationRef;
	}
	SignalCreated(SignalCreated& s):
	Signal(s._type){
		_clientId = s._clientId;
		_creationRef = s._creationRef;
	}
	uint32_t _clientId;
	uint32_t _creationRef;
};

#endif	/* SIGNALCREATED_H */

