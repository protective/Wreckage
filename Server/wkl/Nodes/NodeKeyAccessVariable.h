/* 
 * File:   NodeKeyAccessVariable.h
 * Author: karsten
 *
 * Created on 15. marts 2016, 23:16
 */

#ifndef NODEKEYACCESSVARIABLE_H
#define	NODEKEYACCESSVARIABLE_H

#include "NodeExpr.h"
#include "NodeVariable.h"

class NodeKeyAccessVariable : public NodeVariable{
public:
	NodeKeyAccessVariable(Identifier* id, NodeExpr* key) :
	NodeVariable(id) {
		_key = key;
		_type = NULL;
	}

	virtual void accept(Visitor* v);

	NodeExpr* key(){
		return _key;
	}
	TypeDenoter* getType(){
		return _type;
	}
	void setType(TypeDenoter* type){
		_type = type;
	}
private:
	NodeExpr* _key;
	TypeDenoter* _type;
};



#endif	/* NODEKEYACCESSVARIABLE_H */

