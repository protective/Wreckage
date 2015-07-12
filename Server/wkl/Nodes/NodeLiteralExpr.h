/* 
 * File:   NodeLiteralExpr.h
 * Author: karsten
 *
 * Created on 8. september 2014, 21:55
 */

#ifndef SORDERNODELITERALEXPR_H
#define	SORDERNODELITERALEXPR_H

#include "NodeExpr.h"
#include "../Terminals/Terminal.h"
class NodeLiteralExpr : public NodeExpr {
public:
	NodeLiteralExpr(Terminal* literal) : NodeExpr(literal->pos()) {
		this->_literal = literal;
	}
	virtual void accept(Visitor* v);
	Terminal* literal(){
		return this->_literal;
	}
	virtual TypeDenoter* getType(){return _type;}
	void setType(TypeDenoter* type){
		_type = type;
	}
	virtual ~NodeLiteralExpr(){}
private:
	Terminal* _literal;
	NodeExpr* _expr;
	TypeDenoter* _type;	
};

#endif	/* SORDERNODELITERALEXPR_H */

