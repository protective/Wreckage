/* 
 * File:   TokenIdentifier.h
 * Author: karsten
 *
 * Created on 6. september 2014, 13:31
 */

#ifndef SORDERIDENTIFIER_H
#define	SORDERIDENTIFIER_H

#include "../Terminals/Terminal.h"

class Identifier : public Terminal{
public:
	/** Create an instance of identifier */
	Identifier(char* name, unsigned int length, SourcePosition pos) : 
		Terminal(TOKEN_id, pos),
		_name(name, length)
	{}
	virtual void accept(Visitor* v);
	/** Gets the name of this identifier */
	const string& name() const{
		return this->_name;
	}

private:
	string _name;
};

#endif	/* SORDERIDENTIFIER_H */

