/* 
 * File:   Processor.h
 * Author: karsten
 *
 * Created on 16. februar 2014, 22:24
 */

#ifndef PROCESSOR_H
#define	PROCESSOR_H

#include "../BInclude.h"
#include "ClientViews.h"
#include <pqxx/pqxx>
#define COMMAND_FINAL 0
#define COMMAND_REPEAT 1
class Task;
class SObj;
class Message;
class Processor {
public:
	Processor();
	uint8_t getId(){return _id;}
	uint32_t addTask(Task* task);
	uint32_t removeTask(Task* task);
	static void* workThreadFunction(void* context);
    SObj* createObj(
        OBJID id,
        OBJID fromId,
        bool makePersistent,
        bool makeTemplate);
    
    void loadComponents(SObj* obj, OBJID fromId);
    void loadData(SObj* obj, OBJID fromId);
    void loadPos(SObj* obj, OBJID fromId);
    
	void addObj(SObj* obj);
	void removeObj(SObj* obj);
	void setClone(OBJID obj, SObj* clone){_clones[obj].push_back(clone);}
	SObj* getObj(OBJID id);
	list<SObj*>& getClones(OBJID parrent){return _clones[parrent];}
	void loadAllObjFromDb();
	void sendMessage(OBJID to, Message* message);
	void sendMessage(OBJID to, Message* message, uint32_t delay);
	
	
	OBJID getFreeID();
	pqxx::connection& getDB(){return *_dbCon;}
	
	void addClientView(uint32_t id);
	void removeClientView(uint32_t id);
	virtual ~Processor();
private:

	//Command processing
	void work();
	Task* procesFirstReadyTask();
	pthread_mutex_t _lockCommands; //protect the command list
	pthread_cond_t _workCond;   //workReady condition
	pthread_mutex_t _workMutex; //protect the workReady signal
	bool _workReady;
	list<Task*> _commands;

	map<OBJID, SObj*> _localObjs;
	map<OBJID, list<SObj*> > _clones;
	//processor Data
	uint8_t _id;
	OBJID _freeIdCount;
	pthread_mutex_t _lockFreeID;

	pqxx::connection* _dbCon;
	map<uint32_t, ClientViews*> _clientViews;
};

#endif	/* PROCESSOR_H */

