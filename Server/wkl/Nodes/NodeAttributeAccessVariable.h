#ifndef ATTRIBUTEACCESSVARIABLE_H
#define ATTRIBUTEACCESSVARIABLE_H

#include "NodeVariable.h"
#include "NodeExpr.h"
/** Attribute access variable */
class NodeAttributeAccessVariable : public NodeVariable{
public:
	NodeAttributeAccessVariable(NodeExpr* attributeHolder, Identifier* attribute) : NodeVariable(attribute) {
		_attributeHolder = attributeHolder;
	}
	/** Get the expression the attribute is accessed on */
	NodeExpr* attributeHolder(){
		return _attributeHolder;
	}
	void accept(Visitor* v);
private:
	Identifier* _attribute;
	NodeExpr* _attributeHolder;
};

#endif /* ATTRIBUTEACCESSVARIABLE_H */
