/* 
 * File:   MessageProjectileStats.h
 * Author: karsten
 *
 * Created on 20. oktober 2014, 23:39
 */

#ifndef MESSAGEPROJECTILESTATS_H
#define	MESSAGEPROJECTILESTATS_H

#include "Message.h"
#include "../../wkl/Utils/Variable.h"
#include "../../wkl/Program.h"

struct MessageProjectileStats : public Message {
	MessageProjectileStats(OBJID from,  wkl::Program* program, map<uint32_t, wkl::Variable> env):
	Message(MESSAGE::ProjectileStats, from){
		_env = env;
		_program = program;
	}
	MessageProjectileStats(MessageProjectileStats& m):
	Message(MESSAGE::ProjectileStats, m._fromId){
		_env = m._env;
		_program = m._program;
	}
	map<uint32_t, wkl::Variable> _env;
	wkl::Program* _program;
};

#endif	/* MESSAGEPROJECTILESTATS_H */

