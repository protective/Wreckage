

#ifndef NODEFOREACHSTMT_H
#define	NODEFOREACHSTMT_H

#include "NodeStmt.h"
#include "../Terminals/Identifier.h"
#include "NodeExpr.h"

class NodeForEachStmt : public NodeStmt {
public:
	NodeForEachStmt(Identifier* var, NodeExpr* expr, NodeStmt* block,  NodeStmt* next):
	NodeStmt(next){
		_var = var;
		_expr = expr;
		_block = block;
	}
	Identifier* var(){return _var;}
	NodeExpr* expr(){return _expr;}
	NodeStmt* block(){return _block;}
	virtual void accept(Visitor* v);
	virtual ~NodeForEachStmt(){}
private:
	Identifier* _var;
	NodeExpr* _expr;
	NodeStmt* _block;
};


#endif	/* NODEFOREACHSTMT_H */

