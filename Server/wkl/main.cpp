/* 
 * File:   main.cpp
 * Author: karsten
 *
 * Created on 9. juli 2015, 22:06
 */
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <vector>

#include <list>
#include <vector>
#include <stack>
#include <map>

#include "Lexer.h"
#include "Parser.h"
#include "Nodes/Node.h"
#include "Utils/Visitor.h"
#include "Utils/DotBuilder.h"
#include "Utils/Visitor.h"
#include "Utils/Variable.h"
#include "Program.h"
#include "ProgramExecutor.h"

//#include "ProgramPrinter.h"

using namespace std;

/*
 * 
 */

wkl::Variable doDamage( SObj* obj, void* arg){
	cerr<<"HELLO WORLD"<<endl;
	wkl::Variable u;
	u.v = 123456;
	u.t = new wkl::VObject();
	u.t->_vector.resize(2);
	u.t->_vector[0] = 42;
	u.t->_vector[1] = 1337;
	return u;
}


int main(int argc, char** argv) {
	stringstream s;
	s<<"../testPrograms/"<<"test_pow"<<".wkl";
	cerr<<s.str()<<endl;
	ifstream is(s.str().c_str());
	//ifstream is("testPrograms/test_pow.wkl");
	/*
	Lexer lexer(&is);
	
	Node* result = parse(&lexer);

	//TypeChecker typecheck;
	
	//result->accept(&typecheck);
	
	s.str("");
	s.clear();
	s<<"../testPrograms/"<<"test_pow"<<".dot";
	cerr<<s.str()<<endl;
	ofstream dotfile(s.str().c_str());
	DotBuilder dot(dotfile);
	dot.visit(result);
	result->accept(&dot);
	dot.finalise();
	dotfile.flush();
	*/
	Program* p = new Program("../testPrograms/test_pow.wkl");
	
	map<uint32_t, systemCallFunc> syscall;
	syscall[1] = doDamage;
	list<uint32_t> stack;
	stack.push_back(0x0); //pc EOP
	stack.push_back(0xBBBB); //retVal
	ProgramExecutor* e = new ProgramExecutor("test", NULL, p, syscall);
	
	map<uint32_t, int32_t> envContext;
	envContext[1] = 9000;
	e->run(0,1,stack, envContext);
	
	return 0;
}

