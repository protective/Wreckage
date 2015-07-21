/* 
 * File:   SOrdreProgram.cpp
 * Author: karsten
 * 
 * Created on 5. september 2014, 17:48
 */

#include "Program.h"

Program::Program(string scr, ostream& outAsm){
	_name = "testProgram";
	Compiler* c = new Compiler(scr); 
	c->compile(this, outAsm);
	delete c;
}

Program::Program(string path, bool fromFile, ostream& outAsm){
	_name = "testProgram";
	Compiler* c = new Compiler(path, fromFile); 
	c->compile(this, outAsm);
	delete c;
}

Program::Program(string name, const PROGRAM& praw){
	_name = name;
	_program = praw;
	
	uint32_t i = 0;
	for(wkl::INSTRUCTION& it : _program){
		if (OPCODE(it) == wkl::inst::FUN){
			_interruptHandlers[ARG(it)] = i;	
		}
		i++;
 	}

}

Program::Program(const Program* p){
	_name = p->_name;
	_program = p->_program;
	_interruptHandlers = p->_interruptHandlers;
}

Program::~Program() {
}

