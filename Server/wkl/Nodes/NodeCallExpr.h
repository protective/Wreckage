/* 
 * File:   NodeCallExpr.h
 * Author: karsten
 *
 * Created on 14. september 2014, 14:22
 */

#ifndef SORDERNODECALLEXPR_H
#define	SORDERNODECALLEXPR_H

#include "NodeExpr.h"
#include "NodeVariableExpr.h"


/** Call expression in the abstract syntax tree */
class NodeCallExpr : public NodeExpr{
public:
	NodeCallExpr(NodeVariableExpr* callee, NodeArg* args) : NodeExpr(callee->pos()){
		_callee = callee;
		_args = args;
	}
	/** Method or function being called */
	NodeVariableExpr* callee(){
		return _callee;
	}
	/** Arguments for the call 
 	 * Note that ArgNode forms a single linked list
	 */
	virtual TypeDenoter* getType(){return NULL;}

	
	NodeArg* args(){
		return _args;
	}
	void accept(Visitor* v);
private:
	NodeVariableExpr* _callee;
	NodeArg* _args;
};

#endif	/* SORDERNODECALLEXPR_H */

