
#include "../Utils/Visitor.h"
#include "NodeTupDref.h"
void Terminal::accept(Visitor* v){
	v->visit(this);
}
void Node::accept(Visitor* v){
	v->visit(this);
}
void NodeAssignExpr::accept(Visitor* v){
	v->visit(this);
}
void NodeTupAssignStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeExpr::accept(Visitor* v){
	v->visit(this);
}
void NodeExprStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeRtnStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeIfStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeLiteralExpr::accept(Visitor* v){
	v->visit(this);
}
void NodeStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeVardeclStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeOutdeclStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeIndeclStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeVariable::accept(Visitor* v){
	v->visit(this);
}
void NodeAttributeAccessVariable::accept(Visitor* v){
	v->visit(this);
}
void NodeVariableExpr::accept(Visitor* v){
	v->visit(this);
}
void Identifier::accept(Visitor* v){
	v->visit(this);
}
void IntegerLiteral::accept(Visitor* v){
	v->visit(this);
}
void BinaryOperatorExpr::accept(Visitor* v){
	v->visit(this);
}
void NodeWhileStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeForEachStmt::accept(Visitor* v){
	v->visit(this);
}
void NodeArg::accept(Visitor* v){
	v->visit(this);
}
void NodeTupDref::accept(Visitor* v){
	v->visit(this);
}
void NodeCallExpr::accept(Visitor* v){
	v->visit(this);
}

void TypeDenoter::accept(Visitor* v){
	v->visit(this);
}

void NodeTop::accept(Visitor* v){
	v->visit(this);
}

void NodeVardecTop::accept(Visitor* v){
	v->visit(this);
}

void NodeParam::accept(Visitor* v){
	v->visit(this);
}

void NodeMethod::accept(Visitor* v){
	v->visit(this);
}