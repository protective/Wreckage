/* 
 * File:   TaskRemoveObj.h
 * Author: karsten
 *
 * Created on 19. oktober 2014, 12:05
 */

#ifndef TASKREMOVEOBJ_H
#define	TASKREMOVEOBJ_H

#include "Task.h"
class SComponent;
class TaskRemoveObj : public Task {
public:
	TaskRemoveObj(OBJID obj);

	virtual uint32_t execute();
	virtual ~TaskRemoveObj();
private:
	OBJID _obj;
};

#endif	/* TASKREMOVEOBJ_H */

