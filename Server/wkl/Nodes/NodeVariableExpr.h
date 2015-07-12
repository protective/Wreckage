/* 
 * File:   NodeVariableExpr.h
 * Author: karsten
 *
 * Created on 8. september 2014, 22:07
 */

#ifndef SORDERNODEVARIABLEEXPR_H
#define	SORDERNODEVARIABLEEXPR_H

#include "NodeExpr.h"
#include "NodeVariable.h"

class NodeVariableExpr : public NodeExpr{
public:
	NodeVariableExpr(NodeVariable* var) : NodeExpr(var->id()->pos()) {
		_var = var;
		_type = NULL;
	}
	
	virtual void accept(Visitor* v);
	NodeVariable* var(){
		return _var;
	}
	TypeDenoter* getType(){
		return _type;
	}
	void setType(TypeDenoter* type){
		_type = type;
	}
private:
	NodeVariable* _var;
	TypeDenoter* _type;
};

#endif	/* SORDERNODEVARIABLEEXPR_H */

