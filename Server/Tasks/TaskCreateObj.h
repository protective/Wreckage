/* 
 * File:   TaskCreateObj.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 20:28
 */

#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"

class TaskCreateObj : public Task {
public:
	TaskCreateObj();
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:
	OBJID _id;
};

#endif	/* TASKCREATEOBJ_H */

