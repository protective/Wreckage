/* 
 * File:   NodeVariable.h
 * Author: karsten
 *
 * Created on 6. september 2014, 00:50
 */

#ifndef SORDERNODEVARIABLE_H
#define	SORDERNODEVARIABLE_H

#include "Node.h"
#include "../Terminals/Identifier.h"

class NodeVariable : public Node {
public:
	NodeVariable(Identifier* id){
		_id = id;
	}
	virtual void accept(Visitor* v);
	Identifier* id(){
		return _id;
	}

	virtual ~NodeVariable(){}
private:
Identifier* _id;
};

#endif	/* SORDERNODEVARIABLE_H */

