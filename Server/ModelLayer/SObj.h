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

class Signal;
class SComponent;
class SObj {
public:
	SObj(OBJID id);
	OBJID getId(){return _id;}
	void addComponent(SComponent* comp);
	void signal(SIGNAL::Enum type, Signal* data);
	void subscribeSignal(SIGNAL::Enum signal, SComponent* comp);
	void unSubscribeSignal(SIGNAL::Enum signal, SComponent* comp);
	virtual ~SObj();
private:
	OBJID _id;
	map<COMPID::Enum, SComponent*> _components;
	map<SIGNAL::Enum, list<SComponent*> > _signalAccept;
	map<MESSAGE::Enum, list<SComponent*> > _messageAccept;
};

#endif	/* SOBJ_H */
