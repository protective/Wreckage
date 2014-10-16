
#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"
class SComponent;
class TaskCreateObj : public Task {
public:
	TaskCreateObj(bool persistent);
	void addComponent(SComponent* cmp);
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:
	OBJID _id;
	bool _persistent;
	map<COMPID::Enum, SComponent*> _components;
};

#endif	/* TASKCREATEOBJ_H */

