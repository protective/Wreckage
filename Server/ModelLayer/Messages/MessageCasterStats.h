/* 
 * File:   MessageCasterStats.h
 * Author: karsten
 *
 * Created on 22. oktober 2014, 23:06
 */

#ifndef MESSAGECASTERSTATS_H
#define	MESSAGECASTERSTATS_H

#include "Message.h"

struct MessageCasterStats: public Message {
	MessageCasterStats(OBJID from):
	Message(MESSAGE::casterStatsReq, from){
	}
	MessageCasterStats(MessageCasterStats& m):
	Message(MESSAGE::casterStatsReq, m._fromId){
	}
};

struct MessageCasterStatsRsp : public Message {
	MessageCasterStatsRsp(OBJID from, int32_t damage):
	Message(MESSAGE::casterStatsRsp, from){
		this->damage = damage;
	}
	MessageCasterStatsRsp(MessageCasterStatsRsp& m):
	Message(MESSAGE::casterStatsRsp, m._fromId){
		damage = m.damage;
	}
	int32_t damage;
};

#endif	/* MESSAGECASTERSTATS_H */

