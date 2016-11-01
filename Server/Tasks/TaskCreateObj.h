
#ifndef TASKCREATEOBJ_H
#define	TASKCREATEOBJ_H

#include "Task.h"
class SComponent;
class SObj;
class SPos;
class TaskCreateObj : public Task {
public:

	TaskCreateObj(OBJID id,
			      OBJID fromId,
				  bool makePersistent,
				  bool makeTemplate,
			      TIME spawntime,
			      uint32_t clientId,
			      uint32_t creationRef);

	TaskCreateObj(OBJID id, OBJID fromId, bool makePersistent, bool makeTemplate, TIME spawntime):
		TaskCreateObj(id, fromId, makePersistent, makeTemplate, spawntime, 0, 0){}

	TaskCreateObj(OBJID id, OBJID fromId, bool makePersistent, bool makeTemplate):
		TaskCreateObj(id, fromId, makePersistent, makeTemplate, (TIME)0, 0, 0){}
	
	TaskCreateObj(OBJID id, OBJID fromId, bool makePersistent):
		TaskCreateObj(id, fromId, makePersistent, false, (TIME)0, 0, 0){}

	bool addComponent(SComponent* cmp);
	bool addData(OBJDATA::Enum dataid, int32_t value);
	bool addPos(SPos* pos);
	virtual uint32_t execute();
	virtual ~TaskCreateObj();
private:

    OBJID _id;
    OBJID _fromid;
    bool _makePersistent;
    bool _makeTemplate;
    uint32_t _clientId;
    uint32_t _creationRef;
    map<COMPID::Enum, SComponent*> _components;
    map<OBJDATA::Enum, int32_t> _data;
    SPos* _pos;
};

#endif	/* TASKCREATEOBJ_H */

