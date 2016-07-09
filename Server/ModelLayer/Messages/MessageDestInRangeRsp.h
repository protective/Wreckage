/* 
 * File:   MessageDestInRangeRsp.h
 * Author: karsten
 *
 * Created on 26. juli 2015, 15:49
 */

#ifndef MESSAGEDESTINRANGERSP_H
#define	MESSAGEDESTINRANGERSP_H



#include "Message.h"

struct MessageDestInRangeRsp : public Message {
	MessageDestInRangeRsp(OBJID from, list<OBJID> res, uint32_t _instanceRef, uint32_t runRef):
	Message(MESSAGE::destInRangeRsp, from){
		_res = res;
		_runRef = runRef;
		_instanceRef= _instanceRef;
	}
	MessageDestInRangeRsp(MessageDestInRangeRsp& m):
	Message(MESSAGE::destInRangeRsp, m._fromId){
		_res = m._res;
		_runRef = m._runRef;
		_instanceRef = m._instanceRef;
		
	}
	~MessageDestInRangeRsp(){
	}
	list<OBJID> _res;
	uint32_t _instanceRef;
	uint32_t _runRef;
};


#endif	/* MESSAGEDESTINRANGERSP_H */

