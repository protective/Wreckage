
#ifndef MESSAGEDESTINRANGEREQ_H
#define	MESSAGEDESTINRANGEREQ_H

#include "Message.h"
#include "../ObjData/SPos.h"

struct MessageDestInRangeReq : public Message {
	MessageDestInRangeReq(OBJID from, const SPos& pos, uint32_t range, uint32_t ref):
	Message(MESSAGE::destInRangeReq, from){
		_pos = pos;
		_range = range;
		_ref = ref;
	}
	MessageDestInRangeReq(MessageDestInRangeReq& m):
	Message(MESSAGE::destInRangeReq, m._fromId){
		_pos = m._pos;
		_ref = m._ref;
		_range = m._range;
		
	}
	~MessageDestInRangeReq(){
	}
	SPos _pos;
	uint32_t _range;
	uint32_t _ref;
};

#endif	/* MESSAGEDESTINRANGEREQ_H */

