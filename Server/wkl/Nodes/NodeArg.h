/* 
 * File:   NodeArg.h
 * Author: karsten
 *
 * Created on 14. september 2014, 14:21
 */

#ifndef SORDERNODEARG_H
#define	SORDERNODEARG_H

#include "NodeExpr.h"


class NodeArg : public Node{
public:
	NodeArg(NodeExpr* expr, NodeArg* next = NULL) {
	    _expr = expr;
	    _next = next;
	}
	/** Get the expression for this argument */
	NodeExpr* expr(){
	    return _expr;
	}
	NodeArg* next(){return _next;}
	void setNext(NodeArg* next){_next = next;}
	void accept(Visitor* v);
private:
	NodeExpr* _expr;
	NodeArg* _next;
};

#endif	/* SORDERNODEARG_H */

