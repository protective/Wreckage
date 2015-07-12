
#ifndef NODERTNSTMT_H
#define	NODERTNSTMT_H

#include "NodeStmt.h"
#include "NodeExpr.h"

class NodeRtnStmt : public NodeStmt {
public:
	NodeRtnStmt(NodeExpr* expr):
	NodeStmt(NULL){
		_expr = expr;

	}
	NodeExpr* expr(){return _expr;}

	virtual void accept(Visitor* v);
	virtual ~NodeRtnStmt(){}
private:
NodeExpr* _expr;

};

#endif	/* NODERTNSTMT_H */

