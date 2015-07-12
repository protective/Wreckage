
#ifndef NODETUBEDREFARG_H
#define	NODETUBEDREFARG_H

#include "NodeExpr.h"


class NodeTupDref : public Node{
public:
	NodeTupDref(NodeVariable* var, NodeTupDref* next = NULL) {
	    _var = var;
	    _next = next;
	}
	/** Get the variable for this argument */
	NodeVariable* var(){
	    return _var;
	}
	NodeTupDref* next(){return _next;}
	void setNext(NodeTupDref* next){_next = next;}
	void accept(Visitor* v);
private:
	NodeVariable* _var;
	NodeTupDref* _next;
};

#endif	/* SORDERNODEARG_H */

