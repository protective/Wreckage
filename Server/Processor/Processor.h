/* 
 * File:   Processor.h
 * Author: karsten
 *
 * Created on 16. februar 2014, 22:24
 */

#ifndef PROCESSOR_H
#define	PROCESSOR_H

#include "../BInclude.h"
#define COMMAND_FINAL 0
#define COMMAND_REPEAT 1
class Task;
class Processor {
public:
	Processor();
	uint8_t getId(){return _id;}
	uint32_t addTask(Task* task);
	uint32_t removeTask(Task* task);
	static void* workThreadFunction(void* context);

	uint32_t getFreeID();
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

	//processor Data
	uint8_t _id;
	uint32_t _freeIdCount;
	pthread_mutex_t _lockFreeID;

};

#endif	/* PROCESSOR_H */

