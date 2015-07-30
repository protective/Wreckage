/* 
 * File:   DotBuilder.h
 * Author: karsten
 *
 * Created on 9. september 2014, 21:54
 */

#ifndef SORDERDOTBUILDER_H
#define	SORDERDOTBUILDER_H

class DotBuilder;

#include "Visitor.h"
#include <iostream>
#include <string>

using namespace std;
using namespace wkl;
class DotBuilder : public Visitor {
public:
	DotBuilder(ostream& output = cout) : out(output){
		//Print graph header
		out<<"graph \"\""<<endl;
		out<<"{"<<endl;
		out<<"#   node [fontsize=10,width=\".2\", height=\".2\", margin=0];"<<endl;
		out<<"#   graph[fontsize=8];"<<endl;
		out<<"label=\"test Graf\""<<endl;
		
		//Setup Id's
		int myId;
		nextId = 0;
		myId = nextId++;
		parentId = myId;
		//Print root
		out<<"n"<<myId<<" ;"<<endl; // Create my parent node
		out<<"n"<<myId<<" [label=\"Root\"] ;"<<endl; // Create my node
	}
	void visit(Node* node);
	void visit(Terminal* node);
	void visit(NodeAssignExpr* node);
	void visit(NodeTupAssignStmt* node);
	void visit(NodeExpr* node);
	void visit(NodeExprStmt* node);
	void visit(NodeRtnStmt* node);
	void visit(NodeIfStmt* node);
	void visit(NodeWhileStmt* node);
	void visit(NodeForEachStmt* node);
	void visit(NodeLiteralExpr* node);
	void visit(NodeStmt* node);
	void visit(NodeVardeclStmt* node);
	void visit(NodeOutdeclStmt* node);
	void visit(NodeIndeclStmt* node);
	void visit(NodeVariable* node);
	void visit(NodeAttributeAccessVariable* node);
	void visit(NodeVariableExpr* node);
	void visit(Identifier* node);
	void visit(IntegerLiteral* node);
	void visit(BinaryOperatorExpr* node);
	void visit(NodeArg* node);
	void visit(NodeTupDref* node);
	void visit(NodeCallExpr* node);
	void visit(TypeDenoter* node);
	void visit(NodeMethod* node);
	void visit(NodeParam* node);
	void visit(NodeTop* node);
	void visit(NodeVardecTop* node);
	void finalise(){
		out<<"}"<<endl;
	}
private:
	ostream& out;
	int nextId;
	int parentId;
	int printNode(const string& label){
		int myId = nextId++;
		out<<"n"<<parentId<<" -- n"<<myId<<" ;"<<endl;
		out<<"n"<<myId<<" [label=\""<<label<<"\"] ;"<<endl;
		return myId;
	}
};


#endif	/* SORDERDOTBUILDER_H */

