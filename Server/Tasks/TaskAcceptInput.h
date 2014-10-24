/* 
 * File:   TaskAcceptInput.h
 * Author: karsten
 *
 * Created on 24. oktober 2014, 22:00
 */

#ifndef TASKACCEPTINPUT_H
#define	TASKACCEPTINPUT_H
#include "Task.h"
#include "../../Network/Serialize.h"

class TaskAcceptInput : public Task  {
public:
	TaskAcceptInput(OBJID obj,inputOP op, inputLen len, uint32_t* data);
	virtual uint32_t execute();
	virtual ~TaskAcceptInput();
private:
	OBJID _id;
	inputOP _op;
	inputLen _len;
	uint32_t* _data;
	
};

#endif	/* TASKACCEPTINPUT_H */

