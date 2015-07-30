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
using namespace wkl;
/*
 * 
 */


int main(int argc, char** argv) {
	stringstream s;


	s.str("");
	s.clear();
	s<<"../testPrograms/"<<"test_pow"<<".dot";
	ofstream dotfile(s.str().c_str());
	
	s.str("");
	s.clear();
	s<<"../testPrograms/"<<"test_pow"<<".asm";
	ofstream asmfile(s.str().c_str());
	Program* p = new Program("../testPrograms/test_pow.wkl", true, asmfile, &dotfile);
	
	map<uint32_t, systemCallFunc> syscall;

	list<uint32_t> stack;
	stack.push_back(0x0); //pc EOP
	stack.push_back(0xBBBB); //retVal
	//ProgramExecutor* e = new ProgramExecutor("test", NULL, p, syscall);
	
	map<uint32_t, Variable> envContext;
	envContext[1] = 9000;
	//e->run(0,1,stack, envContext);
	
	return 0;
}

