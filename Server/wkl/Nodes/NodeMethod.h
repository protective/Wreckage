/* 
 * File:   MethodNode.h
 * Author: karsten
 *
 * Created on 19. september 2014, 18:20
 */

#ifndef NODEMETHOD_H
#define	NODEMETHOD_H

#include "NodeExpr.h"
#include "NodeTop.h"
#include "NodeStmt.h"
#include "NodeParam.h"
namespace wkl {
class NodeMethod : public NodeTop {
public:
	NodeMethod(TypeDenoter* type, Identifier* id, NodeParam* param,  NodeStmt* block):
	NodeTop(){
		_block = block;
		_id = id;
		_type = type;
		_param = param;
	}
	Identifier* variable(){
		return this->_id;
	}
	NodeStmt* block(){
		return this->_block;
	}
	NodeParam* param(){
		return this->_param;
	}
	virtual void accept(Visitor* v);
	virtual TypeDenoter* getType(){return _type;}
	virtual void setType(TypeDenoter* type){_type = type;}
	virtual ~NodeMethod(){}
private:
	NodeStmt* _block;
	NodeParam* _param;
	Identifier* _id;
	TypeDenoter* _type;
};
}

#endif	/* NODEMETHOD_H */

