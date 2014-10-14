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


class SComponent;
class SObj {
public:
	SObj();
	SObj(const SObj& orig);
	virtual ~SObj();
private:
	OBJID _id;
	map<COMPID::Enum, SComponent*> _components;
	//map<>

};

#endif	/* SOBJ_H */

