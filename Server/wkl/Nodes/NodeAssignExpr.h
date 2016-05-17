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

#include "../Terminals/Terminal.h"

class NodeAssignExpr : public NodeExpr {
public:
	NodeAssignExpr(NodeVariable* assignee, Terminal* appliedOperator, NodeExpr* expresion) : NodeExpr(assignee->id()->pos()) {
		_assignee = assignee;
		_expresion = expresion;
		_appliedOperator = appliedOperator;
	}
	NodeExpr* expr(){return _expresion;}
	virtual TypeDenoter* getType(){return _expresion->getType();}
	
	NodeVariable* assignee(){return _assignee;}
	
	/** Get the operator applied */
	Terminal* appliedOperator(){
		return _appliedOperator;
	}
	
	virtual void accept(Visitor* v);
	virtual ~NodeAssignExpr(){}
private:
	NodeVariable* _assignee;
	NodeExpr* _expresion;
	Terminal* _appliedOperator;
};	


#endif	/* SORDERNODEASSIGNEXPR_H */

