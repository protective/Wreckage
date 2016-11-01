/* 
 * File:   ComponentFactory.h
 * Author: karsten
 *
 * Created on 16. oktober 2014, 20:51
 */

#ifndef COMPONENTFACTORY_H
#define	COMPONENTFACTORY_H

#include "SComponent.h"
struct SerialObjComp;

/*
 create a component from database
 */
SComponent* createComponent(SObj* obj, COMPID::Enum type, OBJID id, pqxx::connection& con);

/*
 create a component from a stream
 * Size should be the max size of the steam
 * it is up to the factory to check that no buffer overflow occur.
 * size is set to the size of the serialiszed component before the function return
 */
SComponent* createComponent(SerialObjComp* sc, int32_t* Size, SObj* obj);


SComponent* createComponent(uint32_t compId, SObj* obj);

#endif	/* COMPONENTFACTORY_H */

