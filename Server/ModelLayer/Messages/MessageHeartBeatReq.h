/* 
 * File:   MessageHeartBeatReq.h
 * Author: karsten
 *
 * Created on 19. oktober 2014, 00:51
 */

#ifndef MESSAGEHEARTBEATREQ_H
#define	MESSAGEHEARTBEATREQ_H

#include "Message.h"

struct MessageHeartBeatReq : public Message {
	MessageHeartBeatReq(OBJID from):
	Message(MESSAGE::HeartBeatReq, from){
	}
	MessageHeartBeatReq(MessageHeartBeatReq& m):
	Message(MESSAGE::HeartBeatReq, m._fromId){
	}
};


#endif	/* MESSAGEHEARTBEATREQ_H */

