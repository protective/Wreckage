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

#include "../Terminals/Terminal.h"

class NodeVardeclStmt : public NodeStmt {
public:
	NodeVardeclStmt(Identifier* id, Terminal* appliedOperator, NodeExpr* expr, NodeStmt* next):
	NodeStmt(next){
		_id = id;
		_expr = expr;
		_appliedOperator = appliedOperator;
		
	}
	/** Get the operator applied */
	Terminal* appliedOperator(){
		return _appliedOperator;
	}
	
	Identifier* variable(){
		return this->_id;
	}
	/** Getter for the expr */
	NodeExpr* expr(){
		return this->_expr;
	}
	virtual void accept(Visitor* v);
	virtual ~NodeVardeclStmt(){}
private:
	NodeExpr* _expr;
	Identifier* _id;
	Terminal* _appliedOperator;
};

#endif	/* SORDERNODEVARDECLSTMT_H */

