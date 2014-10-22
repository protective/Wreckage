
#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"
class SComponent;
class SObj;
class TaskCreateObj : public Task {
public:
	//TaskCreateObj(bool persistent, OBJID fromId);
	TaskCreateObj(OBJID id, OBJID fromId, bool persistent);	
	bool addComponent(SComponent* cmp);
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:

	void loadComponents(SObj* obj, OBJID id);
	void loadData(OBJID id);
	
	OBJID _id;
	OBJID _fromid;
	bool _persistent;
	bool _isTemplate;
	map<COMPID::Enum, SComponent*> _components;
};

#endif	/* TASKCREATEOBJ_H */

