/* 
 * File:   DotBuilder.cpp
 * Author: karsten
 * 
 * Created on 9. september 2014, 21:54
 */

#include "DotBuilder.h"


#include <sstream>


void DotBuilder::visit(Node* node){
	
}

void DotBuilder::visit(Identifier* node) { 
	string msg("Id: " + node->name());
	printNode(msg);
}
void DotBuilder::visit(IntegerLiteral* node) {
	//Small hack to convert int to string
	stringstream sout;
	sout << node->value();
	
	string msg("Int: " + sout.str());
	printNode(msg);
}

void DotBuilder::visit(NodeLiteralExpr* node){
	node->literal()->accept(this);
}

void DotBuilder::visit(NodeVardeclStmt* node){
	int myId = printNode("VarDeclaration");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->variable()->accept(this);
	parentId = myId;
	if(node->getType()){
		cerr<<"accept type"<<endl;
		node->getType()->accept(this);
	}
	if(node->expr() != NULL){
		parentId = myId;
		node->expr()->accept(this);
	}
}

void DotBuilder::visit(NodeOutdeclStmt* node){
	int myId = printNode("NodeOutdeclStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->variable()->accept(this);
	parentId = myId;
	if(node->expr() != NULL){
		parentId = myId;
		node->expr()->accept(this);
	}
}

void DotBuilder::visit(NodeIndeclStmt* node){
	int myId = printNode("NodeIndeclStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->variable()->accept(this);
}


void DotBuilder::visit(NodeIfStmt* node) { 
	int myId = printNode("IfStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->condition()->accept(this);
	parentId = myId;
	node->ifBlock()->accept(this);
	if(node->elseBlock() != NULL){
		parentId = myId;
		node->elseBlock()->accept(this);
	}
}

void DotBuilder::visit(NodeExprStmt* node) {
	int myId = printNode("ExprStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->expr()->accept(this);
}


void DotBuilder::visit(NodeRtnStmt* node) {
	int myId = printNode("NodeRtnStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->expr()->accept(this);
}

void DotBuilder::visit(NodeVariable* node) { 
	int myId = printNode("Variable");
	//Visit children
	parentId = myId;
	node->id()->accept(this);
}

void DotBuilder::visit(NodeAssignExpr* node) { 
	int myId = printNode("AssignmentExpr");
	//Visit children
	parentId = myId;
	node->assignee()->accept(this);
	parentId = myId;
	if(node->getType())
		node->getType()->accept(this);
	parentId = myId;
	node->value()->accept(this);
}

void DotBuilder::visit(NodeTupAssignStmt* node) { 
	int myId = printNode("NodeTupAssignStmt");
	//Visit children
	parentId = myId;
	node->assignee()->accept(this);
	parentId = myId;
	if(node->getType())
		node->getType()->accept(this);
	parentId = myId;
	node->expr()->accept(this);
}

void DotBuilder::visit(NodeVariableExpr* node) { 
	int myId = printNode("VariableExpr");
	//Visit children
	parentId = myId;
	if(node->getType())
		node->getType()->accept(this);
	parentId = myId;
	node->var()->accept(this);
}

void DotBuilder::visit(NodeAttributeAccessVariable* node) { 
	int myId = printNode("AttributeAccessVariable");
	//Visit children
	parentId = myId;
	if(node->id())
		node->id()->accept(this);
	parentId = myId;
	node->attributeHolder()->accept(this);
}

void DotBuilder::visit(Terminal* node) { 
	string msg("Terminal: " + node->toString());
	printNode(msg);
}

void DotBuilder::visit(NodeExpr* node) { 
	cerr<<"ERROR DotBuilder::visit(NodeExpr* node)"<<endl;
}
void DotBuilder::visit(NodeStmt* node) {
	cerr<<"ERROR DotBuilder::visit(NodeStmt* node)"<<endl;
}

void DotBuilder::visit(BinaryOperatorExpr* node) { 
	int myId = printNode("BinaryOperation");
	//Visit children
	parentId = myId;
	node->firstOperand()->accept(this);
	parentId = myId;
	node->appliedOperator()->accept(this);
	parentId = myId;
	node->secondOperand()->accept(this);
}


void DotBuilder::visit(NodeWhileStmt* node) { 
	int myId = printNode("WhileStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->condition()->accept(this);
	parentId = myId;
	node->body()->accept(this);
}

void DotBuilder::visit(NodeForEachStmt* node) { 
	int myId = printNode("ForEachStmt");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->var()->accept(this);
	parentId = myId;
	node->expr()->accept(this);
	parentId = myId;
	node->block()->accept(this);
}

void DotBuilder::visit(NodeArg* node) { 
	int myId = printNode("ArgNode");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->expr()->accept(this);
}

void DotBuilder::visit(NodeTupDref* node) { 
	int myId = printNode("NodeTupDref");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->var()->accept(this);
}


void DotBuilder::visit(NodeCallExpr* node) { 
	int myId = printNode("CallExpr");
	//Visit children
	parentId = myId;
	node->callee()->accept(this);
	if(node->args()){
		parentId = myId;
		node->args()->accept(this);
	}
}

void DotBuilder::visit(TypeDenoter* node) {
	cerr<<"dot TypeDenoter"<<endl;
	string msg("type: " + node->toString() + " size: " + node->byteSizeToString());
	printNode(msg);
}

void DotBuilder::visit(NodeMethod* node){
	int myId = printNode("Method node");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->variable()->accept(this);
	parentId = myId;
	if(node->getType()){
		//cerr<<"accept type"<<endl;
		//node->getType()->accept(this);
	}else
		cerr<<"ERROR NodeMethod type NULL"<<endl;
	if(node->param() != NULL){
		parentId = myId;
		node->param()->accept(this);
	}
	if(node->block() != NULL){
		parentId = myId;
		node->block()->accept(this);
	}
	
}
void DotBuilder::visit(NodeParam* node){
	int myId = printNode("ParamNode");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->id()->accept(this);
	parentId = myId;
	if(node->type() != NULL)
		node->type()->accept(this);
}
void DotBuilder::visit(NodeTop* node){
	int myId = printNode("Top Node");
	if(node->next() != NULL)
		node->next()->accept(this);
}
void DotBuilder::visit(NodeVardecTop* node){
	int myId = printNode("TopVarDeclaration");
	//Visit next
	if(node->next() != NULL)
		node->next()->accept(this);
	//Visit children
	parentId = myId;
	node->variable()->accept(this);
	parentId = myId;
	if(node->getType()){
		cerr<<"accept type"<<endl;
		node->getType()->accept(this);
	}else
		cerr<<"ERROR type NULL"<<endl;
	if(node->expr() != NULL){
		parentId = myId;
		node->expr()->accept(this);
	}
	
}



void DotBuilder::visit(NodeDictExpr* node){
	int myId = printNode("NodeDictExpr");

	parentId = myId;
	
	if(node->getType() != NULL)
		node->getType()->accept(this);
	parentId = myId;
	
	if(node->pair()){
		cerr<<"accept pair"<<endl;
		node->pair()->accept(this);
	}else
		cerr<<"ERROR type NULL"<<endl;
	
}


void DotBuilder::visit(NodePair* node){
	int myId = printNode("NodePair");
	//Visit next
	parentId = myId;

	if(node->exprKey() != NULL)
		node->exprKey()->accept(this);
	//Visit children
	parentId = myId;
	
	if(node->exprVal() != NULL)
		node->exprVal()->accept(this);
	
	//Visit children
	parentId = myId;
	
	if(node->next() != NULL)
		node->next()->accept(this);
	
}

