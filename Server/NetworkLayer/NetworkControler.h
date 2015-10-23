/* 
 * File:   NetworkControler.h
 * Author: karsten
 *
 * Created on 22. februar 2014, 23:13
 */

#ifndef NETWORKCONTROLER_H
#define	NETWORKCONTROLER_H


#include "Client.h"
#include "../BInclude.h"

class SObj;
class Processor;
class Task;
class Message;
class NetworkControler {
public:
	NetworkControler();
	
	void addClient(Client* client);
	void removeClient(Client* client);
	void registerObj(OBJID obj, Processor* processor);
	void deRegisterObj(OBJID obj);
	//Processor* getProcessor(uint32_t objId);
	SObj* getObj(uint32_t objId);
	void sendMessage(OBJID to, Message* message);
	void sendMessage(OBJID to, Message* message, uint32_t delay);
	uint32_t addTaskToObj(Task* task, OBJID obj);
	void readBuffers();
	uint32_t sendToC(uint32_t clientId, void* block, uint32_t len);
	virtual ~NetworkControler();
private:
	void sendObjDel(OBJID to, OBJID deleted);
	map<uint32_t, Client*> _connections;
	pthread_mutex_t _clientLock;
	pthread_mutex_t _objRegistrationListLock;
	map<OBJID, Processor*> _objRegistration;
	map<OBJID, list<OBJID> > _objRefs;
};

#endif	/* NETWORKCONTROLER_H */

