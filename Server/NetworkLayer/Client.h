/* 
 * File:   Client.h
 * Author: karsten
 *
 * Created on 23. april 2011, 10:00
 */

#ifndef CLIENT_H
#define	CLIENT_H
#include "../SGlobals.h"

struct NetworkBuffer{
    uint32_t recived;
    unsigned char networkBuf[1<<14];
};

class Client {
public:
	Client(int socket);

	int getSocket(){return this->socket;}

	pthread_t listenThread;
	pthread_mutex_t networkBufLock;
	pthread_mutex_t networkSendLock;
	bool networkSendLockBool;
	void proces(){procescounter++; if(procescounter >= 25)procescounter = 0;}
	uint32_t getProcesCount(){return procescounter;}
	bool switchBuffer(){
       //active_buffer = (active_buffer+1)%2;
		if(outputnetworkBuf->recived + inputnetworkBuf->recived < 1<<14){
			memmove(outputnetworkBuf->networkBuf + outputnetworkBuf->recived, inputnetworkBuf->networkBuf, inputnetworkBuf->recived);
			outputnetworkBuf->recived += inputnetworkBuf->recived;
			inputnetworkBuf->recived = 0;
			return true;
		}else
			return false;

    }
	void setPlayerId(uint32_t id){this->playerID = id;}
	uint32_t getPlayerId(){return this->playerID;}
	uint32_t getId(){return _id;}
	uint8_t getTeamId(){return this->_teamId;}
	bool parsingoutput;
    NetworkBuffer* inputnetworkBuf;
    NetworkBuffer* outputnetworkBuf;
	//map<uint32_t,SObj*>& getsubscribes(){return this->_subscribes;}
	bool isDisconnecting(){
		bool temp;
		pthread_mutex_lock(&this->_lockState);
		temp = _isDisconnecting;
		pthread_mutex_unlock(&this->_lockState);
		return temp;
	}
	void disconnect(){
		pthread_mutex_lock(&this->_lockState);
		_isDisconnecting= true;
		pthread_mutex_unlock(&this->_lockState);
	}
	
	
	//send a block
	virtual void sendToC(void* buffer, uint32_t len);
	
	//reads the stream handles websocket
	virtual void ReadBuffer();
	
	//parse and execute the commands
	uint32_t parseBuffer(uint32_t len);
	
	
	
	void initTransfere();
	virtual ~Client();
	pthread_mutex_t& getlocksubscriber() {return locksubscriber;}

private:
	uint32_t _id;
	uint32_t procescounter;
	uint32_t playerID;
	uint32_t _teamId;
	int socket;
    uint16_t active_buffer;
	bool _isDisconnecting;
    NetworkBuffer networkBuf1;
    NetworkBuffer networkBuf2;
	pthread_mutex_t _lockState;
	pthread_mutex_t locksubscriber;
};

#endif	/* CLIENT_H */

