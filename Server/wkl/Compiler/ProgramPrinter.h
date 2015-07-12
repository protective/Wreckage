/* 
 * File:   SOrderProgamPrinter.h
 * Author: karsten
 *
 * Created on 11. september 2014, 19:44
 */

#ifndef SPROGARMPRINTER_H
#define	SPROGARMPRINTER_H

#include "Compiler.h"
#include "systemCallLib.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <inttypes.h>
namespace wkl {
	void printProgram(ofstream& out, PROGRAM& p, map<uint32_t, uint32_t> interruptshandlers);
	string toHex(uint32_t hex, uint32_t pad);
	string tabPad(string topad, uint32_t len);
	void printProgram(ofstream& out, PROGRAM& p, map<uint32_t, uint32_t> interruptshandlers);
}

#endif	/* SPROGARMPRINTER_H */

