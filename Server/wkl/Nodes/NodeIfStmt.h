/* 
 * File:   NodeIfStmt.h
 * Author: karsten
 *
 * Created on 4. september 2014, 23:29
 */

#ifndef SORDERNODEIFSTMT_H
#define	SORDERNODEIFSTMT_H

#include "NodeStmt.h"

class NodeIfStmt : public NodeStmt {
public:
	NodeIfStmt(NodeExpr* condition, NodeStmt* ifStmt, NodeStmt* elseStmt, NodeStmt* next):
	NodeStmt(next){
		_condition = condition;
		_ifStmt = ifStmt;
		_elseStmt = elseStmt;
	}
	NodeExpr* condition(){return _condition;}
	NodeStmt* ifBlock(){return _ifStmt;}
	NodeStmt* elseBlock(){return _elseStmt;}
	virtual void accept(Visitor* v);
	virtual ~NodeIfStmt(){}
private:
NodeExpr* _condition;
NodeStmt* _ifStmt;
NodeStmt* _elseStmt;
};

#endif	/* SORDERNODEIFSTMT_H */

