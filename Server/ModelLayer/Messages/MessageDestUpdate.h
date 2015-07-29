/* 
 * File:   MessageDestUpdate.h
 * Author: karsten
 *
 * Created on 29. juli 2015, 19:50
 */

#ifndef MESSAGEDESTUPDATE_H
#define	MESSAGEDESTUPDATE_H

#include "Message.h"
#include "../ObjData/SPos.h"
 
struct MessageDestUpdate : public Message {
	MessageDestUpdate(OBJID from, const SPos& pos):
	Message(MESSAGE::destUpdate, from){
		_pos = pos;
	}
	MessageDestUpdate(MessageDestUpdate& m):
	Message(MESSAGE::destUpdate, m._fromId){
		_pos = m._pos;
		
	}
	~MessageDestUpdate(){
	}
	SPos _pos;

};

#endif	/* MESSAGEDESTUPDATE_H */

