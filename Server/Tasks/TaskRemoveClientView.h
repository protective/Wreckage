
#ifndef TASKREMOVECLIENTVIEW_H
#define	TASKREMOVECLIENTVIEW_H

#include "Task.h"

class TaskRemoveClientView  : public Task {
public:
	TaskRemoveClientView(uint32_t clientId);
	virtual uint32_t execute();
	virtual ~TaskRemoveClientView();
private:
	uint32_t clientId;
};

#endif	/* TASKREMOVECLIENTVIEW_H */

