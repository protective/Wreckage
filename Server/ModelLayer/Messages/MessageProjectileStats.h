/* 
 * File:   MessageProjectileStats.h
 * Author: karsten
 *
 * Created on 20. oktober 2014, 23:39
 */

#ifndef MESSAGEPROJECTILESTATS_H
#define	MESSAGEPROJECTILESTATS_H

#include "Message.h"

struct MessageProjectileStats : public Message {
	MessageProjectileStats(OBJID from):
	Message(MESSAGE::ProjectileStats, from){
	}
	MessageProjectileStats(MessageProjectileStats& m):
	Message(MESSAGE::ProjectileStats, m._fromId){
	}
	map<STATS::Enum, int32_t> _stats;
};

#endif	/* MESSAGEPROJECTILESTATS_H */

