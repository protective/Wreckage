#include "Lexer.h"
#include "Terminals/Terminals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <assert.h>

#define token 	bufstart

Lexer::Lexer(stringstream* input)
	: pos(1, 0) {
	this->input = input;
	indent = 0;
	d_indent = 0;
	buffer = new char[BUF_SIZE];
	bufstart = buffer;
	cursor = buffer;
	limit = buffer;
	marker = buffer;
	toklen = 0;
	fill();
}

void Lexer::fill(){
	assert(cursor==limit);
	//TODO: Handle the case below by extending the buffer
	assert(!(buffer==bufstart && buffer + BUF_SIZE == limit));

	//Move memory in the buffer
	int relative = bufstart - buffer;
	memmove(buffer,bufstart,limit-bufstart);
	
	//Move pointers
	bufstart -= relative;
	marker -= relative;
	cursor -= relative;
	limit -= relative;

	//Read data
	int reqbyte =  buffer + BUF_SIZE - limit;
	input->read(limit, reqbyte);
	limit += input->gcount();

	//Handle EOF and possible errors
	if(input->eof()){
		//*limit = 0x4; //eof
		uint8_t* tmp = (uint8_t*)limit;
		*tmp = 0x4;
	}else if(input->fail()){
		//TODO: Handle IO error
		fprintf(stderr, "Error reading input file!\n");
		exit(1);		
	}
}

Terminal* Lexer::nextToken(){

BEGIN:
	//Add offset from last token
	this->pos._col += toklen;
	//The DFA:
	{
	bufstart = marker;
	int accept = -1;
	goto START;
final:
	if(accept == -1)
		marker++;
	cursor = marker;
	{
		toklen = marker - bufstart;
	}
	switch(accept){
	case 0:
		{
		cerr<<"terminal def"<<endl; return new Terminal(TOKEN_def, pos);
		}
		break;
	case 1:
		{
		cerr<<"terminal if"<<endl; return new Terminal(TOKEN_if, pos);
		}
		break;
	case 2:
		{
		cerr<<"terminal while"<<endl; return new Terminal(TOKEN_while, pos);
		}
		break;
	case 3:
		{
		cerr<<"terminal for"<<endl; return new Terminal(TOKEN_for, pos);
		}
		break;
	case 4:
		{
		cerr<<"terminal in"<<endl; return new Terminal(TOKEN_in, pos);
		}
		break;
	case 5:
		{
		cerr<<"terminal out"<<endl; return new Terminal(TOKEN_out, pos);
		}
		break;
	case 6:
		{
		cerr<<"terminal return"<<endl; return new Terminal(TOKEN_return, pos);
		}
		break;
	case 7:
		{
		cerr<<"terminal assignment"<<endl; return new Terminal(TOKEN_assignment, pos);
		}
		break;
	case 8:
		{
		cerr<<"terminal eq"<<endl; return new Terminal(TOKEN_eq, pos);
		}
		break;
	case 9:
		{
		cerr<<"terminal neq"<<endl; return new Terminal(TOKEN_neq, pos);
		}
		break;
	case 10:
		{
		cerr<<"terminal comma"<<endl;return new Terminal(TOKEN_comma, pos);
		}
		break;
	case 11:
		{
		cerr<<"terminal dot"<<endl;return new Terminal(TOKEN_dot, pos);
		}
		break;
	case 12:
		{
		cerr<<"terminal plus"<<endl;return new Terminal(TOKEN_plus, pos);
		}
		break;
	case 13:
		{
		cerr<<"terminal minus"<<endl;return new Terminal(TOKEN_minus, pos);
		}
		break;
	case 14:
		{
		cerr<<"terminal semicolon"<<endl;return new Terminal(TOKEN_semicolon, pos);
		}
		break;
	case 15:
		{
		cerr<<"terminal colon"<<endl;return new Terminal(TOKEN_colon, pos);
		}
		break;
	case 16:
		{
		cerr<<"terminal leftp"<<endl;return new Terminal(TOKEN_left_p, pos);
		}
		break;
	case 17:
		{
		cerr<<"terminal rightp"<<endl;return new Terminal(TOKEN_right_p, pos);
		}
		break;
	case 18:
		{
		cerr<<"terminal leftcur"<<endl;return new Terminal(TOKEN_left_c, pos);
		}
		break;
	case 19:
		{
		cerr<<"terminal rightcur"<<endl;return new Terminal(TOKEN_right_c, pos);
		}
		break;
	case 20:
		{
		cerr<<"terminal leftcur"<<endl;return new Terminal(TOKEN_left_b, pos);
		}
		break;
	case 21:
		{
		cerr<<"terminal rightcur"<<endl;return new Terminal(TOKEN_right_b, pos);
		}
		break;
	case 22:
		{
		cerr<<"terminal id"<<endl;return new Identifier(token, toklen, pos);
		}
		break;
	case 23:
		{
		cerr<<"terminal int"<<endl;return IntegerFromDecimalString(token, toklen, pos);
		}
		break;
	case 24:
		{
		cerr<<"terminal eof"<<endl;return new Terminal(TOKEN_EOF, pos);
		}
		break;
	case 25:
		{
		cerr<<"space"<<endl;goto BEGIN;
		}
		break;
	case 26:
		{
		cerr<<"tab"<<endl;goto BEGIN;
		}
		break;
	case 27:
		{
		cerr<<"newline lf"<<endl;goto BEGIN;
		}
		break;
	case 28:
		{
		cerr<<"newline cr"<<endl;goto BEGIN;
		}
		break;
	default:
		{
		cerr<<"terminal ERROR"<<endl;return new Terminal(TOKEN_error, pos);
		}
		break;
	}
	bufstart = marker;
	goto START;
State3:
	cursor++;
	if(limit == cursor) fill();
	accept = 28;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State1:
	cursor++;
	if(limit == cursor) fill();
	accept = 24;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State21:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State44;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State5:
	cursor++;
	if(limit == cursor) fill();
	accept = 25;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State10:
	cursor++;
	if(limit == cursor) fill();
	accept = 10;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State40:
	cursor++;
	if(limit == cursor) fill();
	accept = 1;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State34:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State35;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State19:
	cursor++;
	if(limit == cursor) fill();
	accept = 21;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State26:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State29;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State2:
	cursor++;
	if(limit == cursor) fill();
	accept = 26;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State38:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State39;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State47:
	cursor++;
	if(limit == cursor) fill();
	accept = 9;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State39:
	cursor++;
	if(limit == cursor) fill();
	accept = 5;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State29:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State30;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State44:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State45;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State6:
	cursor++;
	if(limit == cursor) fill();
	switch(*cursor){
		case 61: goto State47;	//'='
		default: goto final;
	};

State18:
	cursor++;
	if(limit == cursor) fill();
	accept = 20;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State23:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State40;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State41;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State32:
	cursor++;
	if(limit == cursor) fill();
	accept = 2;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State30:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State31;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State7:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State41:
	cursor++;
	if(limit == cursor) fill();
	accept = 4;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State25:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State33;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State22:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State42;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State45:
	cursor++;
	if(limit == cursor) fill();
	accept = 0;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State28:
	cursor++;
	if(limit == cursor) fill();
	accept = 19;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State0:
	cursor++;
	if(limit == cursor) fill();
START: 
	switch(*cursor){
		case 4: goto State1;
		case 9: goto State2;
		case 10: goto State3;
		case 13: goto State4;
		case 33: goto State6;	//'!'
		case 32: goto State5;	//' '
		case 41: goto State8;	//')'
		case 40: goto State7;	//'('
		case 43: goto State9;	//'+'
		case 45: goto State11;	//'-'
		case 44: goto State10;	//','
		case 46: goto State12;	//'.'
		case 49: goto State13;	//'1'
		case 48: goto State13;	//'0'
		case 51: goto State13;	//'3'
		case 50: goto State13;	//'2'
		case 53: goto State13;	//'5'
		case 52: goto State13;	//'4'
		case 55: goto State13;	//'7'
		case 54: goto State13;	//'6'
		case 57: goto State13;	//'9'
		case 56: goto State13;	//'8'
		case 59: goto State15;	//';'
		case 58: goto State14;	//':'
		case 61: goto State16;	//'='
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 91: goto State18;	//'['
		case 90: goto State17;	//'Z'
		case 93: goto State19;	//']'
		case 95: goto State20;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State21;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State22;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State24;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State25;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State26;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 123: goto State27;	//'{'
		case 122: goto State17;	//'z'
		case 125: goto State28;	//'}'
		default: goto final;
	};

State8:
	cursor++;
	if(limit == cursor) fill();
	accept = 17;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State42:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State43;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State4:
	cursor++;
	if(limit == cursor) fill();
	accept = 27;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State11:
	cursor++;
	if(limit == cursor) fill();
	accept = 13;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State31:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State32;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State35:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State36;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State9:
	cursor++;
	if(limit == cursor) fill();
	accept = 12;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State33:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State34;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State36:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State37;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State43:
	cursor++;
	if(limit == cursor) fill();
	accept = 3;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State13:
	cursor++;
	if(limit == cursor) fill();
	accept = 23;
	marker = cursor;
	switch(*cursor){
		case 49: goto State13;	//'1'
		case 48: goto State13;	//'0'
		case 51: goto State13;	//'3'
		case 50: goto State13;	//'2'
		case 53: goto State13;	//'5'
		case 52: goto State13;	//'4'
		case 55: goto State13;	//'7'
		case 54: goto State13;	//'6'
		case 57: goto State13;	//'9'
		case 56: goto State13;	//'8'
		default: goto final;
	};

State24:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State38;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State12:
	cursor++;
	if(limit == cursor) fill();
	accept = 11;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State14:
	cursor++;
	if(limit == cursor) fill();
	accept = 15;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State16:
	cursor++;
	if(limit == cursor) fill();
	accept = 7;
	marker = cursor;
	switch(*cursor){
		case 61: goto State46;	//'='
		default: goto final;
	};

State37:
	cursor++;
	if(limit == cursor) fill();
	accept = 6;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State46:
	cursor++;
	if(limit == cursor) fill();
	accept = 8;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State27:
	cursor++;
	if(limit == cursor) fill();
	accept = 18;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State15:
	cursor++;
	if(limit == cursor) fill();
	accept = 14;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State17:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		case 49: goto State17;	//'1'
		case 48: goto State17;	//'0'
		case 51: goto State17;	//'3'
		case 50: goto State17;	//'2'
		case 53: goto State17;	//'5'
		case 52: goto State17;	//'4'
		case 55: goto State17;	//'7'
		case 54: goto State17;	//'6'
		case 57: goto State17;	//'9'
		case 56: goto State17;	//'8'
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State17;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

State20:
	cursor++;
	if(limit == cursor) fill();
	switch(*cursor){
		case 65: goto State17;	//'A'
		case 67: goto State17;	//'C'
		case 66: goto State17;	//'B'
		case 69: goto State17;	//'E'
		case 68: goto State17;	//'D'
		case 71: goto State17;	//'G'
		case 70: goto State17;	//'F'
		case 73: goto State17;	//'I'
		case 72: goto State17;	//'H'
		case 75: goto State17;	//'K'
		case 74: goto State17;	//'J'
		case 77: goto State17;	//'M'
		case 76: goto State17;	//'L'
		case 79: goto State17;	//'O'
		case 78: goto State17;	//'N'
		case 81: goto State17;	//'Q'
		case 80: goto State17;	//'P'
		case 83: goto State17;	//'S'
		case 82: goto State17;	//'R'
		case 85: goto State17;	//'U'
		case 84: goto State17;	//'T'
		case 87: goto State17;	//'W'
		case 86: goto State17;	//'V'
		case 89: goto State17;	//'Y'
		case 88: goto State17;	//'X'
		case 90: goto State17;	//'Z'
		case 95: goto State20;	//'_'
		case 97: goto State17;	//'a'
		case 99: goto State17;	//'c'
		case 98: goto State17;	//'b'
		case 101: goto State17;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State17;	//'g'
		case 102: goto State17;	//'f'
		case 105: goto State17;	//'i'
		case 104: goto State17;	//'h'
		case 107: goto State17;	//'k'
		case 106: goto State17;	//'j'
		case 109: goto State17;	//'m'
		case 108: goto State17;	//'l'
		case 111: goto State17;	//'o'
		case 110: goto State17;	//'n'
		case 113: goto State17;	//'q'
		case 112: goto State17;	//'p'
		case 115: goto State17;	//'s'
		case 114: goto State17;	//'r'
		case 117: goto State17;	//'u'
		case 116: goto State17;	//'t'
		case 119: goto State17;	//'w'
		case 118: goto State17;	//'v'
		case 121: goto State17;	//'y'
		case 120: goto State17;	//'x'
		case 122: goto State17;	//'z'
		default: goto final;
	};

	}

}

