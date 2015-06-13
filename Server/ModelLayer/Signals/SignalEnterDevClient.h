
#ifndef SIGNALENTERDEVCLIENT_H
#define	SIGNALENTERDEVCLIENT_H

#include "Signal.h"

struct SignalEnterDevClient : public Signal {
	SignalEnterDevClient(uint32_t clientId):
	Signal(SIGNAL::enterDevClient){
		_clientId = clientId;
	}
	SignalEnterDevClient(SignalEnterDevClient& s):
	Signal(s._type){
		_clientId = s._clientId;
	}
	uint32_t _clientId;
};


#endif	/* SIGNALENTERDEVCLIENT_H */

