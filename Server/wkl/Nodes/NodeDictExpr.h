
#ifndef NODEDICTEXPR_H
#define	NODEDICTEXPR_H

#include "NodeExpr.h"
#include "NodePair.h"

class NodeDictExpr : public NodeExpr{
public:
	NodeDictExpr(NodePair* pair):
    NodeExpr(pair->exprKey()->pos()){
	    _pair = pair;
	    
	}
	/** Get the pair for this argument */
	NodePair* pair(){
	    return _pair;
	}

	void accept(Visitor* v);
private:
	NodePair* _pair;

};

#endif	/* NODEDICTEXPR_H */

