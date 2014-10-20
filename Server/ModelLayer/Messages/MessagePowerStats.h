/* 
 * File:   MessagePowerStats.h
 * Author: karsten
 *
 * Created on 20. oktober 2014, 23:43
 */

#ifndef MESSAGEPOWERSTATS_H
#define	MESSAGEPOWERSTATS_H

#include "Message.h"

struct MessagePowerStatsReq : public Message {
	MessagePowerStatsReq(OBJID from):
	Message(MESSAGE::powerStatsReq, from){
	}
	MessagePowerStatsReq(MessagePowerStatsReq& m):
	Message(MESSAGE::powerStatsReq, m._fromId){
	}
};

struct MessagePowerStatsRsp : public Message {
	MessagePowerStatsRsp(OBJID from):
	Message(MESSAGE::powerStatsRsp, from){
	}
	MessagePowerStatsRsp(MessagePowerStatsRsp& m):
	Message(MESSAGE::powerStatsRsp, m._fromId){
	}
	map<STATS::Enum, int32_t> _stats;
};


#endif	/* MESSAGEPOWERSTATS_H */

