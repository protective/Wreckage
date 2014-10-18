
#ifndef TASKADDCOMPONENT_H
#define	TASKADDCOMPONENT_H

#include "Task.h"
#include "../Processor/Processor.h"
#include "../ModelLayer/SObj.h"
class SComponent;
class SObj;
class TaskAddComponent : public Task{
public:
	TaskAddComponent();
	virtual uint32_t execute();
	virtual ~TaskAddComponent();
private:
	SObj* _id;
	SComponent* _component;
	
};

#endif	/* TASKADDCOMPONENT_H */

