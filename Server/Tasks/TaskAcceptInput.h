/* 
 * File:   TaskAcceptInput.h
 * Author: karsten
 *
 * Created on 24. oktober 2014, 22:00
 */

#ifndef TASKACCEPTINPUT_H
#define	TASKACCEPTINPUT_H
#include "Task.h"
#include "../../Network/InputSerial.h"

class TaskAcceptInput : public Task  {
public:
	TaskAcceptInput(OBJID id, SerialInputPayload* data);
	virtual uint32_t execute();
	virtual ~TaskAcceptInput();
private:
	OBJID _id;
	SerialInputPayload* _data;
	
};

#endif	/* TASKACCEPTINPUT_H */

