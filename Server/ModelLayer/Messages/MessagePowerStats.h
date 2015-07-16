/* 
 * File:   MessagePowerStats.h
 * Author: karsten
 *
 * Created on 20. oktober 2014, 23:43
 */

#ifndef MESSAGEPOWERSTATS_H
#define	MESSAGEPOWERSTATS_H

#include "Message.h"
#include "../../wkl/Utils/Variable.h"
#include "../../wkl/Program.h"


struct MessagePowerStats : public Message {
	MessagePowerStats(OBJID from, OBJID target):
	Message(MESSAGE::powerStats, from){
		_program = NULL;
		_target = target;
	}
	MessagePowerStats(OBJID from, wkl::Program* program, map<uint32_t, wkl::Variable> env, OBJID target):
	Message(MESSAGE::powerStatsRsp, from){
		_env = env;
		_program = new wkl::Program(program);
		_target = target;
	}
	MessagePowerStats(MessagePowerStats& m):
	Message(m._type, m._fromId){
		_env = m._env;
		_program = new wkl::Program(m._program);
		_target = m._target;
	}
	~MessagePowerStats(){
		if (_program)
			delete _program;
	}
	map<uint32_t, wkl::Variable> _env;
	wkl::Program* _program;
	OBJID _target;
	
};


#endif	/* MESSAGEPOWERSTATS_H */

