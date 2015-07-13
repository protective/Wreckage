/* 
 * File:   SOrdreProgram.cpp
 * Author: karsten
 * 
 * Created on 5. september 2014, 17:48
 */

#include "Program.h"

Program::Program(string path){
	_name = path;
	Compiler* c = new Compiler(path); 
	c->compile(this);
	delete c;
	
}


Program::Program(const Program* p){
	_name = p->_name;
	_program = p->_program;
	_interruptHandlers = p->_interruptHandlers;
}

Program::~Program() {
}

