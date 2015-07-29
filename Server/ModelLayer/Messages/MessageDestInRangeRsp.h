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
	MessageDestInRangeRsp(OBJID from, list<OBJID> res, uint32_t ref):
	Message(MESSAGE::destInRangeRsp, from){
		_res = res;
		_ref = ref;
	}
	MessageDestInRangeRsp(MessageDestInRangeRsp& m):
	Message(MESSAGE::destInRangeRsp, m._fromId){
		_res = m._res;
		_ref = m._ref;
		
	}
	~MessageDestInRangeRsp(){
	}
	list<OBJID> _res;
	uint32_t _ref;
};


#endif	/* MESSAGEDESTINRANGERSP_H */

