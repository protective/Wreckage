/* 
 * File:   Terminal.h
 * Author: karsten
 *
 * Created on 7. september 2014, 15:04
 */

#ifndef SORDERTERMINAL_H
#define	SORDERTERMINAL_H

#include <list>
#include <vector>
#include <stack>
#include <map>

#include "../Utils/SourcePosition.h"
#include "../Parser.h"
#include "../Nodes/Node.h"

/** A simple terminal with any data associated */
class Terminal : public Node{
public:
	/** Create a new instance of Terminal */
	Terminal(Token token, SourcePosition pos) : _pos(pos){
		this->_token = token;
	}
	/** Gets the token of this Terminal */
	Token token() const{
		return this->_token;
	}
	
	/** Gets the source position of this Terminal */
	SourcePosition pos() const{
		return this->_pos;
	}
    
	/** Convert the token of this Terminal to string */
	string toString() const {
		return TokenToString(token());
	}	
	/** Accept a visitor */
	void accept(Visitor* v);
private:
	Token _token;
	SourcePosition _pos;
};


#endif	/* SORDERTERMINAL_H */

