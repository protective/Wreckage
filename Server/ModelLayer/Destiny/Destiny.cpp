/* 
 * File:   Destiny.cpp
 * Author: karsten
 * 
 * Created on 28. juli 2015, 23:33
 */

#include "Destiny.h"
#include "../../NetworkLayer/NetworkControler.h"

#include "../../ModelLayer/Messages/MessageDestInRangeReq.h"
#include "../../ModelLayer/Messages/MessageDestInRangeRsp.h"
#include "../../ModelLayer/Messages/MessageDestUpdate.h"

#include "GFunctions.h"

Destiny::Destiny() {
}

void Destiny::message(MESSAGE::Enum type, Message* data){
	switch(type){
		case MESSAGE::destInRangeReq:{
			MessageDestInRangeReq* msg = (MessageDestInRangeReq*)data;
			list<OBJID> res;
			for(auto it : _index){
				if(rangePos(it.second, msg->_pos) <=  msg->_range){
					res.push_back(it.first);
				} 
			}
			MessageDestInRangeRsp* outmsg = new MessageDestInRangeRsp(0, res, msg->_instanceRef, msg->_runRef);
			networkControl->sendMessage(msg->_fromId, outmsg);
			break;
		}
		case MESSAGE::destUpdate:{
			MessageDestUpdate* msg = (MessageDestUpdate*)data;
			_index[msg->_fromId] = msg->_pos;
		
		}
	}
}

Destiny::~Destiny() {
}

