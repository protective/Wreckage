
#ifndef NODETUPASSIGNSTMT_H
#define	NODETUPASSIGNSTMT_H

#include "NodeExpr.h"
#include "NodeVariable.h"
#include "NodeTupDref.h"
#include "NodeStmt.h"


class NodeTupAssignStmt : public NodeStmt {
public:
	NodeTupAssignStmt(NodeTupDref* assignee, NodeExpr* expresion) : NodeStmt(NULL) {
		_assignee = assignee;
		_expresion = expresion;
	}
	NodeExpr* expr(){return _expresion;}
	virtual TypeDenoter* getType(){return _expresion->getType();}
	
	NodeTupDref* assignee(){return _assignee;}
	virtual void accept(Visitor* v);
	virtual ~NodeTupAssignStmt(){}
private:
	NodeTupDref* _assignee;
	NodeExpr* _expresion;
};


#endif	/* NODETUPASSIGNSTMT_H */

