/* 
 * File:   MessagePowerBaseClone.h
 * Author: karsten
 *
 * Created on 31. oktober 2016, 23:19
 */

#ifndef MESSAGEPOWERBASECLONE_H
#define	MESSAGEPOWERBASECLONE_H

#include "../MessageReCloneComp.h"

#include "../../Components/SComponent.h"

#include "../../../wkl/Program.h"

struct MessagePowerBaseClone : public MessageReCloneComp {
	MessagePowerBaseClone(
		OBJID from,
		string name,
        string description,
        string programSource,
        string sym,
        wkl::Program* program):
	MessageReCloneComp(from)
	{
		_name = name;
        _description = description;
        _programSource = programSource;
        _sym = sym;
        _program = program;
	}
	MessagePowerBaseClone(MessagePowerBaseClone& m):
	MessageReCloneComp(m._fromId){
		_name = m._name;
        _description = m._description;
        _programSource = m._programSource;
        _sym = m._sym;
        _program = m._program;
	}
	~MessagePowerBaseClone(){
		if (_program)
			delete _program;
	}
	string _name;
	string _description;
	string _programSource;
	string _sym;
    wkl::Program* _program;
};

#endif	/* MESSAGEPOWERBASECLONE_H */

