/* 
 * File:   TaskCloneObj.h
 * Author: karsten
 *
 * Created on 16. oktober 2014, 20:30
 */

#ifndef TASKCLONEOBJ_H
#define	TASKCLONEOBJ_H

#include "Task.h"
class TaskCloneObj : public Task {
public:
	TaskCloneObj();
	virtual uint32_t execute();
	virtual ~TaskCloneObj();
private:
	OBJTPID _id;
};

#endif	/* TASKCLONEOBJ_H */

