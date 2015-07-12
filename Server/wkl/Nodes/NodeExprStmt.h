/* 
 * File:   NodeExprStmt.h
 * Author: karsten
 *
 * Created on 7. september 2014, 19:25
 */

#ifndef SORDERNODEEXPRSTMT_H
#define	SORDERNODEEXPRSTMT_H

#include "NodeStmt.h"

class NodeExprStmt : public NodeStmt {
public:
	NodeExprStmt(NodeExpr* expr):
	NodeStmt(NULL){
		_expr = expr;

	}
	NodeExpr* expr(){return _expr;}

	virtual void accept(Visitor* v);
	virtual ~NodeExprStmt(){}
private:
NodeExpr* _expr;

};

#endif	/* SORDERNODEEXPRSTMT_H */

