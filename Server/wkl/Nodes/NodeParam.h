/* 
 * File:   ParamNode.h
 * Author: karsten
 *
 * Created on 19. september 2014, 18:21
 */

#ifndef NODEPARAM_H
#define	NODEPARAM_H

#include "../Terminals/Identifier.h"
#include "../Types/TypeDenoter.h"

namespace wkl {
class NodeParam : public Node{
public:
	NodeParam(TypeDenoter* type, Identifier* id) {
		_type = type;
		_id = id;
		_next = NULL;
	}
	NodeParam(TypeDenoter* type, Identifier* id, NodeParam* next) {
		_type = type;
		_id = id;
		_next = next;
	}
	TypeDenoter* type(){
		return _type;
	}
	Identifier* id(){
		return _id;
	}
	NodeParam* next(){return _next;}
	void setNext(NodeParam* next){_next = next;}
	void accept(Visitor* v);
	virtual ~NodeParam(){}
private:
	TypeDenoter* _type;
	Identifier* _id;
	NodeParam* _next;
};
}
#endif	/* NODEPARAM_H */

