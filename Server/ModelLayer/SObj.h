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
#include "Messages/Message.h"

#define OBJFLAGINIT  0x01
#define OBJFLAGDIRTY 0x02

class Signal;
class SComponent;
class Processor;
class SObj {
public:
	SObj(OBJID id, Processor* processor);
	OBJID getId(){return _id;}
	void addComponent(SComponent* comp);
	void save();
	void init();
	void signal(SIGNAL::Enum type, Signal* data);
	void message(MESSAGE::Enum type, Message* data);

	void subscribeSignal(SIGNAL::Enum signal, SComponent* comp);
	void unSubscribeSignal(SIGNAL::Enum signal, SComponent* comp);
	void subscribeMessage(MESSAGE::Enum message, SComponent* comp);
	void unSubscribeMessage(MESSAGE::Enum message, SComponent* comp);
	Processor* getProcessor(){return _processor;}
	bool isTemplate(){return !(_id & TPIDMASK);}
	bool isInit(){return (_flags & OBJFLAGINIT) ? true : false;}

	virtual ~SObj();
private:
	OBJID _id;
	uint32_t _flags;
	Processor* _processor;
	map<COMPID::Enum, SComponent*> _components;
	map<SIGNAL::Enum, list<SComponent*> > _signalAccept;
	map<MESSAGE::Enum, list<SComponent*> > _messageAccept;
};

#endif	/* SOBJ_H */

