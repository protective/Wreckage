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
	uint32_t move = input->gcount();
	limit += move;

	//Handle EOF and possible errors
	if(input->eof()){
		//*limit = 0x4; //eof
		uint8_t* tmp = (uint8_t*)limit;
		*tmp = 0x4;
		//limit++;
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
		cerr<<"terminal in"<<endl; return new Terminal(TOKEN_in, pos);
		}
		break;
	case 4:
		{
		cerr<<"terminal out"<<endl; return new Terminal(TOKEN_out, pos);
		}
		break;
	case 5:
		{
		cerr<<"terminal return"<<endl; return new Terminal(TOKEN_return, pos);
		}
		break;
	case 6:
		{
		cerr<<"terminal assignment"<<endl; return new Terminal(TOKEN_assignment, pos);
		}
		break;
	case 7:
		{
		cerr<<"terminal comma"<<endl;return new Terminal(TOKEN_comma, pos);
		}
		break;
	case 8:
		{
		cerr<<"terminal dot"<<endl;return new Terminal(TOKEN_dot, pos);
		}
		break;
	case 9:
		{
		cerr<<"terminal plus"<<endl;return new Terminal(TOKEN_plus, pos);
		}
		break;
	case 10:
		{
		cerr<<"terminal minus"<<endl;return new Terminal(TOKEN_minus, pos);
		}
		break;
	case 11:
		{
		cerr<<"terminal semicolon"<<endl;return new Terminal(TOKEN_semicolon, pos);
		}
		break;
	case 12:
		{
		cerr<<"terminal leftp"<<endl;return new Terminal(TOKEN_left_p, pos);
		}
		break;
	case 13:
		{
		cerr<<"terminal rightp"<<endl;return new Terminal(TOKEN_right_p, pos);
		}
		break;
	case 14:
		{
		cerr<<"terminal leftcur"<<endl;return new Terminal(TOKEN_left_c, pos);
		}
		break;
	case 15:
		{
		cerr<<"terminal rightcur"<<endl;return new Terminal(TOKEN_right_c, pos);
		}
		break;
	case 16:
		{
		cerr<<"terminal id"<<endl;return new Identifier(token, toklen, pos);
		}
		break;
	case 17:
		{
		cerr<<"terminal int"<<endl;return IntegerFromDecimalString(token, toklen, pos);
		}
		break;
	case 18:
		{
		cerr<<"terminal eof"<<endl;return new Terminal(TOKEN_EOF, pos);
		}
		break;
	case 19:
		{
		cerr<<"space"<<endl;goto BEGIN;
		}
		break;
	case 20:
		{
		cerr<<"tab"<<endl;goto BEGIN;
		}
		break;
	case 21:
		{
		cerr<<"newline lf"<<endl;goto BEGIN;
		}
		break;
	case 22:
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
	accept = 18;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State4:
	cursor++;
	if(limit == cursor) fill();
	accept = 21;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State17:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State37;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State37:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State38;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State7:
	cursor++;
	if(limit == cursor) fill();
	accept = 13;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State38:
	cursor++;
	if(limit == cursor) fill();
	accept = 0;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State12:
	cursor++;
	if(limit == cursor) fill();
	accept = 17;
	marker = cursor;
	switch(*cursor){
		case 49: goto State12;	//'1'
		case 48: goto State12;	//'0'
		case 51: goto State12;	//'3'
		case 50: goto State12;	//'2'
		case 53: goto State12;	//'5'
		case 52: goto State12;	//'4'
		case 55: goto State12;	//'7'
		case 54: goto State12;	//'6'
		case 57: goto State12;	//'9'
		case 56: goto State12;	//'8'
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

State21:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State24;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
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
		case 32: goto State5;	//' '
		case 41: goto State7;	//')'
		case 40: goto State6;	//'('
		case 43: goto State8;	//'+'
		case 45: goto State10;	//'-'
		case 44: goto State9;	//','
		case 46: goto State11;	//'.'
		case 49: goto State12;	//'1'
		case 48: goto State12;	//'0'
		case 51: goto State12;	//'3'
		case 50: goto State12;	//'2'
		case 53: goto State12;	//'5'
		case 52: goto State12;	//'4'
		case 55: goto State12;	//'7'
		case 54: goto State12;	//'6'
		case 57: goto State12;	//'9'
		case 56: goto State12;	//'8'
		case 59: goto State13;	//';'
		case 61: goto State14;	//'='
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State16;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State17;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State18;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State19;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State20;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State21;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 123: goto State22;	//'{'
		case 122: goto State15;	//'z'
		case 125: goto State23;	//'}'
		default: goto final;
	};

State29:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State30;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State24:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State25;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State23:
	cursor++;
	if(limit == cursor) fill();
	accept = 15;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State14:
	cursor++;
	if(limit == cursor) fill();
	accept = 6;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State30:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State31;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State5:
	cursor++;
	if(limit == cursor) fill();
	accept = 19;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State18:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State35;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State36;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State19:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State33;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State27:
	cursor++;
	if(limit == cursor) fill();
	accept = 2;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State33:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State34;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State25:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State26;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State34:
	cursor++;
	if(limit == cursor) fill();
	accept = 4;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State31:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State32;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State36:
	cursor++;
	if(limit == cursor) fill();
	accept = 3;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State35:
	cursor++;
	if(limit == cursor) fill();
	accept = 1;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State6:
	cursor++;
	if(limit == cursor) fill();
	accept = 12;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State26:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State27;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State13:
	cursor++;
	if(limit == cursor) fill();
	accept = 11;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State32:
	cursor++;
	if(limit == cursor) fill();
	accept = 5;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State11:
	cursor++;
	if(limit == cursor) fill();
	accept = 8;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State28:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State29;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State2:
	cursor++;
	if(limit == cursor) fill();
	accept = 20;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State8:
	cursor++;
	if(limit == cursor) fill();
	accept = 9;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State20:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State28;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State9:
	cursor++;
	if(limit == cursor) fill();
	accept = 7;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State22:
	cursor++;
	if(limit == cursor) fill();
	accept = 14;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State3:
	cursor++;
	if(limit == cursor) fill();
	accept = 22;
	marker = cursor;
	switch(*cursor){
		default: goto final;
	};

State15:
	cursor++;
	if(limit == cursor) fill();
	accept = 16;
	marker = cursor;
	switch(*cursor){
		case 49: goto State15;	//'1'
		case 48: goto State15;	//'0'
		case 51: goto State15;	//'3'
		case 50: goto State15;	//'2'
		case 53: goto State15;	//'5'
		case 52: goto State15;	//'4'
		case 55: goto State15;	//'7'
		case 54: goto State15;	//'6'
		case 57: goto State15;	//'9'
		case 56: goto State15;	//'8'
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State15;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

State16:
	cursor++;
	if(limit == cursor) fill();
	switch(*cursor){
		case 65: goto State15;	//'A'
		case 67: goto State15;	//'C'
		case 66: goto State15;	//'B'
		case 69: goto State15;	//'E'
		case 68: goto State15;	//'D'
		case 71: goto State15;	//'G'
		case 70: goto State15;	//'F'
		case 73: goto State15;	//'I'
		case 72: goto State15;	//'H'
		case 75: goto State15;	//'K'
		case 74: goto State15;	//'J'
		case 77: goto State15;	//'M'
		case 76: goto State15;	//'L'
		case 79: goto State15;	//'O'
		case 78: goto State15;	//'N'
		case 81: goto State15;	//'Q'
		case 80: goto State15;	//'P'
		case 83: goto State15;	//'S'
		case 82: goto State15;	//'R'
		case 85: goto State15;	//'U'
		case 84: goto State15;	//'T'
		case 87: goto State15;	//'W'
		case 86: goto State15;	//'V'
		case 89: goto State15;	//'Y'
		case 88: goto State15;	//'X'
		case 90: goto State15;	//'Z'
		case 95: goto State16;	//'_'
		case 97: goto State15;	//'a'
		case 99: goto State15;	//'c'
		case 98: goto State15;	//'b'
		case 101: goto State15;	//'e'
		case 100: goto State15;	//'d'
		case 103: goto State15;	//'g'
		case 102: goto State15;	//'f'
		case 105: goto State15;	//'i'
		case 104: goto State15;	//'h'
		case 107: goto State15;	//'k'
		case 106: goto State15;	//'j'
		case 109: goto State15;	//'m'
		case 108: goto State15;	//'l'
		case 111: goto State15;	//'o'
		case 110: goto State15;	//'n'
		case 113: goto State15;	//'q'
		case 112: goto State15;	//'p'
		case 115: goto State15;	//'s'
		case 114: goto State15;	//'r'
		case 117: goto State15;	//'u'
		case 116: goto State15;	//'t'
		case 119: goto State15;	//'w'
		case 118: goto State15;	//'v'
		case 121: goto State15;	//'y'
		case 120: goto State15;	//'x'
		case 122: goto State15;	//'z'
		default: goto final;
	};

	}

}

