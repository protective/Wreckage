/* 
 * File:   SObj.h
 * Author: karsten
 *
 * Created on 13. oktober 2014, 23:08
 */

#ifndef SOBJ_H
#define	SOBJ_H

#include "../BInclude.h"
#include "enums.h"

#include "../Network/InputSerial.h"

#include "Messages/Message.h"
#include "ObjData/SPos.h"

#define OBJFLAGINIT  0x01
#define OBJFLAGDIRTY 0x02
#define OBJFLAGPERSISTENT 0x04
#define OBJFLAGTEMPLATE 0x08



class Signal;
class SerialInputPayload;
class SComponent;
class TaskProcess;
class Processor;
class SObj {
public:
	SObj(OBJID id, bool persistent, bool istemplate, bool initialized, Processor* processor);
	OBJID getId(){return _id;}
	void setProcessTask(TaskProcess* task){
		_processtask = task;
	}
	TaskProcess* getProcessTask(){
		return _processtask;
	}
	void addComponent(SComponent* comp);
	void addData(OBJDATA::Enum comp, int32_t value);
	void save();
	void DBdelete();
	void init();
	void signal(SIGNAL::Enum type, Signal* data);
	void message(MESSAGE::Enum type, Message* data);
	void input(SerialInputPayload* data);
	
	Processor* getProcessor(){return _processor;}
	
	int32_t getData(OBJDATA::Enum dataId){
		return _data[dataId];
	}
	void setData(OBJDATA::Enum dataId, int32_t value){
		_data[dataId] = value;
	}
	
	SPos* getPos(){
		return _pos;
	}
	
	void setPos(SPos& pos){
		if(!_pos)
			_pos = new SPos(pos);
		else{
			delete _pos;
			_pos = new SPos(pos);
		}
	}
	map<COMPID::Enum, SComponent*>& getComponents(){return _components;}
	
	bool isPersistent(){return (_flags & OBJFLAGPERSISTENT) ? true : false;}
	bool isInit(){return (_flags & OBJFLAGINIT) ? true : false;}
	bool isTemplate(){return (_flags & OBJFLAGTEMPLATE) ? true : false;}

	virtual ~SObj();
private:
	OBJID _id;
	uint32_t _flags;
	Processor* _processor;
	TaskProcess* _processtask;
	map<COMPID::Enum, SComponent*> _components;
	map<OBJDATA::Enum, int32_t> _data;
	SPos* _pos;
	map<uint32_t, uint32_t> _subscribers;
	//map<SIGNAL::Enum, list<SComponent*> > _signalAccept;
	//map<MESSAGE::Enum, list<SComponent*> > _messageAccept;
};

#endif	/* SOBJ_H */

