/* 
 * File:   TaskAddComponent.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 20:48
 */

#ifndef TASKADDCOMPONENT_H
#define	TASKADDCOMPONENT_H

#include "Task.h"
#include "../ModelLayer/enums.h"

class TaskAddComponent : public Task{
public:
	TaskAddComponent();
	virtual uint32_t execute();
	virtual ~TaskAddComponent();
private:
	OBJID _id;
	COMPID::Enum _component;
};

#endif	/* TASKADDCOMPONENT_H */

