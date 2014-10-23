
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
	bool addData(OBJDATA::Enum dataid, int32_t value);
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:

	void loadComponents(SObj* obj, OBJID id);
	void loadData(SObj* obj, OBJID id);
	
	OBJID _id;
	OBJID _fromid;
	bool _persistent;
	bool _isTemplate;
	map<COMPID::Enum, SComponent*> _components;
	map<OBJDATA::Enum, int32_t> _data;
};

#endif	/* TASKCREATEOBJ_H */

