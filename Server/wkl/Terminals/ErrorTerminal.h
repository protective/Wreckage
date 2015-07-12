/* 
 * File:   ErrorTerminal.h
 * Author: karsten
 *
 * Created on 7. september 2014, 21:59
 */

#ifndef SORDERERRORTERMINAL_H
#define	SORDERERRORTERMINAL_H

#include "Terminal.h"

/** Error terminal in the AST*/
class ErrorTerminal : public Terminal{
public:
	/** Create new error terminal.
	  * This constructor is used by the parser. */
	ErrorTerminal(Terminal* unexpected) : Terminal(TOKEN_error, unexpected->pos()){
		this->_unexpected = unexpected;
	}
	/** Discard an error terminal.
	  * Used by the parser if the next terminal is unusable.*/
	void discard(Terminal* terminal){
		this->_discarded.push_back(terminal);
	}
	/** Returns the unexpected terminal which caused the error*/
	Terminal* unexpected(){
		return this->_unexpected;
	}
private:
	list<Terminal*> _discarded;
	Terminal* _unexpected; 
};


#endif	/* SORDERERRORTERMINAL_H */

