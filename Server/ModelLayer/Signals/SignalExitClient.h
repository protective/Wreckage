
#ifndef SIGNALEXITCLIENT_H
#define	SIGNALEXITCLIENT_H

#include "Signal.h"

struct SignalExitClient : public Signal {
	SignalExitClient(uint32_t clientId):
	Signal(SIGNAL::exitClient){
		_clientId = clientId;
	}
	SignalExitClient(SignalExitClient& s):
	Signal(s._type){
		_clientId = s._clientId;
	}
	uint32_t _clientId;
};

#endif	/* SIGNALEXITCLIENT_H */

