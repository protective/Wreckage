/* 
 * File:   VardecTop.h
 * Author: karsten
 *
 * Created on 19. september 2014, 18:39
 */

#ifndef VARDECTOP_H
#define	VARDECTOP_H

#include "NodeExpr.h"
#include "NodeTop.h"
namespace wkl {
class NodeVardecTop : public NodeTop {
public:
	NodeVardecTop(TypeDenoter* type, Identifier* id, NodeExpr* expr)
	{
		_expr = expr;
		_id = id;
		_type = type;
	}
	Identifier* variable(){
		return this->_id;
	}
	/** Getter for the expr */
	NodeExpr* expr(){
		return this->_expr;
	}
	virtual void accept(Visitor* v);
	virtual TypeDenoter* getType(){return _type;}
	virtual void setType(TypeDenoter* type){_type = type;}
	virtual ~NodeVardecTop(){}
private:
	NodeExpr* _expr;
	Identifier* _id;
	TypeDenoter* _type;
};
}
#endif	/* VARDECTOP_H */

