/* 
 * File:   Task.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 18:09
 */

#ifndef TASK_H
#define	TASK_H
#include "../BInclude.h"
class Processor;
class Task {
public:
	
	Task(uint32_t time);
	uint32_t getTime(){return _time;}
	void setTime(uint32_t time){_time = time;}
	Processor* getProcessor(){return _processor ;}
	void setProcessor(Processor* processor){_processor = processor;}
	virtual uint32_t execute(){};
	virtual void serialize(){};
	virtual ~Task();
protected:
	uint32_t _time;
	Processor* _processor;
};

#endif	/* TASK_H */

