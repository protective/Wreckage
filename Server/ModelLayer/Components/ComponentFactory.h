/* 
 * File:   ComponentFactory.h
 * Author: karsten
 *
 * Created on 16. oktober 2014, 20:51
 */

#ifndef COMPONENTFACTORY_H
#define	COMPONENTFACTORY_H

#include "SComponent.h"

SComponent* createComponent(COMPID::Enum type, pqxx::connection& con);

#endif	/* COMPONENTFACTORY_H */

