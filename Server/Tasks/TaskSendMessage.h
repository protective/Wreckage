
#ifndef TASKSENDMESSAGE_H
#define	TASKSENDMESSAGE_H

#include "Task.h"
class Message;
class SObj;
class TaskSendMessage : public Task {
public:
	TaskSendMessage(SObj* _toId, Message* _message);
	virtual uint32_t execute();
	virtual ~TaskSendMessage();
private:
	SObj* _toId;
	Message* _message;
};

#endif	/* TASKSENDMESSAGE_H */

