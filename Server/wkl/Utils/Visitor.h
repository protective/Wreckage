/* 
 * File:   Visitor.h
 * Author: karsten
 *
 * Created on 9. september 2014, 21:21
 */

#ifndef SORDERVISITOR_H
#define	SORDERVISITOR_H




#include "../Nodes/Nodes.h"
#include "../Terminals/Terminals.h"
using namespace wkl;
class Visitor{
public:
	virtual void visit(Terminal* node) = 0;
	virtual void visit(Node* node) = 0;
	virtual void visit(NodeAssignExpr* node) = 0;
	virtual void visit(NodeTupAssignStmt* node) = 0;
	virtual void visit(NodeExpr* node) = 0;
	virtual void visit(NodeExprStmt* node) = 0;
	virtual void visit(NodeRtnStmt* node) = 0;
	virtual void visit(NodeIfStmt* node) = 0;
	virtual void visit(NodeWhileStmt* node) = 0;
	virtual void visit(NodeLiteralExpr* node) = 0;
	virtual void visit(NodeStmt* node) = 0;
	virtual void visit(NodeVardeclStmt* node) = 0;
	virtual void visit(NodeOutdeclStmt* node) = 0;
	virtual void visit(NodeIndeclStmt* node) = 0;
	virtual void visit(NodeVariable* node) = 0;
	virtual void visit(NodeAttributeAccessVariable* node) = 0;
	virtual void visit(NodeVariableExpr* node) = 0;
	virtual void visit(Identifier* node) = 0;
	virtual void visit(IntegerLiteral* node) = 0;
	virtual void visit(BinaryOperatorExpr* node) = 0;
	virtual void visit(NodeArg* node) = 0;
	virtual void visit(NodeTupDref* node) = 0;
	virtual void visit(NodeCallExpr* node) = 0;
	virtual void visit(TypeDenoter* node) = 0;
	virtual void visit(NodeMethod* node) = 0;
	virtual void visit(NodeParam* node) = 0;
	virtual void visit(NodeTop* node) = 0;
	virtual void visit(NodeVardecTop* node) = 0;
};


#endif	/* SORDERVISITOR_H */

