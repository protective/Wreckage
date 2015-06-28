
#ifndef TASKSENDMESSAGE_H
#define	TASKSENDMESSAGE_H

#include "Task.h"
class Message;
class TaskSendMessage : public Task {
public:
	TaskSendMessage(OBJID _toId, Message* _message);
	virtual uint32_t execute();
	virtual ~TaskSendMessage();
private:
	OBJID _toId;
	Message* _message;
};

#endif	/* TASKSENDMESSAGE_H */

