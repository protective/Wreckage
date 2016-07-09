
#ifndef MESSAGEDESTINRANGEREQ_H
#define	MESSAGEDESTINRANGEREQ_H

#include "Message.h"
#include "../ObjData/SPos.h"

struct MessageDestInRangeReq : public Message {
	MessageDestInRangeReq(OBJID from, const SPos& pos, uint32_t range, uint32_t instanceRef, uint32_t runRef):
	Message(MESSAGE::destInRangeReq, from){
		_pos = pos;
		_range = range;
		_runRef = runRef;
		_instanceRef= _instanceRef;
	}
	MessageDestInRangeReq(MessageDestInRangeReq& m):
	Message(MESSAGE::destInRangeReq, m._fromId){
		_pos = m._pos;
		_range = m._range;
		_runRef = m._runRef;
		_instanceRef = m._instanceRef;	
	}
	~MessageDestInRangeReq(){
	}
	SPos _pos;
	uint32_t _range;
	uint32_t _instanceRef;
	uint32_t _runRef;
};

#endif	/* MESSAGEDESTINRANGEREQ_H */

