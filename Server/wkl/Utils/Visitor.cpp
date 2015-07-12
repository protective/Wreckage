/* 
 * File:   Visitor.cpp
 * Author: karsten
 * 
 * Created on 9. september 2014, 21:21
 */

#include "Visitor.h"

void  Visitor::visit(NodeAssignExpr* node){};
void  Visitor::visit(NodeExpr* node){};
void  Visitor::visit(NodeExprStmt* node){};
void  Visitor::visit(NodeIfStmt* node){};
void  Visitor::visit(NodeWhileStmt* node){};
void  Visitor::visit(NodeLiteralExpr* node){};
void  Visitor::visit(NodeStmt* node){};
void  Visitor::visit(NodeVardeclStmt* node){};
void  Visitor::visit(NodeOutdeclStmt* node){};
void  Visitor::visit(NodeVariable* node){};
void  Visitor::visit(NodeVariableExpr* node){};
void  Visitor::visit(Identifier* node){};
void  Visitor::visit(IntegerLiteral* node){};
void  Visitor::visit(BinaryOperatorExpr* node){};
void  Visitor::visit(TypeDenoter* node){};
void  Visitor::visit(NodeTop* node){};
void  Visitor::visit(NodeVardecTop* node){};
void  Visitor::visit(NodeParam* node){};
void  Visitor::visit(NodeMethod* node){};