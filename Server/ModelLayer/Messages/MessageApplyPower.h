/* 
 * File:   MessageApplyPower.h
 * Author: karsten
 *
 * Created on 15. oktober 2014, 20:44
 */

#ifndef MESSAGEAPPLYPOWER_H
#define	MESSAGEAPPLYPOWER_H
#include "Message.h"

struct MessageApplyPower : public Message {
	MessageApplyPower( OBJID from, map<PROJECTILESTATS::Enum, uint32_t>& stats):
	Message(MESSAGE::applyPower, from){
		_stats = stats;
	}
	MessageApplyPower(MessageApplyPower& m):
	Message(MESSAGE::applyPower){
		_stats = m._stats;
	}
	map<PROJECTILESTATS::Enum, uint32_t> _stats;
};


#endif	/* MESSAGEAPPLYPOWER_H */

