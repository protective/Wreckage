
#ifndef SIGNALENTERCLIENT_H
#define	SIGNALENTERCLIENT_H

#include "Signal.h"

struct SignalEnterClient : public Signal {
	SignalEnterClient(uint32_t clientId):
	Signal(SIGNAL::enterClient){
		_clientId = clientId;
	}
	SignalEnterClient(SignalEnterClient& s):
	Signal(s._type){
		_clientId = s._clientId;
	}
	uint32_t _clientId;
};

#endif	/* SIGNALENTERCLIENT_H */

