/* 
 * File:   SOrdreProgram.h
 * Author: karsten
 *
 * Created on 5. september 2014, 17:48
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <inttypes.h>
#include "Compiler/Compiler.h"

using namespace std;
class Program {
public:
	friend Compiler;
	Program(string name);

	PROGRAM& program(){return _program;}
	string name(){return _name;}

	map<uint32_t, uint32_t> getInterruptHandlers(){return _interruptHandlers;}
	virtual ~Program();
private:
	string _name;
	map<uint32_t, uint32_t> _interruptHandlers;
	PROGRAM _program;
};

#endif	/* PROGRAM_H */

