
#ifndef NODEPAIR_H
#define	NODEPAIR_H

#include "NodeExpr.h"

class NodePair : public Node{
public:
	NodePair(NodeExpr* exprKey, NodeExpr* exprVal, NodePair* next = NULL) {
	    _exprKey = exprKey;
	    _exprVal = exprVal;
		_next = next;
	}
	/** Get the expression for this argument */
	NodeExpr* exprKey(){
	    return _exprKey;
	}
	NodeExpr* exprVal(){
	    return _exprVal;
	}
	NodePair* next(){return _next;}
	void setNext(NodePair* next){_next = next;}
	void accept(Visitor* v);
private:
	NodeExpr* _exprKey;
	NodeExpr* _exprVal;
	NodePair* _next;
};

#endif	/* NODEPAIR_H */

