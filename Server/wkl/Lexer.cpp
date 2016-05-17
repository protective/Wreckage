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
		cerr<<"terminal plus_assignment"<<endl; return new Terminal(TOKEN_plus_assignment, pos);
		}
		break;
	case 9:
		{
		cerr<<"terminal minus_assignment"<<endl; return new Terminal(TOKEN_minus_assignment, pos);
		}
		break;
	case 10:
		{
		cerr<<"terminal multiply_assignment"<<endl; return new Terminal(TOKEN_multiply_assignment, pos);
		}
		break;
	case 11:
		{
		cerr<<"terminal division_assignment"<<endl; return new Terminal(TOKEN_division_assignment, pos);
		}
		break;
	case 12:
		{
		cerr<<"terminal bitand_assignment"<<endl; return new Terminal(TOKEN_bitand_assignment, pos);
		}
		break;
	case 13:
		{
		cerr<<"terminal bitor_assignment"<<endl; return new Terminal(TOKEN_bitor_assignment, pos);
		}
		break;
	case 14:
		{
		cerr<<"terminal eq"<<endl; return new Terminal(TOKEN_eq, pos);
		}
		break;
	case 15:
		{
		cerr<<"terminal neq"<<endl; return new Terminal(TOKEN_not, pos);
		}
		break;
	case 16:
		{
		cerr<<"terminal neq"<<endl; return new Terminal(TOKEN_neq, pos);
		}
		break;
	case 17:
		{
		cerr<<"terminal eq"<<endl; return new Terminal(TOKEN_gteq, pos);
		}
		break;
	case 18:
		{
		cerr<<"terminal neq"<<endl; return new Terminal(TOKEN_leeq, pos);
		}
		break;
	case 19:
		{
		cerr<<"terminal eq"<<endl; return new Terminal(TOKEN_gt, pos);
		}
		break;
	case 20:
		{
		cerr<<"terminal neq"<<endl; return new Terminal(TOKEN_le, pos);
		}
		break;
	case 21:
		{
		cerr<<"terminal neq"<<endl; return new Terminal(TOKEN_modulo, pos);
		}
		break;
	case 22:
		{
		cerr<<"terminal comma"<<endl;return new Terminal(TOKEN_comma, pos);
		}
		break;
	case 23:
		{
		cerr<<"terminal dot"<<endl;return new Terminal(TOKEN_dot, pos);
		}
		break;
	case 24:
		{
		cerr<<"terminal plus"<<endl;return new Terminal(TOKEN_plus, pos);
		}
		break;
	case 25:
		{
		cerr<<"terminal minus"<<endl;return new Terminal(TOKEN_minus, pos);
		}
		break;
	case 26:
		{
		cerr<<"terminal multiply"<<endl;return new Terminal(TOKEN_multiply, pos);
		}
		break;
	case 27:
		{
		cerr<<"terminal division"<<endl;return new Terminal(TOKEN_division, pos);
		}
		break;
	case 28:
		{
		cerr<<"terminal and"<<endl;return new Terminal(TOKEN_and, pos);
		}
		break;
	case 29:
		{
		cerr<<"terminal or"<<endl;return new Terminal(TOKEN_or, pos);
		}
		break;
	case 30:
		{
		cerr<<"terminal bitand"<<endl;return new Terminal(TOKEN_bitand, pos);
		}
		break;
	case 31:
		{
		cerr<<"terminal bitor"<<endl;return new Terminal(TOKEN_bitor, pos);
		}
		break;
	case 32:
		{
		cerr<<"terminal semicolon"<<endl;return new Terminal(TOKEN_semicolon, pos);
		}
		break;
	case 33:
		{
		cerr<<"terminal colon"<<endl;return new Terminal(TOKEN_colon, pos);
		}
		break;
	case 34:
		{
		cerr<<"terminal leftp"<<endl;return new Terminal(TOKEN_left_p, pos);
		}
		break;
	case 35:
		{
		cerr<<"terminal rightp"<<endl;return new Terminal(TOKEN_right_p, pos);
		}
		break;
	case 36:
		{
		cerr<<"terminal leftcur"<<endl;return new Terminal(TOKEN_left_c, pos);
		}
		break;
	case 37:
		{
		cerr<<"terminal rightcur"<<endl;return new Terminal(TOKEN_right_c, pos);
		}
		break;
	case 38:
		{
		cerr<<"terminal leftcur"<<endl;return new Terminal(TOKEN_left_b, pos);
		}
		break;
	case 39:
		{
		cerr<<"terminal rightcur"<<endl;return new Terminal(TOKEN_right_b, pos);
		}
		break;
	case 40:
		{
		cerr<<"terminal id"<<endl;return new Identifier(token, toklen, pos);
		}
		break;
	case 41:
		{
		cerr<<"terminal int"<<endl;return IntegerFromDecimalString(token, toklen, pos);
		}
		break;
	case 42:
		{
		cerr<<"terminal eof"<<endl;return new Terminal(TOKEN_EOF, pos);
		}
		break;
	case 43:
		{
		cerr<<"space"<<endl;goto BEGIN;
		}
		break;
	case 44:
		{
		cerr<<"tab"<<endl;goto BEGIN;
		}
		break;
	case 45:
		{
		cerr<<"newline lf"<<endl;goto BEGIN;
		}
		break;
	case 46:
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
State1:
	cursor++;
	if(limit == cursor) fill();
	accept = 42;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State2:
	cursor++;
	if(limit == cursor) fill();
	accept = 44;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State27:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State53;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State22:
	cursor++;
	if(limit == cursor) fill();
	accept = 19;
	marker = cursor;
	switch(*cursor){
		case 61: goto State55;	//'='
		default: goto final;
	};

State9:
	cursor++;
	if(limit == cursor) fill();
	accept = 34;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State57:
	cursor++;
	if(limit == cursor) fill();
	accept = 18;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State49:
	cursor++;
	if(limit == cursor) fill();
	accept = 1;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State43:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State44;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State62:
	cursor++;
	if(limit == cursor) fill();
	accept = 28;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State10:
	cursor++;
	if(limit == cursor) fill();
	accept = 35;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State13:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State20:
	cursor++;
	if(limit == cursor) fill();
	accept = 20;
	marker = cursor;
	switch(*cursor){
		case 61: goto State57;	//'='
		default: goto final;
	};

State47:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State48;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State46:
	cursor++;
	if(limit == cursor) fill();
	accept = 6;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State59:
	cursor++;
	if(limit == cursor) fill();
	accept = 9;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State34:
	cursor++;
	if(limit == cursor) fill();
	accept = 31;
	marker = cursor;
	switch(*cursor){
		case 61: goto State36;	//'='
		case 124: goto State37;	//'|'
		default: goto final;
	};

State38:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State39;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State35:
	cursor++;
	if(limit == cursor) fill();
	accept = 37;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State53:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State54;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State5:
	cursor++;
	if(limit == cursor) fill();
	accept = 43;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State37:
	cursor++;
	if(limit == cursor) fill();
	accept = 29;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State16:
	cursor++;
	if(limit == cursor) fill();
	accept = 27;
	marker = cursor;
	switch(*cursor){
		case 61: goto State58;	//'='
		default: goto final;
	};

State29:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State49;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State50;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State12:
	cursor++;
	if(limit == cursor) fill();
	accept = 24;
	marker = cursor;
	switch(*cursor){
		case 61: goto State60;	//'='
		default: goto final;
	};

State15:
	cursor++;
	if(limit == cursor) fill();
	accept = 23;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State50:
	cursor++;
	if(limit == cursor) fill();
	accept = 4;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State31:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State42;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State14:
	cursor++;
	if(limit == cursor) fill();
	accept = 25;
	marker = cursor;
	switch(*cursor){
		case 61: goto State59;	//'='
		default: goto final;
	};

State41:
	cursor++;
	if(limit == cursor) fill();
	accept = 2;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State54:
	cursor++;
	if(limit == cursor) fill();
	accept = 0;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State55:
	cursor++;
	if(limit == cursor) fill();
	accept = 17;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State61:
	cursor++;
	if(limit == cursor) fill();
	accept = 10;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State17:
	cursor++;
	if(limit == cursor) fill();
	accept = 41;
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
		default: goto final;
	};

State8:
	cursor++;
	if(limit == cursor) fill();
	accept = 30;
	marker = cursor;
	switch(*cursor){
		case 61: goto State63;	//'='
		case 38: goto State62;	//'&'
		default: goto final;
	};

State33:
	cursor++;
	if(limit == cursor) fill();
	accept = 36;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State51:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State52;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State7:
	cursor++;
	if(limit == cursor) fill();
	accept = 21;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State39:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State40;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State18:
	cursor++;
	if(limit == cursor) fill();
	accept = 33;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State40:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State41;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State32:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State38;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State44:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State45;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State6:
	cursor++;
	if(limit == cursor) fill();
	accept = 15;
	marker = cursor;
	switch(*cursor){
		case 61: goto State64;	//'='
		default: goto final;
	};

State42:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State43;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State21:
	cursor++;
	if(limit == cursor) fill();
	accept = 7;
	marker = cursor;
	switch(*cursor){
		case 61: goto State56;	//'='
		default: goto final;
	};

State45:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State46;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State52:
	cursor++;
	if(limit == cursor) fill();
	accept = 3;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State3:
	cursor++;
	if(limit == cursor) fill();
	accept = 46;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State30:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State47;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State24:
	cursor++;
	if(limit == cursor) fill();
	accept = 38;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State36:
	cursor++;
	if(limit == cursor) fill();
	accept = 13;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State11:
	cursor++;
	if(limit == cursor) fill();
	accept = 26;
	marker = cursor;
	switch(*cursor){
		case 61: goto State61;	//'='
		default: goto final;
	};

State19:
	cursor++;
	if(limit == cursor) fill();
	accept = 32;
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
		case 32: goto State5;	//' '
		case 40: goto State9;	//'('
		case 44: goto State13;	//','
		case 48: goto State17;	//'0'
		case 52: goto State17;	//'4'
		case 56: goto State17;	//'8'
		case 60: goto State20;	//'<'
		case 68: goto State23;	//'D'
		case 72: goto State23;	//'H'
		case 76: goto State23;	//'L'
		case 80: goto State23;	//'P'
		case 84: goto State23;	//'T'
		case 88: goto State23;	//'X'
		case 100: goto State27;	//'d'
		case 104: goto State23;	//'h'
		case 108: goto State23;	//'l'
		case 112: goto State23;	//'p'
		case 116: goto State23;	//'t'
		case 120: goto State23;	//'x'
		case 124: goto State34;	//'|'
		case 43: goto State12;	//'+'
		case 47: goto State16;	//'/'
		case 51: goto State17;	//'3'
		case 55: goto State17;	//'7'
		case 59: goto State19;	//';'
		case 67: goto State23;	//'C'
		case 71: goto State23;	//'G'
		case 75: goto State23;	//'K'
		case 79: goto State23;	//'O'
		case 83: goto State23;	//'S'
		case 87: goto State23;	//'W'
		case 91: goto State24;	//'['
		case 95: goto State26;	//'_'
		case 99: goto State23;	//'c'
		case 103: goto State23;	//'g'
		case 107: goto State23;	//'k'
		case 111: goto State30;	//'o'
		case 115: goto State23;	//'s'
		case 119: goto State32;	//'w'
		case 123: goto State33;	//'{'
		case 10: goto State3;
		case 38: goto State8;	//'&'
		case 42: goto State11;	//'*'
		case 46: goto State15;	//'.'
		case 50: goto State17;	//'2'
		case 54: goto State17;	//'6'
		case 58: goto State18;	//':'
		case 62: goto State22;	//'>'
		case 66: goto State23;	//'B'
		case 70: goto State23;	//'F'
		case 74: goto State23;	//'J'
		case 78: goto State23;	//'N'
		case 82: goto State23;	//'R'
		case 86: goto State23;	//'V'
		case 90: goto State23;	//'Z'
		case 98: goto State23;	//'b'
		case 102: goto State28;	//'f'
		case 106: goto State23;	//'j'
		case 110: goto State23;	//'n'
		case 114: goto State31;	//'r'
		case 118: goto State23;	//'v'
		case 122: goto State23;	//'z'
		case 9: goto State2;
		case 13: goto State4;
		case 33: goto State6;	//'!'
		case 37: goto State7;	//'%'
		case 41: goto State10;	//')'
		case 45: goto State14;	//'-'
		case 49: goto State17;	//'1'
		case 53: goto State17;	//'5'
		case 57: goto State17;	//'9'
		case 61: goto State21;	//'='
		case 65: goto State23;	//'A'
		case 69: goto State23;	//'E'
		case 73: goto State23;	//'I'
		case 77: goto State23;	//'M'
		case 81: goto State23;	//'Q'
		case 85: goto State23;	//'U'
		case 89: goto State23;	//'Y'
		case 93: goto State25;	//']'
		case 97: goto State23;	//'a'
		case 101: goto State23;	//'e'
		case 105: goto State29;	//'i'
		case 109: goto State23;	//'m'
		case 113: goto State23;	//'q'
		case 117: goto State23;	//'u'
		case 121: goto State23;	//'y'
		case 125: goto State35;	//'}'
		default: goto final;
	};

State58:
	cursor++;
	if(limit == cursor) fill();
	accept = 11;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State63:
	cursor++;
	if(limit == cursor) fill();
	accept = 12;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State25:
	cursor++;
	if(limit == cursor) fill();
	accept = 39;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State48:
	cursor++;
	if(limit == cursor) fill();
	accept = 5;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State56:
	cursor++;
	if(limit == cursor) fill();
	accept = 14;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State28:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State51;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State60:
	cursor++;
	if(limit == cursor) fill();
	accept = 8;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State4:
	cursor++;
	if(limit == cursor) fill();
	accept = 45;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State64:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State23:
	cursor++;
	if(limit == cursor) fill();
	accept = 40;
	marker = cursor;
	switch(*cursor){
		case 49: goto State23;	//'1'
		case 48: goto State23;	//'0'
		case 51: goto State23;	//'3'
		case 50: goto State23;	//'2'
		case 53: goto State23;	//'5'
		case 52: goto State23;	//'4'
		case 55: goto State23;	//'7'
		case 54: goto State23;	//'6'
		case 57: goto State23;	//'9'
		case 56: goto State23;	//'8'
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State23;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

State26:
	cursor++;
	if(limit == cursor) fill();
	switch(*cursor){
		case 65: goto State23;	//'A'
		case 67: goto State23;	//'C'
		case 66: goto State23;	//'B'
		case 69: goto State23;	//'E'
		case 68: goto State23;	//'D'
		case 71: goto State23;	//'G'
		case 70: goto State23;	//'F'
		case 73: goto State23;	//'I'
		case 72: goto State23;	//'H'
		case 75: goto State23;	//'K'
		case 74: goto State23;	//'J'
		case 77: goto State23;	//'M'
		case 76: goto State23;	//'L'
		case 79: goto State23;	//'O'
		case 78: goto State23;	//'N'
		case 81: goto State23;	//'Q'
		case 80: goto State23;	//'P'
		case 83: goto State23;	//'S'
		case 82: goto State23;	//'R'
		case 85: goto State23;	//'U'
		case 84: goto State23;	//'T'
		case 87: goto State23;	//'W'
		case 86: goto State23;	//'V'
		case 89: goto State23;	//'Y'
		case 88: goto State23;	//'X'
		case 90: goto State23;	//'Z'
		case 95: goto State26;	//'_'
		case 97: goto State23;	//'a'
		case 99: goto State23;	//'c'
		case 98: goto State23;	//'b'
		case 101: goto State23;	//'e'
		case 100: goto State23;	//'d'
		case 103: goto State23;	//'g'
		case 102: goto State23;	//'f'
		case 105: goto State23;	//'i'
		case 104: goto State23;	//'h'
		case 107: goto State23;	//'k'
		case 106: goto State23;	//'j'
		case 109: goto State23;	//'m'
		case 108: goto State23;	//'l'
		case 111: goto State23;	//'o'
		case 110: goto State23;	//'n'
		case 113: goto State23;	//'q'
		case 112: goto State23;	//'p'
		case 115: goto State23;	//'s'
		case 114: goto State23;	//'r'
		case 117: goto State23;	//'u'
		case 116: goto State23;	//'t'
		case 119: goto State23;	//'w'
		case 118: goto State23;	//'v'
		case 121: goto State23;	//'y'
		case 120: goto State23;	//'x'
		case 122: goto State23;	//'z'
		default: goto final;
	};

	}

}

