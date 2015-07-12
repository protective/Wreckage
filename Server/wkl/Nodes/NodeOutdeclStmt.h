
#ifndef NODEOUTDECLSTMT_H
#define	NODEOUTDECLSTMT_H

#include "NodeStmt.h"
#include "NodeExpr.h"

class NodeOutdeclStmt : public NodeStmt {
public:
	NodeOutdeclStmt(Identifier* id, NodeExpr* expr, NodeStmt* next):
	NodeStmt(next){
		_expr = expr;
		_id = id;
	}
	Identifier* variable(){
		return this->_id;
	}
	/** Getter for the expr */
	NodeExpr* expr(){
		return this->_expr;
	}
	virtual void accept(Visitor* v);
	virtual TypeDenoter* getType(){return NULL;}
	virtual void setType(TypeDenoter* type){}
	virtual ~NodeOutdeclStmt(){}
private:
	NodeExpr* _expr;
	Identifier* _id;
};

#endif	/* NODEOUTDECLSTMT_H */

