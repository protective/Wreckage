/* 
 * File:   NodeAssingExpr.h
 * Author: karsten
 *
 * Created on 6. september 2014, 00:43
 */

#ifndef SORDERNODEASSIGNEXPR_H
#define	SORDERNODEASSIGNEXPR_H

#include "NodeExpr.h"
#include "NodeVariable.h"


class NodeAssignExpr : public NodeExpr {
public:
	NodeAssignExpr(NodeVariable* assignee, NodeExpr* expresion) : NodeExpr(assignee->id()->pos()) {
		_assignee = assignee;
		_expresion = expresion;
	}
	NodeExpr* value(){return _expresion;}
	virtual TypeDenoter* getType(){return _expresion->getType();}
	
	NodeVariable* assignee(){return _assignee;}
	virtual void accept(Visitor* v);
	virtual ~NodeAssignExpr(){}
private:
	NodeVariable* _assignee;
	NodeExpr* _expresion;
};


#endif	/* SORDERNODEASSIGNEXPR_H */

