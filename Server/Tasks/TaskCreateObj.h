
#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"
class SComponent;
class TaskCreateObj : public Task {
public:
	TaskCreateObj();
	void addComponent();
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:
	OBJID _id;
	map<uint32_t, SComponent*> _components;
};

#endif	/* TASKCREATEOBJ_H */

