/* 
 * File:   NodeWhileStmt.h
 * Author: karsten
 *
 * Created on 14. september 2014, 11:53
 */

#ifndef SORDERNODEWHILESTMT_H
#define	SORDERNODEWHILESTMT_H


#include "NodeStmt.h"

class NodeWhileStmt : public NodeStmt {
public:
	NodeWhileStmt(NodeExpr* condition, NodeStmt* body, NodeStmt* next):
	NodeStmt(next){
		_condition = condition;
		_body = body;
	}
	NodeExpr* condition(){return _condition;}
	/** Get the body */
	NodeStmt* body(){
	    return _body;
	}
	virtual void accept(Visitor* v);
	virtual ~NodeWhileStmt(){}
private:
    NodeExpr* _condition;
    NodeStmt* _body;
};


#endif	/* SORDERNODEWHILESTMT_H */

