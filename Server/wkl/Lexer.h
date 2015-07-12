#ifndef LEXER_H
#define LEXER_H

#define BUF_SIZE	4096

class Lexer;

#include <iostream>
#include "Utils/SourcePosition.h"

using namespace std;
class Terminal;
class Lexer{
public:
	/** Create lexer from input stream */
	Lexer(istream* input);
	/** Get next token from the lexer */
	Terminal* nextToken();
	/** Destruct and release buffer */
	~Lexer(){
		delete this->buffer;
	}
private:
	/** Fill the buffer */
	void fill();
	/** Current input stream */
	istream* input;
	/** Start of unread buffer contents */
	char* cursor;
	/** Marks the end of buffer contents */
	char* limit;
	/** Start of buffer contents */
	char* bufstart;
	/** Marks the end of last recognized token */
	char* marker;
	/** Current buffer */
	char* buffer;
	/** Current position in source */
	SourcePosition pos;
	/** Last indent */
	int indent;
	/** Indention change */
	int d_indent;
	/** Length of current token */
	int toklen;
	/** Return a newline token next*/
	bool throwNewline;
};

#endif /* LEXER_H */
