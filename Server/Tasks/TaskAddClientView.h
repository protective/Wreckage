
#ifndef TASKADDCLIENTVIEW_H
#define	TASKADDCLIENTVIEW_H

#include "Task.h"

class TaskAddClientView  : public Task {
public:
	TaskAddClientView(uint32_t clientId);
	virtual uint32_t execute();
	virtual ~TaskAddClientView();
private:
	uint32_t clientId;
};

#endif	/* TASKADDLOCALCLIENTVIEW_H */

