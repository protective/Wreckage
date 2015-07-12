/* 
 * File:   NodeVardecl.h
 * Author: karsten
 *
 * Created on 4. september 2014, 22:48
 */

#ifndef SORDERNODEVARDECLSTMT_H
#define	SORDERNODEVARDECLSTMT_H

#include "NodeStmt.h"
#include "NodeExpr.h"

class NodeVardeclStmt : public NodeStmt {
public:
	NodeVardeclStmt(TypeDenoter* type, Identifier* id, NodeExpr* expr, NodeStmt* next):
	NodeStmt(next){
		_expr = expr;
		_id = id;
		_type = type;
	}
	Identifier* variable(){
		return this->_id;
	}
	/** Getter for the expr */
	NodeExpr* expr(){
		return this->_expr;
	}
	virtual void accept(Visitor* v);
	virtual TypeDenoter* getType(){return _type;}
	virtual void setType(TypeDenoter* type){_type = type;}
	virtual ~NodeVardeclStmt(){}
private:
	NodeExpr* _expr;
	Identifier* _id;
	TypeDenoter* _type;
};

#endif	/* SORDERNODEVARDECLSTMT_H */

