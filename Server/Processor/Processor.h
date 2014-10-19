/* 
 * File:   Processor.h
 * Author: karsten
 *
 * Created on 16. februar 2014, 22:24
 */

#ifndef PROCESSOR_H
#define	PROCESSOR_H

#include "../BInclude.h"
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
	void addObj(SObj* obj);
	void removeObj(SObj* obj);
	SObj* getObj(OBJID id);
	void loadAllObjFromDb();
	void sendMessage(OBJID to, Message* message);
	OBJID getFreeID();
	pqxx::connection& getDB(){return *_dbCon;}
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
	//processor Data
	uint8_t _id;
	OBJID _freeIdCount;
	pthread_mutex_t _lockFreeID;

	pqxx::connection* _dbCon;

};

#endif	/* PROCESSOR_H */

