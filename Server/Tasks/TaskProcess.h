/* 
 * File:   TaskProcess.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 23:14
 */

#ifndef TASKPROCESS_H
#define	TASKPROCESS_H
#include "Task.h"
#include "../ModelLayer/enums.h"
class SObj;
class TaskProcess : public Task {
public:
	TaskProcess(SObj* obj, TIME delta);
	virtual uint32_t execute();
	virtual ~TaskProcess();
private:
	SObj* _obj;
	TIME _procesDelta;
	TIME _last;
};

#endif	/* TASKPROCESS_H */

