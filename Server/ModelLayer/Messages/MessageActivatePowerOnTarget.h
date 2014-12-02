/* 
 * File:   MessageActivatePowerOnTarget.h
 * Author: karsten
 *
 * Created on 23. oktober 2014, 21:21
 */

#ifndef MESSAGEACTIVATEPOWERONTARGET_H
#define	MESSAGEACTIVATEPOWERONTARGET_H

#include "Message.h"

struct MessageActivatePowerOnTarget : public Message {
	MessageActivatePowerOnTarget(OBJID from, OBJID target):
	Message(MESSAGE::activatePowerOnt, from){
		this->target = target;
	}
	MessageActivatePowerOnTarget(MessageActivatePowerOnTarget& m):
	Message(MESSAGE::activatePowerOnt, m._fromId){
		this->target = m.target;
	}
	
	OBJID target;
};

#endif	/* MESSAGEACTIVATEPOWERONTARGET_H */

