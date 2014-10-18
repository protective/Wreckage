
#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"
class SComponent;
class TaskCreateObj : public Task {
public:
	TaskCreateObj(bool persistent, OBJID fromId);
	TaskCreateObj(OBJID id, OBJID fromId, bool persistent);	

	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:
	
	void addComponent(SComponent* cmp);
	void loadComponents(OBJID id);
	void loadData(OBJID id);
	
	OBJID _id;
	OBJID _fromid;
	bool _persistent;
	map<COMPID::Enum, SComponent*> _components;
};

#endif	/* TASKCREATEOBJ_H */

