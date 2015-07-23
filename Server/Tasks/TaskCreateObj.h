
#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"
class SComponent;
class SObj;
class SPos;
class TaskCreateObj : public Task {
public:
	//TaskCreateObj(bool persistent, OBJID fromId);
	
	TaskCreateObj(OBJID id, OBJID fromId, bool persistent, TIME spawntime);	
	TaskCreateObj(OBJID id, OBJID fromId, bool persistent) : TaskCreateObj(id,fromId,persistent,0){}
	bool addComponent(SComponent* cmp);
	bool addData(OBJDATA::Enum dataid, int32_t value);
	bool addPos(SPos* pos);
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:

	void loadComponents(SObj* obj, OBJID id);
	void loadData(SObj* obj, OBJID id);
	void loadPos(SObj* obj, OBJID id);
	OBJID _id;
	OBJID _fromid;
	bool _persistent;
	bool _isTemplate;
	map<COMPID::Enum, SComponent*> _components;
	map<OBJDATA::Enum, int32_t> _data;
	SPos* _pos;
};

#endif	/* TASKCREATEOBJ_H */

