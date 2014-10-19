/* 
 * File:   MessageHeartBeat.h
 * Author: karsten
 *
 * Created on 19. oktober 2014, 00:51
 */

#ifndef MESSAGEHEARTBEATRSP_H
#define	MESSAGEHEARTBEATRSP_H

#include "Message.h"

struct MessageHeartBeatRsp : public Message {
	MessageHeartBeatRsp(OBJID from):
	Message(MESSAGE::HeartBeatRsp, from){
	}
	MessageHeartBeatRsp(MessageHeartBeatRsp& m):
	Message(MESSAGE::HeartBeatRsp, m._fromId){
	}
};


#endif	/* MESSAGEHEARTBEATRSP_H */

