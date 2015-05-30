/* 
 * File:   ClientWebSock.h
 * Author: karsten
 *
 * Created on 17. maj 2015, 22:23
 */

#ifndef CLIENTWEBSOCK_H
#define	CLIENTWEBSOCK_H

#include "Client.h"

class ClientWebSock : public Client {
public:
	ClientWebSock(int socket);
	
	//reads the stream handles websocket
	virtual void ReadBuffer();
	virtual void sendToC(void* buffer, uint32_t len);
	void handshake();
	virtual ~ClientWebSock();
private:
	bool _handshakeing;
};

#endif	/* CLIENTWEBSOCK_H */

