/* 
 * File:   SignalRunProgram.h
 * Author: karsten
 *
 * Created on 28. juli 2015, 00:53
 */

#ifndef SIGNALRUNPROGRAM_H
#define	SIGNALRUNPROGRAM_H


#include "Signal.h"

struct SignalRunProgram : public Signal {
	SignalRunProgram(
			wkl::Program* program,
			map<wkl::Variable, wkl::Variable>* env,
			uint32_t functionId,
			uint32_t runRef
	):
	Signal(SIGNAL::runProgram){
		_program = program;
		_env = env;
		_functionId = functionId;
		_runRef = runRef;
		_retVar = NULL;
	}
	
	SignalRunProgram(
			wkl::Variable* retVar,
			uint32_t runRef
	):
	Signal(SIGNAL::runProgram){
		_retVar = retVar;
		_runRef = runRef;
	}
	
	SignalRunProgram(SignalRunProgram& s):
	Signal(s._type){
		_env = s._env;
		_functionId = s._functionId;
		_program = s._program;
		_runRef = s._runRef;
		_retVar = s._retVar;
	}
	map<wkl::Variable, wkl::Variable>* _env;
	wkl::Program* _program;
	uint32_t _functionId;
	uint32_t _runRef;
	wkl::Variable* _retVar;
};


#endif	/* SIGNALRUNPROGRAM_H */

