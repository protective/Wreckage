#include <stdio.h>
#include "Lexer.h"

#include "Nodes/Nodes.h"
#include "Terminals/Terminals.h"
using namespace wkl;
#define BinOp(a,b,c)		new BinaryOperatorExpr((NodeExpr*)a, (Terminal*)b, (NodeExpr*)c)

//Generated code:
#include <stack>
#include "Parser.h"
using namespace std;

/* Enumeration for all non-terminals */
enum Symbol{
	SYMBOL_error,
	SYMBOL_root,
	SYMBOL_program,
	SYMBOL_top_defs,
	SYMBOL_top_def,
	SYMBOL_method,
	SYMBOL_paramsblock,
	SYMBOL_block,
	SYMBOL_stmts,
	SYMBOL_stmt,
	SYMBOL_closedStmt,
	SYMBOL_outDecl,
	SYMBOL_inDecl,
	SYMBOL_returnStmt,
	SYMBOL_varAssign,
	SYMBOL_tuprefblock,
	SYMBOL_expr,
	SYMBOL_params,
	SYMBOL_param,
	SYMBOL_varexpr,
	SYMBOL_type,
	SYMBOL_argblock,
	SYMBOL_args,
	SYMBOL_arg,
	SYMBOL_tupblock,
	SYMBOL_tups,
	SYMBOL_tup,
	SYMBOL_tuprefs,
	SYMBOL_dictblock,
	SYMBOL_pairs,
	SYMBOL_pair
};


/* The following auto generated code expects the function lexer->nextToken() to return a Terminal
 * object pointer (e.g. Terminal*). The terminal object is assumed to have a token() method
 * returning a Token (the enum defined in the header file). The Terminal class must also
 * derivate from a class called Node, which must also be defined.
 * 
 * At last but not least a subclass of Terminal called ErrorTerminal must exist. This class
 * must have a constructor that takes a Terminal pointer as single argument. It must also
 * have a method called discard(Terminal* terminal), which will be called whenever a terminal
 * following an error is discarded.
 */

/** Function for parsing input read from lexer->nextToken() */
Node* parse(Lexer* lexer){
	stack<Node*> symbols = stack<Node*>();
	stack<void*> states = stack<void*>();
	Symbol top_non_terminal;
	Terminal* current_terminal = lexer->nextToken();
	Node* result, *arg0, *arg1, *arg2, *arg3, *arg4;
	goto START;
	/*** States ****/
Shift0:
/*
{root -> ~ program, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
START:
State0:
	states.push(&&Goto0);
	switch(current_terminal->token()){
		case TOKEN_newline: goto Shift136;
		case TOKEN_error: goto Shift134;
		case TOKEN_def: goto Shift1;
		default: goto ERROR;
	}

Goto0:
	switch(top_non_terminal){
		case SYMBOL_program: goto State138;
		case SYMBOL_top_defs: goto State135;
		case SYMBOL_top_def: goto State132;
		case SYMBOL_method: goto State131;
		case SYMBOL_error:
			goto Shift134;
		default: goto FATAL_ERROR;
	}

Shift1:
/*
{method -> [def] ~ [id] paramsblock block, [def]}
{method -> [def] ~ [id] paramsblock block, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State1:
	states.push(&&Goto1);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift2;
		default: goto ERROR;
	}

Goto1:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift2:
/*
{method -> [def] [id] ~ paramsblock block, [def]}
{method -> [def] [id] ~ paramsblock block, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State2:
	states.push(&&Goto2);
	switch(current_terminal->token()){
		case TOKEN_left_p: goto Shift3;
		default: goto ERROR;
	}

Goto2:
	switch(top_non_terminal){
		case SYMBOL_paramsblock: goto State11;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift3:
/*
{paramsblock -> [left_p] ~ params [right_p], [left_c]}
{paramsblock -> [left_p] ~ [right_p], [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State3:
	states.push(&&Goto3);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift7;
		case TOKEN_id: goto Shift10;
		default: goto ERROR;
	}

Goto3:
	switch(top_non_terminal){
		case SYMBOL_params: goto State8;
		case SYMBOL_param: goto State4;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift4:
/*
{params -> param ~ [comma] params, [right_p]}
{params -> param ~, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State4:
	states.push(&&Goto4);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Shift5;
		case TOKEN_right_p: goto Reduce21;
		default: goto ERROR;
	}

Goto4:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift5:
/*
{params -> param [comma] ~ params, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State5:
	states.push(&&Goto5);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift10;
		default: goto ERROR;
	}

Goto5:
	switch(top_non_terminal){
		case SYMBOL_params: goto State6;
		case SYMBOL_param: goto State4;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift6:
/*
{params -> param [comma] params ~, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State6:
	states.push(&&Goto6);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce20;
		default: goto ERROR;
	}

Goto6:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift7:
/*
{paramsblock -> [left_p] [right_p] ~, [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State7:
	states.push(&&Goto7);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Reduce19;
		default: goto ERROR;
	}

Goto7:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift8:
/*
{paramsblock -> [left_p] params ~ [right_p], [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State8:
	states.push(&&Goto8);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift9;
		default: goto ERROR;
	}

Goto8:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift9:
/*
{paramsblock -> [left_p] params [right_p] ~, [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State9:
	states.push(&&Goto9);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Reduce18;
		default: goto ERROR;
	}

Goto9:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift10:
/*
{param -> [id] ~, [right_p]}
{param -> [id] ~, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State10:
	states.push(&&Goto10);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce22;
		case TOKEN_comma: goto Reduce22;
		default: goto ERROR;
	}

Goto10:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift11:
/*
{method -> [def] [id] paramsblock ~ block, [def]}
{method -> [def] [id] paramsblock ~ block, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State11:
	states.push(&&Goto11);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto11:
	switch(top_non_terminal){
		case SYMBOL_block: goto State130;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift12:
/*
{block -> [left_c] ~ stmts [right_c], [def]}
{block -> [left_c] ~ stmts [right_c], [EOF]}
{block -> [left_c] ~ stmts [right_c], [right_c]}
{block -> [left_c] ~ stmts [right_c], [out]}
{block -> [left_c] ~ stmts [right_c], [in]}
{block -> [left_c] ~ stmts [right_c], [return]}
{block -> [left_c] ~ stmts [right_c], [id]}
{block -> [left_c] ~ stmts [right_c], [left_p]}
{block -> [left_c] ~ stmts [right_c], [left_c]}
{block -> [left_c] ~ stmts [right_c], [not]}
{block -> [left_c] ~ stmts [right_c], [int]}
{block -> [left_c] ~ stmts [right_c], [if]}
{block -> [left_c] ~ stmts [right_c], [while]}
{block -> [left_c] ~ stmts [right_c], [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State12:
	states.push(&&Goto12);
	switch(current_terminal->token()){
		case TOKEN_if: goto Shift61;
		case TOKEN_while: goto Shift58;
		case TOKEN_for: goto Shift53;
		case TOKEN_out: goto Shift103;
		case TOKEN_in: goto Shift98;
		case TOKEN_return: goto Shift95;
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift115;
		case TOKEN_left_c: goto Shift64;
		case TOKEN_left_p: goto Shift84;
		default: goto ERROR;
	}

Goto12:
	switch(top_non_terminal){
		case SYMBOL_stmts: goto State113;
		case SYMBOL_stmt: goto State110;
		case SYMBOL_closedStmt: goto State108;
		case SYMBOL_varAssign: goto State94;
		case SYMBOL_tuprefblock: goto State91;
		case SYMBOL_expr: goto State90;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift13:
/*
{expr -> [int] ~, [semicolon]}
{expr -> [int] ~, [dot]}
{expr -> [int] ~, [or]}
{expr -> [int] ~, [and]}
{expr -> [int] ~, [bitor]}
{expr -> [int] ~, [bitand]}
{expr -> [int] ~, [neq]}
{expr -> [int] ~, [eq]}
{expr -> [int] ~, [gt]}
{expr -> [int] ~, [gteq]}
{expr -> [int] ~, [le]}
{expr -> [int] ~, [leeq]}
{expr -> [int] ~, [plus]}
{expr -> [int] ~, [minus]}
{expr -> [int] ~, [modulo]}
{expr -> [int] ~, [division]}
{expr -> [int] ~, [multiply]}
{expr -> [int] ~, [right_b]}
{expr -> [int] ~, [left_c]}
{expr -> [int] ~, [colon]}
{expr -> [int] ~, [right_p]}
{expr -> [int] ~, [comma]}
{expr -> [int] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State13:
	states.push(&&Goto13);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce78;
		case TOKEN_dot: goto Reduce78;
		case TOKEN_or: goto Reduce78;
		case TOKEN_and: goto Reduce78;
		case TOKEN_bitor: goto Reduce78;
		case TOKEN_bitand: goto Reduce78;
		case TOKEN_neq: goto Reduce78;
		case TOKEN_eq: goto Reduce78;
		case TOKEN_gt: goto Reduce78;
		case TOKEN_gteq: goto Reduce78;
		case TOKEN_le: goto Reduce78;
		case TOKEN_leeq: goto Reduce78;
		case TOKEN_plus: goto Reduce78;
		case TOKEN_minus: goto Reduce78;
		case TOKEN_modulo: goto Reduce78;
		case TOKEN_division: goto Reduce78;
		case TOKEN_multiply: goto Reduce78;
		case TOKEN_right_b: goto Reduce78;
		case TOKEN_left_c: goto Reduce78;
		case TOKEN_colon: goto Reduce78;
		case TOKEN_right_p: goto Reduce78;
		case TOKEN_comma: goto Reduce78;
		case TOKEN_right_c: goto Reduce78;
		default: goto ERROR;
	}

Goto13:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift14:
/*
{expr -> [not] ~ expr, [semicolon]}
{expr -> [not] ~ expr, [dot]}
{expr -> [not] ~ expr, [or]}
{expr -> [not] ~ expr, [and]}
{expr -> [not] ~ expr, [bitor]}
{expr -> [not] ~ expr, [bitand]}
{expr -> [not] ~ expr, [neq]}
{expr -> [not] ~ expr, [eq]}
{expr -> [not] ~ expr, [gt]}
{expr -> [not] ~ expr, [gteq]}
{expr -> [not] ~ expr, [le]}
{expr -> [not] ~ expr, [leeq]}
{expr -> [not] ~ expr, [plus]}
{expr -> [not] ~ expr, [minus]}
{expr -> [not] ~ expr, [modulo]}
{expr -> [not] ~ expr, [division]}
{expr -> [not] ~ expr, [multiply]}
{expr -> [not] ~ expr, [right_b]}
{expr -> [not] ~ expr, [left_c]}
{expr -> [not] ~ expr, [colon]}
{expr -> [not] ~ expr, [right_p]}
{expr -> [not] ~ expr, [comma]}
{expr -> [not] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State14:
	states.push(&&Goto14);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto14:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State15;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift15:
/*
{expr -> [not] expr ~, [semicolon]}
{expr -> [not] expr ~, [dot]}
{expr -> [not] expr ~, [or]}
{expr -> [not] expr ~, [and]}
{expr -> [not] expr ~, [bitor]}
{expr -> [not] expr ~, [bitand]}
{expr -> [not] expr ~, [neq]}
{expr -> [not] expr ~, [eq]}
{expr -> [not] expr ~, [gt]}
{expr -> [not] expr ~, [gteq]}
{expr -> [not] expr ~, [le]}
{expr -> [not] expr ~, [leeq]}
{expr -> [not] expr ~, [plus]}
{expr -> [not] expr ~, [minus]}
{expr -> [not] expr ~, [modulo]}
{expr -> [not] expr ~, [division]}
{expr -> [not] expr ~, [multiply]}
{expr -> [not] expr ~, [right_b]}
{expr -> [not] expr ~, [left_c]}
{expr -> [not] expr ~, [colon]}
{expr -> [not] expr ~, [right_p]}
{expr -> [not] expr ~, [comma]}
{expr -> [not] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State15:
	states.push(&&Goto15);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce62;
		case TOKEN_or: goto Reduce62;
		case TOKEN_and: goto Reduce62;
		case TOKEN_bitor: goto Reduce62;
		case TOKEN_bitand: goto Reduce62;
		case TOKEN_neq: goto Reduce62;
		case TOKEN_eq: goto Reduce62;
		case TOKEN_gt: goto Reduce62;
		case TOKEN_gteq: goto Reduce62;
		case TOKEN_le: goto Reduce62;
		case TOKEN_leeq: goto Reduce62;
		case TOKEN_plus: goto Reduce62;
		case TOKEN_minus: goto Reduce62;
		case TOKEN_modulo: goto Reduce62;
		case TOKEN_division: goto Reduce62;
		case TOKEN_multiply: goto Reduce62;
		case TOKEN_right_b: goto Reduce62;
		case TOKEN_left_c: goto Reduce62;
		case TOKEN_colon: goto Reduce62;
		case TOKEN_right_p: goto Reduce62;
		case TOKEN_comma: goto Reduce62;
		case TOKEN_right_c: goto Reduce62;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto15:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift16:
/*
{expr -> expr [or] ~ expr, [dot]}
{expr -> expr [or] ~ expr, [or]}
{expr -> expr [or] ~ expr, [and]}
{expr -> expr [or] ~ expr, [bitor]}
{expr -> expr [or] ~ expr, [bitand]}
{expr -> expr [or] ~ expr, [neq]}
{expr -> expr [or] ~ expr, [eq]}
{expr -> expr [or] ~ expr, [gt]}
{expr -> expr [or] ~ expr, [gteq]}
{expr -> expr [or] ~ expr, [le]}
{expr -> expr [or] ~ expr, [leeq]}
{expr -> expr [or] ~ expr, [plus]}
{expr -> expr [or] ~ expr, [minus]}
{expr -> expr [or] ~ expr, [modulo]}
{expr -> expr [or] ~ expr, [division]}
{expr -> expr [or] ~ expr, [multiply]}
{expr -> expr [or] ~ expr, [semicolon]}
{expr -> expr [or] ~ expr, [right_b]}
{expr -> expr [or] ~ expr, [left_c]}
{expr -> expr [or] ~ expr, [colon]}
{expr -> expr [or] ~ expr, [right_p]}
{expr -> expr [or] ~ expr, [comma]}
{expr -> expr [or] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State16:
	states.push(&&Goto16);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto16:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State17;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift17:
/*
{expr -> expr [or] expr ~, [dot]}
{expr -> expr [or] expr ~, [or]}
{expr -> expr [or] expr ~, [and]}
{expr -> expr [or] expr ~, [bitor]}
{expr -> expr [or] expr ~, [bitand]}
{expr -> expr [or] expr ~, [neq]}
{expr -> expr [or] expr ~, [eq]}
{expr -> expr [or] expr ~, [gt]}
{expr -> expr [or] expr ~, [gteq]}
{expr -> expr [or] expr ~, [le]}
{expr -> expr [or] expr ~, [leeq]}
{expr -> expr [or] expr ~, [plus]}
{expr -> expr [or] expr ~, [minus]}
{expr -> expr [or] expr ~, [modulo]}
{expr -> expr [or] expr ~, [division]}
{expr -> expr [or] expr ~, [multiply]}
{expr -> expr [or] expr ~, [semicolon]}
{expr -> expr [or] expr ~, [right_b]}
{expr -> expr [or] expr ~, [left_c]}
{expr -> expr [or] expr ~, [colon]}
{expr -> expr [or] expr ~, [right_p]}
{expr -> expr [or] expr ~, [comma]}
{expr -> expr [or] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State17:
	states.push(&&Goto17);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce77;
		case TOKEN_semicolon: goto Reduce77;
		case TOKEN_right_b: goto Reduce77;
		case TOKEN_left_c: goto Reduce77;
		case TOKEN_colon: goto Reduce77;
		case TOKEN_right_p: goto Reduce77;
		case TOKEN_comma: goto Reduce77;
		case TOKEN_right_c: goto Reduce77;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto17:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift18:
/*
{expr -> expr [and] ~ expr, [dot]}
{expr -> expr [and] ~ expr, [or]}
{expr -> expr [and] ~ expr, [and]}
{expr -> expr [and] ~ expr, [bitor]}
{expr -> expr [and] ~ expr, [bitand]}
{expr -> expr [and] ~ expr, [neq]}
{expr -> expr [and] ~ expr, [eq]}
{expr -> expr [and] ~ expr, [gt]}
{expr -> expr [and] ~ expr, [gteq]}
{expr -> expr [and] ~ expr, [le]}
{expr -> expr [and] ~ expr, [leeq]}
{expr -> expr [and] ~ expr, [plus]}
{expr -> expr [and] ~ expr, [minus]}
{expr -> expr [and] ~ expr, [modulo]}
{expr -> expr [and] ~ expr, [division]}
{expr -> expr [and] ~ expr, [multiply]}
{expr -> expr [and] ~ expr, [semicolon]}
{expr -> expr [and] ~ expr, [right_b]}
{expr -> expr [and] ~ expr, [left_c]}
{expr -> expr [and] ~ expr, [colon]}
{expr -> expr [and] ~ expr, [right_p]}
{expr -> expr [and] ~ expr, [comma]}
{expr -> expr [and] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State18:
	states.push(&&Goto18);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto18:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State19;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift19:
/*
{expr -> expr [and] expr ~, [dot]}
{expr -> expr [and] expr ~, [or]}
{expr -> expr [and] expr ~, [and]}
{expr -> expr [and] expr ~, [bitor]}
{expr -> expr [and] expr ~, [bitand]}
{expr -> expr [and] expr ~, [neq]}
{expr -> expr [and] expr ~, [eq]}
{expr -> expr [and] expr ~, [gt]}
{expr -> expr [and] expr ~, [gteq]}
{expr -> expr [and] expr ~, [le]}
{expr -> expr [and] expr ~, [leeq]}
{expr -> expr [and] expr ~, [plus]}
{expr -> expr [and] expr ~, [minus]}
{expr -> expr [and] expr ~, [modulo]}
{expr -> expr [and] expr ~, [division]}
{expr -> expr [and] expr ~, [multiply]}
{expr -> expr [and] expr ~, [semicolon]}
{expr -> expr [and] expr ~, [right_b]}
{expr -> expr [and] expr ~, [left_c]}
{expr -> expr [and] expr ~, [colon]}
{expr -> expr [and] expr ~, [right_p]}
{expr -> expr [and] expr ~, [comma]}
{expr -> expr [and] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State19:
	states.push(&&Goto19);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce76;
		case TOKEN_and: goto Reduce76;
		case TOKEN_semicolon: goto Reduce76;
		case TOKEN_right_b: goto Reduce76;
		case TOKEN_left_c: goto Reduce76;
		case TOKEN_colon: goto Reduce76;
		case TOKEN_right_p: goto Reduce76;
		case TOKEN_comma: goto Reduce76;
		case TOKEN_right_c: goto Reduce76;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto19:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift20:
/*
{expr -> expr [bitor] ~ expr, [dot]}
{expr -> expr [bitor] ~ expr, [or]}
{expr -> expr [bitor] ~ expr, [and]}
{expr -> expr [bitor] ~ expr, [bitor]}
{expr -> expr [bitor] ~ expr, [bitand]}
{expr -> expr [bitor] ~ expr, [neq]}
{expr -> expr [bitor] ~ expr, [eq]}
{expr -> expr [bitor] ~ expr, [gt]}
{expr -> expr [bitor] ~ expr, [gteq]}
{expr -> expr [bitor] ~ expr, [le]}
{expr -> expr [bitor] ~ expr, [leeq]}
{expr -> expr [bitor] ~ expr, [plus]}
{expr -> expr [bitor] ~ expr, [minus]}
{expr -> expr [bitor] ~ expr, [modulo]}
{expr -> expr [bitor] ~ expr, [division]}
{expr -> expr [bitor] ~ expr, [multiply]}
{expr -> expr [bitor] ~ expr, [semicolon]}
{expr -> expr [bitor] ~ expr, [right_b]}
{expr -> expr [bitor] ~ expr, [left_c]}
{expr -> expr [bitor] ~ expr, [colon]}
{expr -> expr [bitor] ~ expr, [right_p]}
{expr -> expr [bitor] ~ expr, [comma]}
{expr -> expr [bitor] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State20:
	states.push(&&Goto20);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto20:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State21;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift21:
/*
{expr -> expr [bitor] expr ~, [dot]}
{expr -> expr [bitor] expr ~, [or]}
{expr -> expr [bitor] expr ~, [and]}
{expr -> expr [bitor] expr ~, [bitor]}
{expr -> expr [bitor] expr ~, [bitand]}
{expr -> expr [bitor] expr ~, [neq]}
{expr -> expr [bitor] expr ~, [eq]}
{expr -> expr [bitor] expr ~, [gt]}
{expr -> expr [bitor] expr ~, [gteq]}
{expr -> expr [bitor] expr ~, [le]}
{expr -> expr [bitor] expr ~, [leeq]}
{expr -> expr [bitor] expr ~, [plus]}
{expr -> expr [bitor] expr ~, [minus]}
{expr -> expr [bitor] expr ~, [modulo]}
{expr -> expr [bitor] expr ~, [division]}
{expr -> expr [bitor] expr ~, [multiply]}
{expr -> expr [bitor] expr ~, [semicolon]}
{expr -> expr [bitor] expr ~, [right_b]}
{expr -> expr [bitor] expr ~, [left_c]}
{expr -> expr [bitor] expr ~, [colon]}
{expr -> expr [bitor] expr ~, [right_p]}
{expr -> expr [bitor] expr ~, [comma]}
{expr -> expr [bitor] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State21:
	states.push(&&Goto21);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce75;
		case TOKEN_and: goto Reduce75;
		case TOKEN_bitor: goto Reduce75;
		case TOKEN_semicolon: goto Reduce75;
		case TOKEN_right_b: goto Reduce75;
		case TOKEN_left_c: goto Reduce75;
		case TOKEN_colon: goto Reduce75;
		case TOKEN_right_p: goto Reduce75;
		case TOKEN_comma: goto Reduce75;
		case TOKEN_right_c: goto Reduce75;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto21:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift22:
/*
{expr -> expr [bitand] ~ expr, [dot]}
{expr -> expr [bitand] ~ expr, [or]}
{expr -> expr [bitand] ~ expr, [and]}
{expr -> expr [bitand] ~ expr, [bitor]}
{expr -> expr [bitand] ~ expr, [bitand]}
{expr -> expr [bitand] ~ expr, [neq]}
{expr -> expr [bitand] ~ expr, [eq]}
{expr -> expr [bitand] ~ expr, [gt]}
{expr -> expr [bitand] ~ expr, [gteq]}
{expr -> expr [bitand] ~ expr, [le]}
{expr -> expr [bitand] ~ expr, [leeq]}
{expr -> expr [bitand] ~ expr, [plus]}
{expr -> expr [bitand] ~ expr, [minus]}
{expr -> expr [bitand] ~ expr, [modulo]}
{expr -> expr [bitand] ~ expr, [division]}
{expr -> expr [bitand] ~ expr, [multiply]}
{expr -> expr [bitand] ~ expr, [semicolon]}
{expr -> expr [bitand] ~ expr, [right_b]}
{expr -> expr [bitand] ~ expr, [left_c]}
{expr -> expr [bitand] ~ expr, [colon]}
{expr -> expr [bitand] ~ expr, [right_p]}
{expr -> expr [bitand] ~ expr, [comma]}
{expr -> expr [bitand] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State22:
	states.push(&&Goto22);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto22:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State23;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift23:
/*
{expr -> expr [bitand] expr ~, [dot]}
{expr -> expr [bitand] expr ~, [or]}
{expr -> expr [bitand] expr ~, [and]}
{expr -> expr [bitand] expr ~, [bitor]}
{expr -> expr [bitand] expr ~, [bitand]}
{expr -> expr [bitand] expr ~, [neq]}
{expr -> expr [bitand] expr ~, [eq]}
{expr -> expr [bitand] expr ~, [gt]}
{expr -> expr [bitand] expr ~, [gteq]}
{expr -> expr [bitand] expr ~, [le]}
{expr -> expr [bitand] expr ~, [leeq]}
{expr -> expr [bitand] expr ~, [plus]}
{expr -> expr [bitand] expr ~, [minus]}
{expr -> expr [bitand] expr ~, [modulo]}
{expr -> expr [bitand] expr ~, [division]}
{expr -> expr [bitand] expr ~, [multiply]}
{expr -> expr [bitand] expr ~, [semicolon]}
{expr -> expr [bitand] expr ~, [right_b]}
{expr -> expr [bitand] expr ~, [left_c]}
{expr -> expr [bitand] expr ~, [colon]}
{expr -> expr [bitand] expr ~, [right_p]}
{expr -> expr [bitand] expr ~, [comma]}
{expr -> expr [bitand] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State23:
	states.push(&&Goto23);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce74;
		case TOKEN_and: goto Reduce74;
		case TOKEN_bitor: goto Reduce74;
		case TOKEN_bitand: goto Reduce74;
		case TOKEN_semicolon: goto Reduce74;
		case TOKEN_right_b: goto Reduce74;
		case TOKEN_left_c: goto Reduce74;
		case TOKEN_colon: goto Reduce74;
		case TOKEN_right_p: goto Reduce74;
		case TOKEN_comma: goto Reduce74;
		case TOKEN_right_c: goto Reduce74;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto23:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift24:
/*
{expr -> expr [neq] ~ expr, [dot]}
{expr -> expr [neq] ~ expr, [or]}
{expr -> expr [neq] ~ expr, [and]}
{expr -> expr [neq] ~ expr, [bitor]}
{expr -> expr [neq] ~ expr, [bitand]}
{expr -> expr [neq] ~ expr, [neq]}
{expr -> expr [neq] ~ expr, [eq]}
{expr -> expr [neq] ~ expr, [gt]}
{expr -> expr [neq] ~ expr, [gteq]}
{expr -> expr [neq] ~ expr, [le]}
{expr -> expr [neq] ~ expr, [leeq]}
{expr -> expr [neq] ~ expr, [plus]}
{expr -> expr [neq] ~ expr, [minus]}
{expr -> expr [neq] ~ expr, [modulo]}
{expr -> expr [neq] ~ expr, [division]}
{expr -> expr [neq] ~ expr, [multiply]}
{expr -> expr [neq] ~ expr, [semicolon]}
{expr -> expr [neq] ~ expr, [right_b]}
{expr -> expr [neq] ~ expr, [left_c]}
{expr -> expr [neq] ~ expr, [colon]}
{expr -> expr [neq] ~ expr, [right_p]}
{expr -> expr [neq] ~ expr, [comma]}
{expr -> expr [neq] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State24:
	states.push(&&Goto24);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto24:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State25;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift25:
/*
{expr -> expr [neq] expr ~, [dot]}
{expr -> expr [neq] expr ~, [or]}
{expr -> expr [neq] expr ~, [and]}
{expr -> expr [neq] expr ~, [bitor]}
{expr -> expr [neq] expr ~, [bitand]}
{expr -> expr [neq] expr ~, [neq]}
{expr -> expr [neq] expr ~, [eq]}
{expr -> expr [neq] expr ~, [gt]}
{expr -> expr [neq] expr ~, [gteq]}
{expr -> expr [neq] expr ~, [le]}
{expr -> expr [neq] expr ~, [leeq]}
{expr -> expr [neq] expr ~, [plus]}
{expr -> expr [neq] expr ~, [minus]}
{expr -> expr [neq] expr ~, [modulo]}
{expr -> expr [neq] expr ~, [division]}
{expr -> expr [neq] expr ~, [multiply]}
{expr -> expr [neq] expr ~, [semicolon]}
{expr -> expr [neq] expr ~, [right_b]}
{expr -> expr [neq] expr ~, [left_c]}
{expr -> expr [neq] expr ~, [colon]}
{expr -> expr [neq] expr ~, [right_p]}
{expr -> expr [neq] expr ~, [comma]}
{expr -> expr [neq] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State25:
	states.push(&&Goto25);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce73;
		case TOKEN_and: goto Reduce73;
		case TOKEN_bitor: goto Reduce73;
		case TOKEN_bitand: goto Reduce73;
		case TOKEN_neq: goto Reduce73;
		case TOKEN_semicolon: goto Reduce73;
		case TOKEN_right_b: goto Reduce73;
		case TOKEN_left_c: goto Reduce73;
		case TOKEN_colon: goto Reduce73;
		case TOKEN_right_p: goto Reduce73;
		case TOKEN_comma: goto Reduce73;
		case TOKEN_right_c: goto Reduce73;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto25:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift26:
/*
{expr -> expr [eq] ~ expr, [dot]}
{expr -> expr [eq] ~ expr, [or]}
{expr -> expr [eq] ~ expr, [and]}
{expr -> expr [eq] ~ expr, [bitor]}
{expr -> expr [eq] ~ expr, [bitand]}
{expr -> expr [eq] ~ expr, [neq]}
{expr -> expr [eq] ~ expr, [eq]}
{expr -> expr [eq] ~ expr, [gt]}
{expr -> expr [eq] ~ expr, [gteq]}
{expr -> expr [eq] ~ expr, [le]}
{expr -> expr [eq] ~ expr, [leeq]}
{expr -> expr [eq] ~ expr, [plus]}
{expr -> expr [eq] ~ expr, [minus]}
{expr -> expr [eq] ~ expr, [modulo]}
{expr -> expr [eq] ~ expr, [division]}
{expr -> expr [eq] ~ expr, [multiply]}
{expr -> expr [eq] ~ expr, [semicolon]}
{expr -> expr [eq] ~ expr, [right_b]}
{expr -> expr [eq] ~ expr, [left_c]}
{expr -> expr [eq] ~ expr, [colon]}
{expr -> expr [eq] ~ expr, [right_p]}
{expr -> expr [eq] ~ expr, [comma]}
{expr -> expr [eq] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State26:
	states.push(&&Goto26);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto26:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State27;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift27:
/*
{expr -> expr [eq] expr ~, [dot]}
{expr -> expr [eq] expr ~, [or]}
{expr -> expr [eq] expr ~, [and]}
{expr -> expr [eq] expr ~, [bitor]}
{expr -> expr [eq] expr ~, [bitand]}
{expr -> expr [eq] expr ~, [neq]}
{expr -> expr [eq] expr ~, [eq]}
{expr -> expr [eq] expr ~, [gt]}
{expr -> expr [eq] expr ~, [gteq]}
{expr -> expr [eq] expr ~, [le]}
{expr -> expr [eq] expr ~, [leeq]}
{expr -> expr [eq] expr ~, [plus]}
{expr -> expr [eq] expr ~, [minus]}
{expr -> expr [eq] expr ~, [modulo]}
{expr -> expr [eq] expr ~, [division]}
{expr -> expr [eq] expr ~, [multiply]}
{expr -> expr [eq] expr ~, [semicolon]}
{expr -> expr [eq] expr ~, [right_b]}
{expr -> expr [eq] expr ~, [left_c]}
{expr -> expr [eq] expr ~, [colon]}
{expr -> expr [eq] expr ~, [right_p]}
{expr -> expr [eq] expr ~, [comma]}
{expr -> expr [eq] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State27:
	states.push(&&Goto27);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce72;
		case TOKEN_and: goto Reduce72;
		case TOKEN_bitor: goto Reduce72;
		case TOKEN_bitand: goto Reduce72;
		case TOKEN_neq: goto Reduce72;
		case TOKEN_eq: goto Reduce72;
		case TOKEN_semicolon: goto Reduce72;
		case TOKEN_right_b: goto Reduce72;
		case TOKEN_left_c: goto Reduce72;
		case TOKEN_colon: goto Reduce72;
		case TOKEN_right_p: goto Reduce72;
		case TOKEN_comma: goto Reduce72;
		case TOKEN_right_c: goto Reduce72;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto27:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift28:
/*
{expr -> expr [gt] ~ expr, [dot]}
{expr -> expr [gt] ~ expr, [or]}
{expr -> expr [gt] ~ expr, [and]}
{expr -> expr [gt] ~ expr, [bitor]}
{expr -> expr [gt] ~ expr, [bitand]}
{expr -> expr [gt] ~ expr, [neq]}
{expr -> expr [gt] ~ expr, [eq]}
{expr -> expr [gt] ~ expr, [gt]}
{expr -> expr [gt] ~ expr, [gteq]}
{expr -> expr [gt] ~ expr, [le]}
{expr -> expr [gt] ~ expr, [leeq]}
{expr -> expr [gt] ~ expr, [plus]}
{expr -> expr [gt] ~ expr, [minus]}
{expr -> expr [gt] ~ expr, [modulo]}
{expr -> expr [gt] ~ expr, [division]}
{expr -> expr [gt] ~ expr, [multiply]}
{expr -> expr [gt] ~ expr, [semicolon]}
{expr -> expr [gt] ~ expr, [right_b]}
{expr -> expr [gt] ~ expr, [left_c]}
{expr -> expr [gt] ~ expr, [colon]}
{expr -> expr [gt] ~ expr, [right_p]}
{expr -> expr [gt] ~ expr, [comma]}
{expr -> expr [gt] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State28:
	states.push(&&Goto28);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto28:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State29;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift29:
/*
{expr -> expr [gt] expr ~, [dot]}
{expr -> expr [gt] expr ~, [or]}
{expr -> expr [gt] expr ~, [and]}
{expr -> expr [gt] expr ~, [bitor]}
{expr -> expr [gt] expr ~, [bitand]}
{expr -> expr [gt] expr ~, [neq]}
{expr -> expr [gt] expr ~, [eq]}
{expr -> expr [gt] expr ~, [gt]}
{expr -> expr [gt] expr ~, [gteq]}
{expr -> expr [gt] expr ~, [le]}
{expr -> expr [gt] expr ~, [leeq]}
{expr -> expr [gt] expr ~, [plus]}
{expr -> expr [gt] expr ~, [minus]}
{expr -> expr [gt] expr ~, [modulo]}
{expr -> expr [gt] expr ~, [division]}
{expr -> expr [gt] expr ~, [multiply]}
{expr -> expr [gt] expr ~, [semicolon]}
{expr -> expr [gt] expr ~, [right_b]}
{expr -> expr [gt] expr ~, [left_c]}
{expr -> expr [gt] expr ~, [colon]}
{expr -> expr [gt] expr ~, [right_p]}
{expr -> expr [gt] expr ~, [comma]}
{expr -> expr [gt] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State29:
	states.push(&&Goto29);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce71;
		case TOKEN_and: goto Reduce71;
		case TOKEN_bitor: goto Reduce71;
		case TOKEN_bitand: goto Reduce71;
		case TOKEN_neq: goto Reduce71;
		case TOKEN_eq: goto Reduce71;
		case TOKEN_gt: goto Reduce71;
		case TOKEN_semicolon: goto Reduce71;
		case TOKEN_right_b: goto Reduce71;
		case TOKEN_left_c: goto Reduce71;
		case TOKEN_colon: goto Reduce71;
		case TOKEN_right_p: goto Reduce71;
		case TOKEN_comma: goto Reduce71;
		case TOKEN_right_c: goto Reduce71;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto29:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift30:
/*
{expr -> expr [gteq] ~ expr, [dot]}
{expr -> expr [gteq] ~ expr, [or]}
{expr -> expr [gteq] ~ expr, [and]}
{expr -> expr [gteq] ~ expr, [bitor]}
{expr -> expr [gteq] ~ expr, [bitand]}
{expr -> expr [gteq] ~ expr, [neq]}
{expr -> expr [gteq] ~ expr, [eq]}
{expr -> expr [gteq] ~ expr, [gt]}
{expr -> expr [gteq] ~ expr, [gteq]}
{expr -> expr [gteq] ~ expr, [le]}
{expr -> expr [gteq] ~ expr, [leeq]}
{expr -> expr [gteq] ~ expr, [plus]}
{expr -> expr [gteq] ~ expr, [minus]}
{expr -> expr [gteq] ~ expr, [modulo]}
{expr -> expr [gteq] ~ expr, [division]}
{expr -> expr [gteq] ~ expr, [multiply]}
{expr -> expr [gteq] ~ expr, [semicolon]}
{expr -> expr [gteq] ~ expr, [right_b]}
{expr -> expr [gteq] ~ expr, [left_c]}
{expr -> expr [gteq] ~ expr, [colon]}
{expr -> expr [gteq] ~ expr, [right_p]}
{expr -> expr [gteq] ~ expr, [comma]}
{expr -> expr [gteq] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State30:
	states.push(&&Goto30);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto30:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State31;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift31:
/*
{expr -> expr [gteq] expr ~, [dot]}
{expr -> expr [gteq] expr ~, [or]}
{expr -> expr [gteq] expr ~, [and]}
{expr -> expr [gteq] expr ~, [bitor]}
{expr -> expr [gteq] expr ~, [bitand]}
{expr -> expr [gteq] expr ~, [neq]}
{expr -> expr [gteq] expr ~, [eq]}
{expr -> expr [gteq] expr ~, [gt]}
{expr -> expr [gteq] expr ~, [gteq]}
{expr -> expr [gteq] expr ~, [le]}
{expr -> expr [gteq] expr ~, [leeq]}
{expr -> expr [gteq] expr ~, [plus]}
{expr -> expr [gteq] expr ~, [minus]}
{expr -> expr [gteq] expr ~, [modulo]}
{expr -> expr [gteq] expr ~, [division]}
{expr -> expr [gteq] expr ~, [multiply]}
{expr -> expr [gteq] expr ~, [semicolon]}
{expr -> expr [gteq] expr ~, [right_b]}
{expr -> expr [gteq] expr ~, [left_c]}
{expr -> expr [gteq] expr ~, [colon]}
{expr -> expr [gteq] expr ~, [right_p]}
{expr -> expr [gteq] expr ~, [comma]}
{expr -> expr [gteq] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State31:
	states.push(&&Goto31);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce70;
		case TOKEN_and: goto Reduce70;
		case TOKEN_bitor: goto Reduce70;
		case TOKEN_bitand: goto Reduce70;
		case TOKEN_neq: goto Reduce70;
		case TOKEN_eq: goto Reduce70;
		case TOKEN_gt: goto Reduce70;
		case TOKEN_gteq: goto Reduce70;
		case TOKEN_semicolon: goto Reduce70;
		case TOKEN_right_b: goto Reduce70;
		case TOKEN_left_c: goto Reduce70;
		case TOKEN_colon: goto Reduce70;
		case TOKEN_right_p: goto Reduce70;
		case TOKEN_comma: goto Reduce70;
		case TOKEN_right_c: goto Reduce70;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto31:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift32:
/*
{expr -> expr [le] ~ expr, [dot]}
{expr -> expr [le] ~ expr, [or]}
{expr -> expr [le] ~ expr, [and]}
{expr -> expr [le] ~ expr, [bitor]}
{expr -> expr [le] ~ expr, [bitand]}
{expr -> expr [le] ~ expr, [neq]}
{expr -> expr [le] ~ expr, [eq]}
{expr -> expr [le] ~ expr, [gt]}
{expr -> expr [le] ~ expr, [gteq]}
{expr -> expr [le] ~ expr, [le]}
{expr -> expr [le] ~ expr, [leeq]}
{expr -> expr [le] ~ expr, [plus]}
{expr -> expr [le] ~ expr, [minus]}
{expr -> expr [le] ~ expr, [modulo]}
{expr -> expr [le] ~ expr, [division]}
{expr -> expr [le] ~ expr, [multiply]}
{expr -> expr [le] ~ expr, [semicolon]}
{expr -> expr [le] ~ expr, [right_b]}
{expr -> expr [le] ~ expr, [left_c]}
{expr -> expr [le] ~ expr, [colon]}
{expr -> expr [le] ~ expr, [right_p]}
{expr -> expr [le] ~ expr, [comma]}
{expr -> expr [le] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State32:
	states.push(&&Goto32);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto32:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State33;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift33:
/*
{expr -> expr [le] expr ~, [dot]}
{expr -> expr [le] expr ~, [or]}
{expr -> expr [le] expr ~, [and]}
{expr -> expr [le] expr ~, [bitor]}
{expr -> expr [le] expr ~, [bitand]}
{expr -> expr [le] expr ~, [neq]}
{expr -> expr [le] expr ~, [eq]}
{expr -> expr [le] expr ~, [gt]}
{expr -> expr [le] expr ~, [gteq]}
{expr -> expr [le] expr ~, [le]}
{expr -> expr [le] expr ~, [leeq]}
{expr -> expr [le] expr ~, [plus]}
{expr -> expr [le] expr ~, [minus]}
{expr -> expr [le] expr ~, [modulo]}
{expr -> expr [le] expr ~, [division]}
{expr -> expr [le] expr ~, [multiply]}
{expr -> expr [le] expr ~, [semicolon]}
{expr -> expr [le] expr ~, [right_b]}
{expr -> expr [le] expr ~, [left_c]}
{expr -> expr [le] expr ~, [colon]}
{expr -> expr [le] expr ~, [right_p]}
{expr -> expr [le] expr ~, [comma]}
{expr -> expr [le] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State33:
	states.push(&&Goto33);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce69;
		case TOKEN_and: goto Reduce69;
		case TOKEN_bitor: goto Reduce69;
		case TOKEN_bitand: goto Reduce69;
		case TOKEN_neq: goto Reduce69;
		case TOKEN_eq: goto Reduce69;
		case TOKEN_gt: goto Reduce69;
		case TOKEN_gteq: goto Reduce69;
		case TOKEN_le: goto Reduce69;
		case TOKEN_semicolon: goto Reduce69;
		case TOKEN_right_b: goto Reduce69;
		case TOKEN_left_c: goto Reduce69;
		case TOKEN_colon: goto Reduce69;
		case TOKEN_right_p: goto Reduce69;
		case TOKEN_comma: goto Reduce69;
		case TOKEN_right_c: goto Reduce69;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto33:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift34:
/*
{expr -> expr [leeq] ~ expr, [dot]}
{expr -> expr [leeq] ~ expr, [or]}
{expr -> expr [leeq] ~ expr, [and]}
{expr -> expr [leeq] ~ expr, [bitor]}
{expr -> expr [leeq] ~ expr, [bitand]}
{expr -> expr [leeq] ~ expr, [neq]}
{expr -> expr [leeq] ~ expr, [eq]}
{expr -> expr [leeq] ~ expr, [gt]}
{expr -> expr [leeq] ~ expr, [gteq]}
{expr -> expr [leeq] ~ expr, [le]}
{expr -> expr [leeq] ~ expr, [leeq]}
{expr -> expr [leeq] ~ expr, [plus]}
{expr -> expr [leeq] ~ expr, [minus]}
{expr -> expr [leeq] ~ expr, [modulo]}
{expr -> expr [leeq] ~ expr, [division]}
{expr -> expr [leeq] ~ expr, [multiply]}
{expr -> expr [leeq] ~ expr, [semicolon]}
{expr -> expr [leeq] ~ expr, [right_b]}
{expr -> expr [leeq] ~ expr, [left_c]}
{expr -> expr [leeq] ~ expr, [colon]}
{expr -> expr [leeq] ~ expr, [right_p]}
{expr -> expr [leeq] ~ expr, [comma]}
{expr -> expr [leeq] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State34:
	states.push(&&Goto34);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto34:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State35;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift35:
/*
{expr -> expr [leeq] expr ~, [dot]}
{expr -> expr [leeq] expr ~, [or]}
{expr -> expr [leeq] expr ~, [and]}
{expr -> expr [leeq] expr ~, [bitor]}
{expr -> expr [leeq] expr ~, [bitand]}
{expr -> expr [leeq] expr ~, [neq]}
{expr -> expr [leeq] expr ~, [eq]}
{expr -> expr [leeq] expr ~, [gt]}
{expr -> expr [leeq] expr ~, [gteq]}
{expr -> expr [leeq] expr ~, [le]}
{expr -> expr [leeq] expr ~, [leeq]}
{expr -> expr [leeq] expr ~, [plus]}
{expr -> expr [leeq] expr ~, [minus]}
{expr -> expr [leeq] expr ~, [modulo]}
{expr -> expr [leeq] expr ~, [division]}
{expr -> expr [leeq] expr ~, [multiply]}
{expr -> expr [leeq] expr ~, [semicolon]}
{expr -> expr [leeq] expr ~, [right_b]}
{expr -> expr [leeq] expr ~, [left_c]}
{expr -> expr [leeq] expr ~, [colon]}
{expr -> expr [leeq] expr ~, [right_p]}
{expr -> expr [leeq] expr ~, [comma]}
{expr -> expr [leeq] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State35:
	states.push(&&Goto35);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce68;
		case TOKEN_and: goto Reduce68;
		case TOKEN_bitor: goto Reduce68;
		case TOKEN_bitand: goto Reduce68;
		case TOKEN_neq: goto Reduce68;
		case TOKEN_eq: goto Reduce68;
		case TOKEN_gt: goto Reduce68;
		case TOKEN_gteq: goto Reduce68;
		case TOKEN_le: goto Reduce68;
		case TOKEN_leeq: goto Reduce68;
		case TOKEN_semicolon: goto Reduce68;
		case TOKEN_right_b: goto Reduce68;
		case TOKEN_left_c: goto Reduce68;
		case TOKEN_colon: goto Reduce68;
		case TOKEN_right_p: goto Reduce68;
		case TOKEN_comma: goto Reduce68;
		case TOKEN_right_c: goto Reduce68;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto35:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift36:
/*
{expr -> expr [plus] ~ expr, [dot]}
{expr -> expr [plus] ~ expr, [or]}
{expr -> expr [plus] ~ expr, [and]}
{expr -> expr [plus] ~ expr, [bitor]}
{expr -> expr [plus] ~ expr, [bitand]}
{expr -> expr [plus] ~ expr, [neq]}
{expr -> expr [plus] ~ expr, [eq]}
{expr -> expr [plus] ~ expr, [gt]}
{expr -> expr [plus] ~ expr, [gteq]}
{expr -> expr [plus] ~ expr, [le]}
{expr -> expr [plus] ~ expr, [leeq]}
{expr -> expr [plus] ~ expr, [plus]}
{expr -> expr [plus] ~ expr, [minus]}
{expr -> expr [plus] ~ expr, [modulo]}
{expr -> expr [plus] ~ expr, [division]}
{expr -> expr [plus] ~ expr, [multiply]}
{expr -> expr [plus] ~ expr, [semicolon]}
{expr -> expr [plus] ~ expr, [right_b]}
{expr -> expr [plus] ~ expr, [left_c]}
{expr -> expr [plus] ~ expr, [colon]}
{expr -> expr [plus] ~ expr, [right_p]}
{expr -> expr [plus] ~ expr, [comma]}
{expr -> expr [plus] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State36:
	states.push(&&Goto36);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto36:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State37;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift37:
/*
{expr -> expr [plus] expr ~, [dot]}
{expr -> expr [plus] expr ~, [or]}
{expr -> expr [plus] expr ~, [and]}
{expr -> expr [plus] expr ~, [bitor]}
{expr -> expr [plus] expr ~, [bitand]}
{expr -> expr [plus] expr ~, [neq]}
{expr -> expr [plus] expr ~, [eq]}
{expr -> expr [plus] expr ~, [gt]}
{expr -> expr [plus] expr ~, [gteq]}
{expr -> expr [plus] expr ~, [le]}
{expr -> expr [plus] expr ~, [leeq]}
{expr -> expr [plus] expr ~, [plus]}
{expr -> expr [plus] expr ~, [minus]}
{expr -> expr [plus] expr ~, [modulo]}
{expr -> expr [plus] expr ~, [division]}
{expr -> expr [plus] expr ~, [multiply]}
{expr -> expr [plus] expr ~, [semicolon]}
{expr -> expr [plus] expr ~, [right_b]}
{expr -> expr [plus] expr ~, [left_c]}
{expr -> expr [plus] expr ~, [colon]}
{expr -> expr [plus] expr ~, [right_p]}
{expr -> expr [plus] expr ~, [comma]}
{expr -> expr [plus] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State37:
	states.push(&&Goto37);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce67;
		case TOKEN_and: goto Reduce67;
		case TOKEN_bitor: goto Reduce67;
		case TOKEN_bitand: goto Reduce67;
		case TOKEN_neq: goto Reduce67;
		case TOKEN_eq: goto Reduce67;
		case TOKEN_gt: goto Reduce67;
		case TOKEN_gteq: goto Reduce67;
		case TOKEN_le: goto Reduce67;
		case TOKEN_leeq: goto Reduce67;
		case TOKEN_plus: goto Reduce67;
		case TOKEN_semicolon: goto Reduce67;
		case TOKEN_right_b: goto Reduce67;
		case TOKEN_left_c: goto Reduce67;
		case TOKEN_colon: goto Reduce67;
		case TOKEN_right_p: goto Reduce67;
		case TOKEN_comma: goto Reduce67;
		case TOKEN_right_c: goto Reduce67;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto37:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift38:
/*
{expr -> expr [minus] ~ expr, [dot]}
{expr -> expr [minus] ~ expr, [or]}
{expr -> expr [minus] ~ expr, [and]}
{expr -> expr [minus] ~ expr, [bitor]}
{expr -> expr [minus] ~ expr, [bitand]}
{expr -> expr [minus] ~ expr, [neq]}
{expr -> expr [minus] ~ expr, [eq]}
{expr -> expr [minus] ~ expr, [gt]}
{expr -> expr [minus] ~ expr, [gteq]}
{expr -> expr [minus] ~ expr, [le]}
{expr -> expr [minus] ~ expr, [leeq]}
{expr -> expr [minus] ~ expr, [plus]}
{expr -> expr [minus] ~ expr, [minus]}
{expr -> expr [minus] ~ expr, [modulo]}
{expr -> expr [minus] ~ expr, [division]}
{expr -> expr [minus] ~ expr, [multiply]}
{expr -> expr [minus] ~ expr, [semicolon]}
{expr -> expr [minus] ~ expr, [right_b]}
{expr -> expr [minus] ~ expr, [left_c]}
{expr -> expr [minus] ~ expr, [colon]}
{expr -> expr [minus] ~ expr, [right_p]}
{expr -> expr [minus] ~ expr, [comma]}
{expr -> expr [minus] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State38:
	states.push(&&Goto38);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto38:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State39;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift39:
/*
{expr -> expr [minus] expr ~, [dot]}
{expr -> expr [minus] expr ~, [or]}
{expr -> expr [minus] expr ~, [and]}
{expr -> expr [minus] expr ~, [bitor]}
{expr -> expr [minus] expr ~, [bitand]}
{expr -> expr [minus] expr ~, [neq]}
{expr -> expr [minus] expr ~, [eq]}
{expr -> expr [minus] expr ~, [gt]}
{expr -> expr [minus] expr ~, [gteq]}
{expr -> expr [minus] expr ~, [le]}
{expr -> expr [minus] expr ~, [leeq]}
{expr -> expr [minus] expr ~, [plus]}
{expr -> expr [minus] expr ~, [minus]}
{expr -> expr [minus] expr ~, [modulo]}
{expr -> expr [minus] expr ~, [division]}
{expr -> expr [minus] expr ~, [multiply]}
{expr -> expr [minus] expr ~, [semicolon]}
{expr -> expr [minus] expr ~, [right_b]}
{expr -> expr [minus] expr ~, [left_c]}
{expr -> expr [minus] expr ~, [colon]}
{expr -> expr [minus] expr ~, [right_p]}
{expr -> expr [minus] expr ~, [comma]}
{expr -> expr [minus] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State39:
	states.push(&&Goto39);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce66;
		case TOKEN_and: goto Reduce66;
		case TOKEN_bitor: goto Reduce66;
		case TOKEN_bitand: goto Reduce66;
		case TOKEN_neq: goto Reduce66;
		case TOKEN_eq: goto Reduce66;
		case TOKEN_gt: goto Reduce66;
		case TOKEN_gteq: goto Reduce66;
		case TOKEN_le: goto Reduce66;
		case TOKEN_leeq: goto Reduce66;
		case TOKEN_plus: goto Reduce66;
		case TOKEN_minus: goto Reduce66;
		case TOKEN_semicolon: goto Reduce66;
		case TOKEN_right_b: goto Reduce66;
		case TOKEN_left_c: goto Reduce66;
		case TOKEN_colon: goto Reduce66;
		case TOKEN_right_p: goto Reduce66;
		case TOKEN_comma: goto Reduce66;
		case TOKEN_right_c: goto Reduce66;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto39:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift40:
/*
{expr -> expr [modulo] ~ expr, [dot]}
{expr -> expr [modulo] ~ expr, [or]}
{expr -> expr [modulo] ~ expr, [and]}
{expr -> expr [modulo] ~ expr, [bitor]}
{expr -> expr [modulo] ~ expr, [bitand]}
{expr -> expr [modulo] ~ expr, [neq]}
{expr -> expr [modulo] ~ expr, [eq]}
{expr -> expr [modulo] ~ expr, [gt]}
{expr -> expr [modulo] ~ expr, [gteq]}
{expr -> expr [modulo] ~ expr, [le]}
{expr -> expr [modulo] ~ expr, [leeq]}
{expr -> expr [modulo] ~ expr, [plus]}
{expr -> expr [modulo] ~ expr, [minus]}
{expr -> expr [modulo] ~ expr, [modulo]}
{expr -> expr [modulo] ~ expr, [division]}
{expr -> expr [modulo] ~ expr, [multiply]}
{expr -> expr [modulo] ~ expr, [semicolon]}
{expr -> expr [modulo] ~ expr, [right_b]}
{expr -> expr [modulo] ~ expr, [left_c]}
{expr -> expr [modulo] ~ expr, [colon]}
{expr -> expr [modulo] ~ expr, [right_p]}
{expr -> expr [modulo] ~ expr, [comma]}
{expr -> expr [modulo] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State40:
	states.push(&&Goto40);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto40:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State41;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift41:
/*
{expr -> expr [modulo] expr ~, [dot]}
{expr -> expr [modulo] expr ~, [or]}
{expr -> expr [modulo] expr ~, [and]}
{expr -> expr [modulo] expr ~, [bitor]}
{expr -> expr [modulo] expr ~, [bitand]}
{expr -> expr [modulo] expr ~, [neq]}
{expr -> expr [modulo] expr ~, [eq]}
{expr -> expr [modulo] expr ~, [gt]}
{expr -> expr [modulo] expr ~, [gteq]}
{expr -> expr [modulo] expr ~, [le]}
{expr -> expr [modulo] expr ~, [leeq]}
{expr -> expr [modulo] expr ~, [plus]}
{expr -> expr [modulo] expr ~, [minus]}
{expr -> expr [modulo] expr ~, [modulo]}
{expr -> expr [modulo] expr ~, [division]}
{expr -> expr [modulo] expr ~, [multiply]}
{expr -> expr [modulo] expr ~, [semicolon]}
{expr -> expr [modulo] expr ~, [right_b]}
{expr -> expr [modulo] expr ~, [left_c]}
{expr -> expr [modulo] expr ~, [colon]}
{expr -> expr [modulo] expr ~, [right_p]}
{expr -> expr [modulo] expr ~, [comma]}
{expr -> expr [modulo] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State41:
	states.push(&&Goto41);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce65;
		case TOKEN_and: goto Reduce65;
		case TOKEN_bitor: goto Reduce65;
		case TOKEN_bitand: goto Reduce65;
		case TOKEN_neq: goto Reduce65;
		case TOKEN_eq: goto Reduce65;
		case TOKEN_gt: goto Reduce65;
		case TOKEN_gteq: goto Reduce65;
		case TOKEN_le: goto Reduce65;
		case TOKEN_leeq: goto Reduce65;
		case TOKEN_plus: goto Reduce65;
		case TOKEN_minus: goto Reduce65;
		case TOKEN_modulo: goto Reduce65;
		case TOKEN_semicolon: goto Reduce65;
		case TOKEN_right_b: goto Reduce65;
		case TOKEN_left_c: goto Reduce65;
		case TOKEN_colon: goto Reduce65;
		case TOKEN_right_p: goto Reduce65;
		case TOKEN_comma: goto Reduce65;
		case TOKEN_right_c: goto Reduce65;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto41:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift42:
/*
{expr -> expr [division] ~ expr, [dot]}
{expr -> expr [division] ~ expr, [or]}
{expr -> expr [division] ~ expr, [and]}
{expr -> expr [division] ~ expr, [bitor]}
{expr -> expr [division] ~ expr, [bitand]}
{expr -> expr [division] ~ expr, [neq]}
{expr -> expr [division] ~ expr, [eq]}
{expr -> expr [division] ~ expr, [gt]}
{expr -> expr [division] ~ expr, [gteq]}
{expr -> expr [division] ~ expr, [le]}
{expr -> expr [division] ~ expr, [leeq]}
{expr -> expr [division] ~ expr, [plus]}
{expr -> expr [division] ~ expr, [minus]}
{expr -> expr [division] ~ expr, [modulo]}
{expr -> expr [division] ~ expr, [division]}
{expr -> expr [division] ~ expr, [multiply]}
{expr -> expr [division] ~ expr, [semicolon]}
{expr -> expr [division] ~ expr, [right_b]}
{expr -> expr [division] ~ expr, [left_c]}
{expr -> expr [division] ~ expr, [colon]}
{expr -> expr [division] ~ expr, [right_p]}
{expr -> expr [division] ~ expr, [comma]}
{expr -> expr [division] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State42:
	states.push(&&Goto42);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto42:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State43;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift43:
/*
{expr -> expr [division] expr ~, [dot]}
{expr -> expr [division] expr ~, [or]}
{expr -> expr [division] expr ~, [and]}
{expr -> expr [division] expr ~, [bitor]}
{expr -> expr [division] expr ~, [bitand]}
{expr -> expr [division] expr ~, [neq]}
{expr -> expr [division] expr ~, [eq]}
{expr -> expr [division] expr ~, [gt]}
{expr -> expr [division] expr ~, [gteq]}
{expr -> expr [division] expr ~, [le]}
{expr -> expr [division] expr ~, [leeq]}
{expr -> expr [division] expr ~, [plus]}
{expr -> expr [division] expr ~, [minus]}
{expr -> expr [division] expr ~, [modulo]}
{expr -> expr [division] expr ~, [division]}
{expr -> expr [division] expr ~, [multiply]}
{expr -> expr [division] expr ~, [semicolon]}
{expr -> expr [division] expr ~, [right_b]}
{expr -> expr [division] expr ~, [left_c]}
{expr -> expr [division] expr ~, [colon]}
{expr -> expr [division] expr ~, [right_p]}
{expr -> expr [division] expr ~, [comma]}
{expr -> expr [division] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State43:
	states.push(&&Goto43);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce64;
		case TOKEN_and: goto Reduce64;
		case TOKEN_bitor: goto Reduce64;
		case TOKEN_bitand: goto Reduce64;
		case TOKEN_neq: goto Reduce64;
		case TOKEN_eq: goto Reduce64;
		case TOKEN_gt: goto Reduce64;
		case TOKEN_gteq: goto Reduce64;
		case TOKEN_le: goto Reduce64;
		case TOKEN_leeq: goto Reduce64;
		case TOKEN_plus: goto Reduce64;
		case TOKEN_minus: goto Reduce64;
		case TOKEN_modulo: goto Reduce64;
		case TOKEN_division: goto Reduce64;
		case TOKEN_semicolon: goto Reduce64;
		case TOKEN_right_b: goto Reduce64;
		case TOKEN_left_c: goto Reduce64;
		case TOKEN_colon: goto Reduce64;
		case TOKEN_right_p: goto Reduce64;
		case TOKEN_comma: goto Reduce64;
		case TOKEN_right_c: goto Reduce64;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto43:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift44:
/*
{expr -> expr [multiply] ~ expr, [dot]}
{expr -> expr [multiply] ~ expr, [or]}
{expr -> expr [multiply] ~ expr, [and]}
{expr -> expr [multiply] ~ expr, [bitor]}
{expr -> expr [multiply] ~ expr, [bitand]}
{expr -> expr [multiply] ~ expr, [neq]}
{expr -> expr [multiply] ~ expr, [eq]}
{expr -> expr [multiply] ~ expr, [gt]}
{expr -> expr [multiply] ~ expr, [gteq]}
{expr -> expr [multiply] ~ expr, [le]}
{expr -> expr [multiply] ~ expr, [leeq]}
{expr -> expr [multiply] ~ expr, [plus]}
{expr -> expr [multiply] ~ expr, [minus]}
{expr -> expr [multiply] ~ expr, [modulo]}
{expr -> expr [multiply] ~ expr, [division]}
{expr -> expr [multiply] ~ expr, [multiply]}
{expr -> expr [multiply] ~ expr, [semicolon]}
{expr -> expr [multiply] ~ expr, [right_b]}
{expr -> expr [multiply] ~ expr, [left_c]}
{expr -> expr [multiply] ~ expr, [colon]}
{expr -> expr [multiply] ~ expr, [right_p]}
{expr -> expr [multiply] ~ expr, [comma]}
{expr -> expr [multiply] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State44:
	states.push(&&Goto44);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto44:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State45;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift45:
/*
{expr -> expr [multiply] expr ~, [dot]}
{expr -> expr [multiply] expr ~, [or]}
{expr -> expr [multiply] expr ~, [and]}
{expr -> expr [multiply] expr ~, [bitor]}
{expr -> expr [multiply] expr ~, [bitand]}
{expr -> expr [multiply] expr ~, [neq]}
{expr -> expr [multiply] expr ~, [eq]}
{expr -> expr [multiply] expr ~, [gt]}
{expr -> expr [multiply] expr ~, [gteq]}
{expr -> expr [multiply] expr ~, [le]}
{expr -> expr [multiply] expr ~, [leeq]}
{expr -> expr [multiply] expr ~, [plus]}
{expr -> expr [multiply] expr ~, [minus]}
{expr -> expr [multiply] expr ~, [modulo]}
{expr -> expr [multiply] expr ~, [division]}
{expr -> expr [multiply] expr ~, [multiply]}
{expr -> expr [multiply] expr ~, [semicolon]}
{expr -> expr [multiply] expr ~, [right_b]}
{expr -> expr [multiply] expr ~, [left_c]}
{expr -> expr [multiply] expr ~, [colon]}
{expr -> expr [multiply] expr ~, [right_p]}
{expr -> expr [multiply] expr ~, [comma]}
{expr -> expr [multiply] expr ~, [right_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [comma]}
{expr -> expr ~ [or] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State45:
	states.push(&&Goto45);
	switch(current_terminal->token()){
		case TOKEN_or: goto Reduce63;
		case TOKEN_and: goto Reduce63;
		case TOKEN_bitor: goto Reduce63;
		case TOKEN_bitand: goto Reduce63;
		case TOKEN_neq: goto Reduce63;
		case TOKEN_eq: goto Reduce63;
		case TOKEN_gt: goto Reduce63;
		case TOKEN_gteq: goto Reduce63;
		case TOKEN_le: goto Reduce63;
		case TOKEN_leeq: goto Reduce63;
		case TOKEN_plus: goto Reduce63;
		case TOKEN_minus: goto Reduce63;
		case TOKEN_modulo: goto Reduce63;
		case TOKEN_division: goto Reduce63;
		case TOKEN_multiply: goto Reduce63;
		case TOKEN_semicolon: goto Reduce63;
		case TOKEN_right_b: goto Reduce63;
		case TOKEN_left_c: goto Reduce63;
		case TOKEN_colon: goto Reduce63;
		case TOKEN_right_p: goto Reduce63;
		case TOKEN_comma: goto Reduce63;
		case TOKEN_right_c: goto Reduce63;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto45:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift46:
/*
{varexpr -> expr [dot] ~ [id], [dot]}
{varexpr -> expr [dot] ~ [id], [left_p]}
{varexpr -> expr [dot] ~ [id], [or]}
{varexpr -> expr [dot] ~ [id], [and]}
{varexpr -> expr [dot] ~ [id], [bitor]}
{varexpr -> expr [dot] ~ [id], [bitand]}
{varexpr -> expr [dot] ~ [id], [neq]}
{varexpr -> expr [dot] ~ [id], [eq]}
{varexpr -> expr [dot] ~ [id], [gt]}
{varexpr -> expr [dot] ~ [id], [gteq]}
{varexpr -> expr [dot] ~ [id], [le]}
{varexpr -> expr [dot] ~ [id], [leeq]}
{varexpr -> expr [dot] ~ [id], [plus]}
{varexpr -> expr [dot] ~ [id], [minus]}
{varexpr -> expr [dot] ~ [id], [modulo]}
{varexpr -> expr [dot] ~ [id], [division]}
{varexpr -> expr [dot] ~ [id], [multiply]}
{varexpr -> expr [dot] ~ [id], [semicolon]}
{varexpr -> expr [dot] ~ [id], [right_b]}
{varexpr -> expr [dot] ~ [id], [left_c]}
{varexpr -> expr [dot] ~ [id], [colon]}
{varexpr -> expr [dot] ~ [id], [right_p]}
{varexpr -> expr [dot] ~ [id], [comma]}
{varexpr -> expr [dot] ~ [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State46:
	states.push(&&Goto46);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift47;
		default: goto ERROR;
	}

Goto46:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift47:
/*
{varexpr -> expr [dot] [id] ~, [dot]}
{varexpr -> expr [dot] [id] ~, [left_p]}
{varexpr -> expr [dot] [id] ~, [or]}
{varexpr -> expr [dot] [id] ~, [and]}
{varexpr -> expr [dot] [id] ~, [bitor]}
{varexpr -> expr [dot] [id] ~, [bitand]}
{varexpr -> expr [dot] [id] ~, [neq]}
{varexpr -> expr [dot] [id] ~, [eq]}
{varexpr -> expr [dot] [id] ~, [gt]}
{varexpr -> expr [dot] [id] ~, [gteq]}
{varexpr -> expr [dot] [id] ~, [le]}
{varexpr -> expr [dot] [id] ~, [leeq]}
{varexpr -> expr [dot] [id] ~, [plus]}
{varexpr -> expr [dot] [id] ~, [minus]}
{varexpr -> expr [dot] [id] ~, [modulo]}
{varexpr -> expr [dot] [id] ~, [division]}
{varexpr -> expr [dot] [id] ~, [multiply]}
{varexpr -> expr [dot] [id] ~, [semicolon]}
{varexpr -> expr [dot] [id] ~, [right_b]}
{varexpr -> expr [dot] [id] ~, [left_c]}
{varexpr -> expr [dot] [id] ~, [colon]}
{varexpr -> expr [dot] [id] ~, [right_p]}
{varexpr -> expr [dot] [id] ~, [comma]}
{varexpr -> expr [dot] [id] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State47:
	states.push(&&Goto47);
	switch(current_terminal->token()){
		case TOKEN_dot: goto Reduce37;
		case TOKEN_left_p: goto Reduce37;
		case TOKEN_or: goto Reduce37;
		case TOKEN_and: goto Reduce37;
		case TOKEN_bitor: goto Reduce37;
		case TOKEN_bitand: goto Reduce37;
		case TOKEN_neq: goto Reduce37;
		case TOKEN_eq: goto Reduce37;
		case TOKEN_gt: goto Reduce37;
		case TOKEN_gteq: goto Reduce37;
		case TOKEN_le: goto Reduce37;
		case TOKEN_leeq: goto Reduce37;
		case TOKEN_plus: goto Reduce37;
		case TOKEN_minus: goto Reduce37;
		case TOKEN_modulo: goto Reduce37;
		case TOKEN_division: goto Reduce37;
		case TOKEN_multiply: goto Reduce37;
		case TOKEN_semicolon: goto Reduce37;
		case TOKEN_right_b: goto Reduce37;
		case TOKEN_left_c: goto Reduce37;
		case TOKEN_colon: goto Reduce37;
		case TOKEN_right_p: goto Reduce37;
		case TOKEN_comma: goto Reduce37;
		case TOKEN_right_c: goto Reduce37;
		default: goto ERROR;
	}

Goto47:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift48:
/*
{varexpr -> [id] ~ [left_b] expr [right_b], [dot]}
{varexpr -> [id] ~ [left_b] expr [right_b], [left_p]}
{varexpr -> [id] ~ [left_b] expr [right_b], [or]}
{varexpr -> [id] ~ [left_b] expr [right_b], [and]}
{varexpr -> [id] ~ [left_b] expr [right_b], [bitor]}
{varexpr -> [id] ~ [left_b] expr [right_b], [bitand]}
{varexpr -> [id] ~ [left_b] expr [right_b], [neq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [eq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [gt]}
{varexpr -> [id] ~ [left_b] expr [right_b], [gteq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [le]}
{varexpr -> [id] ~ [left_b] expr [right_b], [leeq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [plus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [minus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [modulo]}
{varexpr -> [id] ~ [left_b] expr [right_b], [division]}
{varexpr -> [id] ~ [left_b] expr [right_b], [multiply]}
{varexpr -> [id] ~ [left_b] expr [right_b], [right_b]}
{varexpr -> [id] ~ [left_b] expr [right_b], [left_c]}
{varexpr -> [id] ~ [left_b] expr [right_b], [colon]}
{varexpr -> [id] ~ [left_b] expr [right_b], [right_p]}
{varexpr -> [id] ~ [left_b] expr [right_b], [comma]}
{varexpr -> [id] ~ [left_b] expr [right_b], [semicolon]}
{varexpr -> [id] ~ [left_b] expr [right_b], [right_c]}
{varexpr -> [id] ~, [dot]}
{varexpr -> [id] ~, [left_p]}
{varexpr -> [id] ~, [or]}
{varexpr -> [id] ~, [and]}
{varexpr -> [id] ~, [bitor]}
{varexpr -> [id] ~, [bitand]}
{varexpr -> [id] ~, [neq]}
{varexpr -> [id] ~, [eq]}
{varexpr -> [id] ~, [gt]}
{varexpr -> [id] ~, [gteq]}
{varexpr -> [id] ~, [le]}
{varexpr -> [id] ~, [leeq]}
{varexpr -> [id] ~, [plus]}
{varexpr -> [id] ~, [minus]}
{varexpr -> [id] ~, [modulo]}
{varexpr -> [id] ~, [division]}
{varexpr -> [id] ~, [multiply]}
{varexpr -> [id] ~, [right_b]}
{varexpr -> [id] ~, [left_c]}
{varexpr -> [id] ~, [colon]}
{varexpr -> [id] ~, [right_p]}
{varexpr -> [id] ~, [comma]}
{varexpr -> [id] ~, [semicolon]}
{varexpr -> [id] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State48:
	states.push(&&Goto48);
	switch(current_terminal->token()){
		case TOKEN_left_b: goto Shift49;
		case TOKEN_dot: goto Reduce36;
		case TOKEN_left_p: goto Reduce36;
		case TOKEN_or: goto Reduce36;
		case TOKEN_and: goto Reduce36;
		case TOKEN_bitor: goto Reduce36;
		case TOKEN_bitand: goto Reduce36;
		case TOKEN_neq: goto Reduce36;
		case TOKEN_eq: goto Reduce36;
		case TOKEN_gt: goto Reduce36;
		case TOKEN_gteq: goto Reduce36;
		case TOKEN_le: goto Reduce36;
		case TOKEN_leeq: goto Reduce36;
		case TOKEN_plus: goto Reduce36;
		case TOKEN_minus: goto Reduce36;
		case TOKEN_modulo: goto Reduce36;
		case TOKEN_division: goto Reduce36;
		case TOKEN_multiply: goto Reduce36;
		case TOKEN_right_b: goto Reduce36;
		case TOKEN_left_c: goto Reduce36;
		case TOKEN_colon: goto Reduce36;
		case TOKEN_right_p: goto Reduce36;
		case TOKEN_comma: goto Reduce36;
		case TOKEN_semicolon: goto Reduce36;
		case TOKEN_right_c: goto Reduce36;
		default: goto ERROR;
	}

Goto48:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift49:
/*
{varexpr -> [id] [left_b] ~ expr [right_b], [dot]}
{varexpr -> [id] [left_b] ~ expr [right_b], [left_p]}
{varexpr -> [id] [left_b] ~ expr [right_b], [or]}
{varexpr -> [id] [left_b] ~ expr [right_b], [and]}
{varexpr -> [id] [left_b] ~ expr [right_b], [bitor]}
{varexpr -> [id] [left_b] ~ expr [right_b], [bitand]}
{varexpr -> [id] [left_b] ~ expr [right_b], [neq]}
{varexpr -> [id] [left_b] ~ expr [right_b], [eq]}
{varexpr -> [id] [left_b] ~ expr [right_b], [gt]}
{varexpr -> [id] [left_b] ~ expr [right_b], [gteq]}
{varexpr -> [id] [left_b] ~ expr [right_b], [le]}
{varexpr -> [id] [left_b] ~ expr [right_b], [leeq]}
{varexpr -> [id] [left_b] ~ expr [right_b], [plus]}
{varexpr -> [id] [left_b] ~ expr [right_b], [minus]}
{varexpr -> [id] [left_b] ~ expr [right_b], [modulo]}
{varexpr -> [id] [left_b] ~ expr [right_b], [division]}
{varexpr -> [id] [left_b] ~ expr [right_b], [multiply]}
{varexpr -> [id] [left_b] ~ expr [right_b], [right_b]}
{varexpr -> [id] [left_b] ~ expr [right_b], [left_c]}
{varexpr -> [id] [left_b] ~ expr [right_b], [colon]}
{varexpr -> [id] [left_b] ~ expr [right_b], [right_p]}
{varexpr -> [id] [left_b] ~ expr [right_b], [comma]}
{varexpr -> [id] [left_b] ~ expr [right_b], [semicolon]}
{varexpr -> [id] [left_b] ~ expr [right_b], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State49:
	states.push(&&Goto49);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto49:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State50;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift50:
/*
{varexpr -> [id] [left_b] expr ~ [right_b], [dot]}
{varexpr -> [id] [left_b] expr ~ [right_b], [left_p]}
{varexpr -> [id] [left_b] expr ~ [right_b], [or]}
{varexpr -> [id] [left_b] expr ~ [right_b], [and]}
{varexpr -> [id] [left_b] expr ~ [right_b], [bitor]}
{varexpr -> [id] [left_b] expr ~ [right_b], [bitand]}
{varexpr -> [id] [left_b] expr ~ [right_b], [neq]}
{varexpr -> [id] [left_b] expr ~ [right_b], [eq]}
{varexpr -> [id] [left_b] expr ~ [right_b], [gt]}
{varexpr -> [id] [left_b] expr ~ [right_b], [gteq]}
{varexpr -> [id] [left_b] expr ~ [right_b], [le]}
{varexpr -> [id] [left_b] expr ~ [right_b], [leeq]}
{varexpr -> [id] [left_b] expr ~ [right_b], [plus]}
{varexpr -> [id] [left_b] expr ~ [right_b], [minus]}
{varexpr -> [id] [left_b] expr ~ [right_b], [modulo]}
{varexpr -> [id] [left_b] expr ~ [right_b], [division]}
{varexpr -> [id] [left_b] expr ~ [right_b], [multiply]}
{varexpr -> [id] [left_b] expr ~ [right_b], [right_b]}
{varexpr -> [id] [left_b] expr ~ [right_b], [left_c]}
{varexpr -> [id] [left_b] expr ~ [right_b], [colon]}
{varexpr -> [id] [left_b] expr ~ [right_b], [right_p]}
{varexpr -> [id] [left_b] expr ~ [right_b], [comma]}
{varexpr -> [id] [left_b] expr ~ [right_b], [semicolon]}
{varexpr -> [id] [left_b] expr ~ [right_b], [right_c]}
{expr -> expr ~ [multiply] expr, [right_b]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [division] expr, [right_b]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [right_b]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [right_b]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [le] expr, [right_b]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [right_b]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gt] expr, [right_b]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [right_b]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [right_b]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [and] expr, [right_b]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [or] expr, [right_b]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State50:
	states.push(&&Goto50);
	switch(current_terminal->token()){
		case TOKEN_right_b: goto Shift51;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto50:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift51:
/*
{varexpr -> [id] [left_b] expr [right_b] ~, [dot]}
{varexpr -> [id] [left_b] expr [right_b] ~, [left_p]}
{varexpr -> [id] [left_b] expr [right_b] ~, [or]}
{varexpr -> [id] [left_b] expr [right_b] ~, [and]}
{varexpr -> [id] [left_b] expr [right_b] ~, [bitor]}
{varexpr -> [id] [left_b] expr [right_b] ~, [bitand]}
{varexpr -> [id] [left_b] expr [right_b] ~, [neq]}
{varexpr -> [id] [left_b] expr [right_b] ~, [eq]}
{varexpr -> [id] [left_b] expr [right_b] ~, [gt]}
{varexpr -> [id] [left_b] expr [right_b] ~, [gteq]}
{varexpr -> [id] [left_b] expr [right_b] ~, [le]}
{varexpr -> [id] [left_b] expr [right_b] ~, [leeq]}
{varexpr -> [id] [left_b] expr [right_b] ~, [plus]}
{varexpr -> [id] [left_b] expr [right_b] ~, [minus]}
{varexpr -> [id] [left_b] expr [right_b] ~, [modulo]}
{varexpr -> [id] [left_b] expr [right_b] ~, [division]}
{varexpr -> [id] [left_b] expr [right_b] ~, [multiply]}
{varexpr -> [id] [left_b] expr [right_b] ~, [right_b]}
{varexpr -> [id] [left_b] expr [right_b] ~, [left_c]}
{varexpr -> [id] [left_b] expr [right_b] ~, [colon]}
{varexpr -> [id] [left_b] expr [right_b] ~, [right_p]}
{varexpr -> [id] [left_b] expr [right_b] ~, [comma]}
{varexpr -> [id] [left_b] expr [right_b] ~, [semicolon]}
{varexpr -> [id] [left_b] expr [right_b] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State51:
	states.push(&&Goto51);
	switch(current_terminal->token()){
		case TOKEN_dot: goto Reduce35;
		case TOKEN_left_p: goto Reduce35;
		case TOKEN_or: goto Reduce35;
		case TOKEN_and: goto Reduce35;
		case TOKEN_bitor: goto Reduce35;
		case TOKEN_bitand: goto Reduce35;
		case TOKEN_neq: goto Reduce35;
		case TOKEN_eq: goto Reduce35;
		case TOKEN_gt: goto Reduce35;
		case TOKEN_gteq: goto Reduce35;
		case TOKEN_le: goto Reduce35;
		case TOKEN_leeq: goto Reduce35;
		case TOKEN_plus: goto Reduce35;
		case TOKEN_minus: goto Reduce35;
		case TOKEN_modulo: goto Reduce35;
		case TOKEN_division: goto Reduce35;
		case TOKEN_multiply: goto Reduce35;
		case TOKEN_right_b: goto Reduce35;
		case TOKEN_left_c: goto Reduce35;
		case TOKEN_colon: goto Reduce35;
		case TOKEN_right_p: goto Reduce35;
		case TOKEN_comma: goto Reduce35;
		case TOKEN_semicolon: goto Reduce35;
		case TOKEN_right_c: goto Reduce35;
		default: goto ERROR;
	}

Goto51:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift52:
/*
{expr -> dictblock ~, [semicolon]}
{expr -> dictblock ~, [dot]}
{expr -> dictblock ~, [or]}
{expr -> dictblock ~, [and]}
{expr -> dictblock ~, [bitor]}
{expr -> dictblock ~, [bitand]}
{expr -> dictblock ~, [neq]}
{expr -> dictblock ~, [eq]}
{expr -> dictblock ~, [gt]}
{expr -> dictblock ~, [gteq]}
{expr -> dictblock ~, [le]}
{expr -> dictblock ~, [leeq]}
{expr -> dictblock ~, [plus]}
{expr -> dictblock ~, [minus]}
{expr -> dictblock ~, [modulo]}
{expr -> dictblock ~, [division]}
{expr -> dictblock ~, [multiply]}
{expr -> dictblock ~, [right_b]}
{expr -> dictblock ~, [left_c]}
{expr -> dictblock ~, [colon]}
{expr -> dictblock ~, [right_p]}
{expr -> dictblock ~, [comma]}
{expr -> dictblock ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State52:
	states.push(&&Goto52);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce61;
		case TOKEN_dot: goto Reduce61;
		case TOKEN_or: goto Reduce61;
		case TOKEN_and: goto Reduce61;
		case TOKEN_bitor: goto Reduce61;
		case TOKEN_bitand: goto Reduce61;
		case TOKEN_neq: goto Reduce61;
		case TOKEN_eq: goto Reduce61;
		case TOKEN_gt: goto Reduce61;
		case TOKEN_gteq: goto Reduce61;
		case TOKEN_le: goto Reduce61;
		case TOKEN_leeq: goto Reduce61;
		case TOKEN_plus: goto Reduce61;
		case TOKEN_minus: goto Reduce61;
		case TOKEN_modulo: goto Reduce61;
		case TOKEN_division: goto Reduce61;
		case TOKEN_multiply: goto Reduce61;
		case TOKEN_right_b: goto Reduce61;
		case TOKEN_left_c: goto Reduce61;
		case TOKEN_colon: goto Reduce61;
		case TOKEN_right_p: goto Reduce61;
		case TOKEN_comma: goto Reduce61;
		case TOKEN_right_c: goto Reduce61;
		default: goto ERROR;
	}

Goto52:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift53:
/*
{closedStmt -> [for] ~ [id] [in] expr block, [right_c]}
{closedStmt -> [for] ~ [id] [in] expr block, [out]}
{closedStmt -> [for] ~ [id] [in] expr block, [in]}
{closedStmt -> [for] ~ [id] [in] expr block, [return]}
{closedStmt -> [for] ~ [id] [in] expr block, [id]}
{closedStmt -> [for] ~ [id] [in] expr block, [left_p]}
{closedStmt -> [for] ~ [id] [in] expr block, [left_c]}
{closedStmt -> [for] ~ [id] [in] expr block, [not]}
{closedStmt -> [for] ~ [id] [in] expr block, [int]}
{closedStmt -> [for] ~ [id] [in] expr block, [if]}
{closedStmt -> [for] ~ [id] [in] expr block, [while]}
{closedStmt -> [for] ~ [id] [in] expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State53:
	states.push(&&Goto53);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift54;
		default: goto ERROR;
	}

Goto53:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift54:
/*
{closedStmt -> [for] [id] ~ [in] expr block, [right_c]}
{closedStmt -> [for] [id] ~ [in] expr block, [out]}
{closedStmt -> [for] [id] ~ [in] expr block, [in]}
{closedStmt -> [for] [id] ~ [in] expr block, [return]}
{closedStmt -> [for] [id] ~ [in] expr block, [id]}
{closedStmt -> [for] [id] ~ [in] expr block, [left_p]}
{closedStmt -> [for] [id] ~ [in] expr block, [left_c]}
{closedStmt -> [for] [id] ~ [in] expr block, [not]}
{closedStmt -> [for] [id] ~ [in] expr block, [int]}
{closedStmt -> [for] [id] ~ [in] expr block, [if]}
{closedStmt -> [for] [id] ~ [in] expr block, [while]}
{closedStmt -> [for] [id] ~ [in] expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State54:
	states.push(&&Goto54);
	switch(current_terminal->token()){
		case TOKEN_in: goto Shift55;
		default: goto ERROR;
	}

Goto54:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift55:
/*
{closedStmt -> [for] [id] [in] ~ expr block, [right_c]}
{closedStmt -> [for] [id] [in] ~ expr block, [out]}
{closedStmt -> [for] [id] [in] ~ expr block, [in]}
{closedStmt -> [for] [id] [in] ~ expr block, [return]}
{closedStmt -> [for] [id] [in] ~ expr block, [id]}
{closedStmt -> [for] [id] [in] ~ expr block, [left_p]}
{closedStmt -> [for] [id] [in] ~ expr block, [left_c]}
{closedStmt -> [for] [id] [in] ~ expr block, [not]}
{closedStmt -> [for] [id] [in] ~ expr block, [int]}
{closedStmt -> [for] [id] [in] ~ expr block, [if]}
{closedStmt -> [for] [id] [in] ~ expr block, [while]}
{closedStmt -> [for] [id] [in] ~ expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State55:
	states.push(&&Goto55);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto55:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State56;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift56:
/*
{closedStmt -> [for] [id] [in] expr ~ block, [right_c]}
{closedStmt -> [for] [id] [in] expr ~ block, [out]}
{closedStmt -> [for] [id] [in] expr ~ block, [in]}
{closedStmt -> [for] [id] [in] expr ~ block, [return]}
{closedStmt -> [for] [id] [in] expr ~ block, [id]}
{closedStmt -> [for] [id] [in] expr ~ block, [left_p]}
{closedStmt -> [for] [id] [in] expr ~ block, [left_c]}
{closedStmt -> [for] [id] [in] expr ~ block, [not]}
{closedStmt -> [for] [id] [in] expr ~ block, [int]}
{closedStmt -> [for] [id] [in] expr ~ block, [if]}
{closedStmt -> [for] [id] [in] expr ~ block, [while]}
{closedStmt -> [for] [id] [in] expr ~ block, [for]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State56:
	states.push(&&Goto56);
	switch(current_terminal->token()){
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto56:
	switch(top_non_terminal){
		case SYMBOL_block: goto State57;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift57:
/*
{closedStmt -> [for] [id] [in] expr block ~, [right_c]}
{closedStmt -> [for] [id] [in] expr block ~, [out]}
{closedStmt -> [for] [id] [in] expr block ~, [in]}
{closedStmt -> [for] [id] [in] expr block ~, [return]}
{closedStmt -> [for] [id] [in] expr block ~, [id]}
{closedStmt -> [for] [id] [in] expr block ~, [left_p]}
{closedStmt -> [for] [id] [in] expr block ~, [left_c]}
{closedStmt -> [for] [id] [in] expr block ~, [not]}
{closedStmt -> [for] [id] [in] expr block ~, [int]}
{closedStmt -> [for] [id] [in] expr block ~, [if]}
{closedStmt -> [for] [id] [in] expr block ~, [while]}
{closedStmt -> [for] [id] [in] expr block ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State57:
	states.push(&&Goto57);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce41;
		case TOKEN_out: goto Reduce41;
		case TOKEN_in: goto Reduce41;
		case TOKEN_return: goto Reduce41;
		case TOKEN_id: goto Reduce41;
		case TOKEN_left_p: goto Reduce41;
		case TOKEN_left_c: goto Reduce41;
		case TOKEN_not: goto Reduce41;
		case TOKEN_int: goto Reduce41;
		case TOKEN_if: goto Reduce41;
		case TOKEN_while: goto Reduce41;
		case TOKEN_for: goto Reduce41;
		default: goto ERROR;
	}

Goto57:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift58:
/*
{closedStmt -> [while] ~ expr block, [right_c]}
{closedStmt -> [while] ~ expr block, [out]}
{closedStmt -> [while] ~ expr block, [in]}
{closedStmt -> [while] ~ expr block, [return]}
{closedStmt -> [while] ~ expr block, [id]}
{closedStmt -> [while] ~ expr block, [left_p]}
{closedStmt -> [while] ~ expr block, [left_c]}
{closedStmt -> [while] ~ expr block, [not]}
{closedStmt -> [while] ~ expr block, [int]}
{closedStmt -> [while] ~ expr block, [if]}
{closedStmt -> [while] ~ expr block, [while]}
{closedStmt -> [while] ~ expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State58:
	states.push(&&Goto58);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto58:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State59;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift59:
/*
{closedStmt -> [while] expr ~ block, [right_c]}
{closedStmt -> [while] expr ~ block, [out]}
{closedStmt -> [while] expr ~ block, [in]}
{closedStmt -> [while] expr ~ block, [return]}
{closedStmt -> [while] expr ~ block, [id]}
{closedStmt -> [while] expr ~ block, [left_p]}
{closedStmt -> [while] expr ~ block, [left_c]}
{closedStmt -> [while] expr ~ block, [not]}
{closedStmt -> [while] expr ~ block, [int]}
{closedStmt -> [while] expr ~ block, [if]}
{closedStmt -> [while] expr ~ block, [while]}
{closedStmt -> [while] expr ~ block, [for]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State59:
	states.push(&&Goto59);
	switch(current_terminal->token()){
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto59:
	switch(top_non_terminal){
		case SYMBOL_block: goto State60;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift60:
/*
{closedStmt -> [while] expr block ~, [right_c]}
{closedStmt -> [while] expr block ~, [out]}
{closedStmt -> [while] expr block ~, [in]}
{closedStmt -> [while] expr block ~, [return]}
{closedStmt -> [while] expr block ~, [id]}
{closedStmt -> [while] expr block ~, [left_p]}
{closedStmt -> [while] expr block ~, [left_c]}
{closedStmt -> [while] expr block ~, [not]}
{closedStmt -> [while] expr block ~, [int]}
{closedStmt -> [while] expr block ~, [if]}
{closedStmt -> [while] expr block ~, [while]}
{closedStmt -> [while] expr block ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State60:
	states.push(&&Goto60);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce40;
		case TOKEN_out: goto Reduce40;
		case TOKEN_in: goto Reduce40;
		case TOKEN_return: goto Reduce40;
		case TOKEN_id: goto Reduce40;
		case TOKEN_left_p: goto Reduce40;
		case TOKEN_left_c: goto Reduce40;
		case TOKEN_not: goto Reduce40;
		case TOKEN_int: goto Reduce40;
		case TOKEN_if: goto Reduce40;
		case TOKEN_while: goto Reduce40;
		case TOKEN_for: goto Reduce40;
		default: goto ERROR;
	}

Goto60:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift61:
/*
{closedStmt -> [if] ~ expr block, [right_c]}
{closedStmt -> [if] ~ expr block, [out]}
{closedStmt -> [if] ~ expr block, [in]}
{closedStmt -> [if] ~ expr block, [return]}
{closedStmt -> [if] ~ expr block, [id]}
{closedStmt -> [if] ~ expr block, [left_p]}
{closedStmt -> [if] ~ expr block, [left_c]}
{closedStmt -> [if] ~ expr block, [not]}
{closedStmt -> [if] ~ expr block, [int]}
{closedStmt -> [if] ~ expr block, [if]}
{closedStmt -> [if] ~ expr block, [while]}
{closedStmt -> [if] ~ expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State61:
	states.push(&&Goto61);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto61:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State62;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift62:
/*
{closedStmt -> [if] expr ~ block, [right_c]}
{closedStmt -> [if] expr ~ block, [out]}
{closedStmt -> [if] expr ~ block, [in]}
{closedStmt -> [if] expr ~ block, [return]}
{closedStmt -> [if] expr ~ block, [id]}
{closedStmt -> [if] expr ~ block, [left_p]}
{closedStmt -> [if] expr ~ block, [left_c]}
{closedStmt -> [if] expr ~ block, [not]}
{closedStmt -> [if] expr ~ block, [int]}
{closedStmt -> [if] expr ~ block, [if]}
{closedStmt -> [if] expr ~ block, [while]}
{closedStmt -> [if] expr ~ block, [for]}
{expr -> expr ~ [multiply] expr, [left_c]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [division] expr, [left_c]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [left_c]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [left_c]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [le] expr, [left_c]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [left_c]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gt] expr, [left_c]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [left_c]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [left_c]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [and] expr, [left_c]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [or] expr, [left_c]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State62:
	states.push(&&Goto62);
	switch(current_terminal->token()){
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto62:
	switch(top_non_terminal){
		case SYMBOL_block: goto State63;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift63:
/*
{closedStmt -> [if] expr block ~, [right_c]}
{closedStmt -> [if] expr block ~, [out]}
{closedStmt -> [if] expr block ~, [in]}
{closedStmt -> [if] expr block ~, [return]}
{closedStmt -> [if] expr block ~, [id]}
{closedStmt -> [if] expr block ~, [left_p]}
{closedStmt -> [if] expr block ~, [left_c]}
{closedStmt -> [if] expr block ~, [not]}
{closedStmt -> [if] expr block ~, [int]}
{closedStmt -> [if] expr block ~, [if]}
{closedStmt -> [if] expr block ~, [while]}
{closedStmt -> [if] expr block ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State63:
	states.push(&&Goto63);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce39;
		case TOKEN_out: goto Reduce39;
		case TOKEN_in: goto Reduce39;
		case TOKEN_return: goto Reduce39;
		case TOKEN_id: goto Reduce39;
		case TOKEN_left_p: goto Reduce39;
		case TOKEN_left_c: goto Reduce39;
		case TOKEN_not: goto Reduce39;
		case TOKEN_int: goto Reduce39;
		case TOKEN_if: goto Reduce39;
		case TOKEN_while: goto Reduce39;
		case TOKEN_for: goto Reduce39;
		default: goto ERROR;
	}

Goto63:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift64:
/*
{dictblock -> [left_c] ~ pairs [right_c], [multiply]}
{dictblock -> [left_c] ~ pairs [right_c], [division]}
{dictblock -> [left_c] ~ pairs [right_c], [modulo]}
{dictblock -> [left_c] ~ pairs [right_c], [minus]}
{dictblock -> [left_c] ~ pairs [right_c], [plus]}
{dictblock -> [left_c] ~ pairs [right_c], [leeq]}
{dictblock -> [left_c] ~ pairs [right_c], [le]}
{dictblock -> [left_c] ~ pairs [right_c], [gteq]}
{dictblock -> [left_c] ~ pairs [right_c], [gt]}
{dictblock -> [left_c] ~ pairs [right_c], [eq]}
{dictblock -> [left_c] ~ pairs [right_c], [neq]}
{dictblock -> [left_c] ~ pairs [right_c], [bitand]}
{dictblock -> [left_c] ~ pairs [right_c], [bitor]}
{dictblock -> [left_c] ~ pairs [right_c], [and]}
{dictblock -> [left_c] ~ pairs [right_c], [or]}
{dictblock -> [left_c] ~ pairs [right_c], [dot]}
{dictblock -> [left_c] ~ pairs [right_c], [semicolon]}
{dictblock -> [left_c] ~ pairs [right_c], [right_b]}
{dictblock -> [left_c] ~ pairs [right_c], [left_c]}
{dictblock -> [left_c] ~ pairs [right_c], [colon]}
{dictblock -> [left_c] ~ pairs [right_c], [right_p]}
{dictblock -> [left_c] ~ pairs [right_c], [comma]}
{dictblock -> [left_c] ~ pairs [right_c], [right_c]}
{dictblock -> [left_c] ~ [right_c], [multiply]}
{dictblock -> [left_c] ~ [right_c], [division]}
{dictblock -> [left_c] ~ [right_c], [modulo]}
{dictblock -> [left_c] ~ [right_c], [minus]}
{dictblock -> [left_c] ~ [right_c], [plus]}
{dictblock -> [left_c] ~ [right_c], [leeq]}
{dictblock -> [left_c] ~ [right_c], [le]}
{dictblock -> [left_c] ~ [right_c], [gteq]}
{dictblock -> [left_c] ~ [right_c], [gt]}
{dictblock -> [left_c] ~ [right_c], [eq]}
{dictblock -> [left_c] ~ [right_c], [neq]}
{dictblock -> [left_c] ~ [right_c], [bitand]}
{dictblock -> [left_c] ~ [right_c], [bitor]}
{dictblock -> [left_c] ~ [right_c], [and]}
{dictblock -> [left_c] ~ [right_c], [or]}
{dictblock -> [left_c] ~ [right_c], [dot]}
{dictblock -> [left_c] ~ [right_c], [semicolon]}
{dictblock -> [left_c] ~ [right_c], [right_b]}
{dictblock -> [left_c] ~ [right_c], [left_c]}
{dictblock -> [left_c] ~ [right_c], [colon]}
{dictblock -> [left_c] ~ [right_c], [right_p]}
{dictblock -> [left_c] ~ [right_c], [comma]}
{dictblock -> [left_c] ~ [right_c], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State64:
	states.push(&&Goto64);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Shift70;
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto64:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State71;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_pairs: goto State66;
		case SYMBOL_pair: goto State65;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift65:
/*
{pairs -> pair ~, [right_c]}
{pairs -> pair ~, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State65:
	states.push(&&Goto65);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce59;
		case TOKEN_comma: goto Reduce59;
		default: goto ERROR;
	}

Goto65:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift66:
/*
{dictblock -> [left_c] pairs ~ [right_c], [multiply]}
{dictblock -> [left_c] pairs ~ [right_c], [division]}
{dictblock -> [left_c] pairs ~ [right_c], [modulo]}
{dictblock -> [left_c] pairs ~ [right_c], [minus]}
{dictblock -> [left_c] pairs ~ [right_c], [plus]}
{dictblock -> [left_c] pairs ~ [right_c], [leeq]}
{dictblock -> [left_c] pairs ~ [right_c], [le]}
{dictblock -> [left_c] pairs ~ [right_c], [gteq]}
{dictblock -> [left_c] pairs ~ [right_c], [gt]}
{dictblock -> [left_c] pairs ~ [right_c], [eq]}
{dictblock -> [left_c] pairs ~ [right_c], [neq]}
{dictblock -> [left_c] pairs ~ [right_c], [bitand]}
{dictblock -> [left_c] pairs ~ [right_c], [bitor]}
{dictblock -> [left_c] pairs ~ [right_c], [and]}
{dictblock -> [left_c] pairs ~ [right_c], [or]}
{dictblock -> [left_c] pairs ~ [right_c], [dot]}
{dictblock -> [left_c] pairs ~ [right_c], [semicolon]}
{dictblock -> [left_c] pairs ~ [right_c], [right_b]}
{dictblock -> [left_c] pairs ~ [right_c], [left_c]}
{dictblock -> [left_c] pairs ~ [right_c], [colon]}
{dictblock -> [left_c] pairs ~ [right_c], [right_p]}
{dictblock -> [left_c] pairs ~ [right_c], [comma]}
{dictblock -> [left_c] pairs ~ [right_c], [right_c]}
{pairs -> pairs ~ [comma] pairs, [right_c]}
{pairs -> pairs ~ [comma] pairs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State66:
	states.push(&&Goto66);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Shift67;
		case TOKEN_comma: goto Shift68;
		default: goto ERROR;
	}

Goto66:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift67:
/*
{dictblock -> [left_c] pairs [right_c] ~, [multiply]}
{dictblock -> [left_c] pairs [right_c] ~, [division]}
{dictblock -> [left_c] pairs [right_c] ~, [modulo]}
{dictblock -> [left_c] pairs [right_c] ~, [minus]}
{dictblock -> [left_c] pairs [right_c] ~, [plus]}
{dictblock -> [left_c] pairs [right_c] ~, [leeq]}
{dictblock -> [left_c] pairs [right_c] ~, [le]}
{dictblock -> [left_c] pairs [right_c] ~, [gteq]}
{dictblock -> [left_c] pairs [right_c] ~, [gt]}
{dictblock -> [left_c] pairs [right_c] ~, [eq]}
{dictblock -> [left_c] pairs [right_c] ~, [neq]}
{dictblock -> [left_c] pairs [right_c] ~, [bitand]}
{dictblock -> [left_c] pairs [right_c] ~, [bitor]}
{dictblock -> [left_c] pairs [right_c] ~, [and]}
{dictblock -> [left_c] pairs [right_c] ~, [or]}
{dictblock -> [left_c] pairs [right_c] ~, [dot]}
{dictblock -> [left_c] pairs [right_c] ~, [semicolon]}
{dictblock -> [left_c] pairs [right_c] ~, [right_b]}
{dictblock -> [left_c] pairs [right_c] ~, [left_c]}
{dictblock -> [left_c] pairs [right_c] ~, [colon]}
{dictblock -> [left_c] pairs [right_c] ~, [right_p]}
{dictblock -> [left_c] pairs [right_c] ~, [comma]}
{dictblock -> [left_c] pairs [right_c] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State67:
	states.push(&&Goto67);
	switch(current_terminal->token()){
		case TOKEN_multiply: goto Reduce56;
		case TOKEN_division: goto Reduce56;
		case TOKEN_modulo: goto Reduce56;
		case TOKEN_minus: goto Reduce56;
		case TOKEN_plus: goto Reduce56;
		case TOKEN_leeq: goto Reduce56;
		case TOKEN_le: goto Reduce56;
		case TOKEN_gteq: goto Reduce56;
		case TOKEN_gt: goto Reduce56;
		case TOKEN_eq: goto Reduce56;
		case TOKEN_neq: goto Reduce56;
		case TOKEN_bitand: goto Reduce56;
		case TOKEN_bitor: goto Reduce56;
		case TOKEN_and: goto Reduce56;
		case TOKEN_or: goto Reduce56;
		case TOKEN_dot: goto Reduce56;
		case TOKEN_semicolon: goto Reduce56;
		case TOKEN_right_b: goto Reduce56;
		case TOKEN_left_c: goto Reduce56;
		case TOKEN_colon: goto Reduce56;
		case TOKEN_right_p: goto Reduce56;
		case TOKEN_comma: goto Reduce56;
		case TOKEN_right_c: goto Reduce56;
		default: goto ERROR;
	}

Goto67:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift68:
/*
{pairs -> pairs [comma] ~ pairs, [right_c]}
{pairs -> pairs [comma] ~ pairs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State68:
	states.push(&&Goto68);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto68:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State71;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_pairs: goto State69;
		case SYMBOL_pair: goto State65;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift69:
/*
{pairs -> pairs [comma] pairs ~, [right_c]}
{pairs -> pairs [comma] pairs ~, [comma]}
{pairs -> pairs ~ [comma] pairs, [comma]}
{pairs -> pairs ~ [comma] pairs, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State69:
	states.push(&&Goto69);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce58;
		case TOKEN_comma: goto Reduce58;
		default: goto ERROR;
	}

Goto69:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift70:
/*
{dictblock -> [left_c] [right_c] ~, [multiply]}
{dictblock -> [left_c] [right_c] ~, [division]}
{dictblock -> [left_c] [right_c] ~, [modulo]}
{dictblock -> [left_c] [right_c] ~, [minus]}
{dictblock -> [left_c] [right_c] ~, [plus]}
{dictblock -> [left_c] [right_c] ~, [leeq]}
{dictblock -> [left_c] [right_c] ~, [le]}
{dictblock -> [left_c] [right_c] ~, [gteq]}
{dictblock -> [left_c] [right_c] ~, [gt]}
{dictblock -> [left_c] [right_c] ~, [eq]}
{dictblock -> [left_c] [right_c] ~, [neq]}
{dictblock -> [left_c] [right_c] ~, [bitand]}
{dictblock -> [left_c] [right_c] ~, [bitor]}
{dictblock -> [left_c] [right_c] ~, [and]}
{dictblock -> [left_c] [right_c] ~, [or]}
{dictblock -> [left_c] [right_c] ~, [dot]}
{dictblock -> [left_c] [right_c] ~, [semicolon]}
{dictblock -> [left_c] [right_c] ~, [right_b]}
{dictblock -> [left_c] [right_c] ~, [left_c]}
{dictblock -> [left_c] [right_c] ~, [colon]}
{dictblock -> [left_c] [right_c] ~, [right_p]}
{dictblock -> [left_c] [right_c] ~, [comma]}
{dictblock -> [left_c] [right_c] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State70:
	states.push(&&Goto70);
	switch(current_terminal->token()){
		case TOKEN_multiply: goto Reduce57;
		case TOKEN_division: goto Reduce57;
		case TOKEN_modulo: goto Reduce57;
		case TOKEN_minus: goto Reduce57;
		case TOKEN_plus: goto Reduce57;
		case TOKEN_leeq: goto Reduce57;
		case TOKEN_le: goto Reduce57;
		case TOKEN_gteq: goto Reduce57;
		case TOKEN_gt: goto Reduce57;
		case TOKEN_eq: goto Reduce57;
		case TOKEN_neq: goto Reduce57;
		case TOKEN_bitand: goto Reduce57;
		case TOKEN_bitor: goto Reduce57;
		case TOKEN_and: goto Reduce57;
		case TOKEN_or: goto Reduce57;
		case TOKEN_dot: goto Reduce57;
		case TOKEN_semicolon: goto Reduce57;
		case TOKEN_right_b: goto Reduce57;
		case TOKEN_left_c: goto Reduce57;
		case TOKEN_colon: goto Reduce57;
		case TOKEN_right_p: goto Reduce57;
		case TOKEN_comma: goto Reduce57;
		case TOKEN_right_c: goto Reduce57;
		default: goto ERROR;
	}

Goto70:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift71:
/*
{pair -> expr ~ [colon] expr, [right_c]}
{pair -> expr ~ [colon] expr, [comma]}
{expr -> expr ~ [multiply] expr, [colon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [division] expr, [colon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [colon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [colon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [le] expr, [colon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [colon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gt] expr, [colon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [colon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [colon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [and] expr, [colon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [or] expr, [colon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State71:
	states.push(&&Goto71);
	switch(current_terminal->token()){
		case TOKEN_colon: goto Shift72;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto71:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift72:
/*
{pair -> expr [colon] ~ expr, [right_c]}
{pair -> expr [colon] ~ expr, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State72:
	states.push(&&Goto72);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto72:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State73;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift73:
/*
{pair -> expr [colon] expr ~, [right_c]}
{pair -> expr [colon] expr ~, [comma]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [right_c]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [right_c]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [right_c]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [right_c]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [right_c]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [right_c]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [right_c]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [right_c]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [right_c]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [right_c]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [right_c]}
{expr -> expr ~ [or] expr, [comma]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [right_c]}
{varexpr -> expr ~ [dot] [id], [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State73:
	states.push(&&Goto73);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce60;
		case TOKEN_comma: goto Reduce60;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto73:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift74:
/*
{expr -> varexpr ~ argblock, [semicolon]}
{expr -> varexpr ~ argblock, [dot]}
{expr -> varexpr ~ argblock, [or]}
{expr -> varexpr ~ argblock, [and]}
{expr -> varexpr ~ argblock, [bitor]}
{expr -> varexpr ~ argblock, [bitand]}
{expr -> varexpr ~ argblock, [neq]}
{expr -> varexpr ~ argblock, [eq]}
{expr -> varexpr ~ argblock, [gt]}
{expr -> varexpr ~ argblock, [gteq]}
{expr -> varexpr ~ argblock, [le]}
{expr -> varexpr ~ argblock, [leeq]}
{expr -> varexpr ~ argblock, [plus]}
{expr -> varexpr ~ argblock, [minus]}
{expr -> varexpr ~ argblock, [modulo]}
{expr -> varexpr ~ argblock, [division]}
{expr -> varexpr ~ argblock, [multiply]}
{expr -> varexpr ~ argblock, [right_b]}
{expr -> varexpr ~ argblock, [left_c]}
{expr -> varexpr ~ argblock, [colon]}
{expr -> varexpr ~ argblock, [right_p]}
{expr -> varexpr ~ argblock, [comma]}
{expr -> varexpr ~ argblock, [right_c]}
{expr -> varexpr ~, [semicolon]}
{expr -> varexpr ~, [dot]}
{expr -> varexpr ~, [or]}
{expr -> varexpr ~, [and]}
{expr -> varexpr ~, [bitor]}
{expr -> varexpr ~, [bitand]}
{expr -> varexpr ~, [neq]}
{expr -> varexpr ~, [eq]}
{expr -> varexpr ~, [gt]}
{expr -> varexpr ~, [gteq]}
{expr -> varexpr ~, [le]}
{expr -> varexpr ~, [leeq]}
{expr -> varexpr ~, [plus]}
{expr -> varexpr ~, [minus]}
{expr -> varexpr ~, [modulo]}
{expr -> varexpr ~, [division]}
{expr -> varexpr ~, [multiply]}
{expr -> varexpr ~, [right_b]}
{expr -> varexpr ~, [left_c]}
{expr -> varexpr ~, [colon]}
{expr -> varexpr ~, [right_p]}
{expr -> varexpr ~, [comma]}
{expr -> varexpr ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State74:
	states.push(&&Goto74);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce80;
		case TOKEN_dot: goto Reduce80;
		case TOKEN_or: goto Reduce80;
		case TOKEN_and: goto Reduce80;
		case TOKEN_bitor: goto Reduce80;
		case TOKEN_bitand: goto Reduce80;
		case TOKEN_neq: goto Reduce80;
		case TOKEN_eq: goto Reduce80;
		case TOKEN_gt: goto Reduce80;
		case TOKEN_gteq: goto Reduce80;
		case TOKEN_le: goto Reduce80;
		case TOKEN_leeq: goto Reduce80;
		case TOKEN_plus: goto Reduce80;
		case TOKEN_minus: goto Reduce80;
		case TOKEN_modulo: goto Reduce80;
		case TOKEN_division: goto Reduce80;
		case TOKEN_multiply: goto Reduce80;
		case TOKEN_right_b: goto Reduce80;
		case TOKEN_left_c: goto Reduce80;
		case TOKEN_colon: goto Reduce80;
		case TOKEN_right_p: goto Reduce80;
		case TOKEN_comma: goto Reduce80;
		case TOKEN_right_c: goto Reduce80;
		case TOKEN_left_p: goto Shift76;
		default: goto ERROR;
	}

Goto74:
	switch(top_non_terminal){
		case SYMBOL_argblock: goto State75;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift75:
/*
{expr -> varexpr argblock ~, [semicolon]}
{expr -> varexpr argblock ~, [dot]}
{expr -> varexpr argblock ~, [or]}
{expr -> varexpr argblock ~, [and]}
{expr -> varexpr argblock ~, [bitor]}
{expr -> varexpr argblock ~, [bitand]}
{expr -> varexpr argblock ~, [neq]}
{expr -> varexpr argblock ~, [eq]}
{expr -> varexpr argblock ~, [gt]}
{expr -> varexpr argblock ~, [gteq]}
{expr -> varexpr argblock ~, [le]}
{expr -> varexpr argblock ~, [leeq]}
{expr -> varexpr argblock ~, [plus]}
{expr -> varexpr argblock ~, [minus]}
{expr -> varexpr argblock ~, [modulo]}
{expr -> varexpr argblock ~, [division]}
{expr -> varexpr argblock ~, [multiply]}
{expr -> varexpr argblock ~, [right_b]}
{expr -> varexpr argblock ~, [left_c]}
{expr -> varexpr argblock ~, [colon]}
{expr -> varexpr argblock ~, [right_p]}
{expr -> varexpr argblock ~, [comma]}
{expr -> varexpr argblock ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State75:
	states.push(&&Goto75);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce79;
		case TOKEN_dot: goto Reduce79;
		case TOKEN_or: goto Reduce79;
		case TOKEN_and: goto Reduce79;
		case TOKEN_bitor: goto Reduce79;
		case TOKEN_bitand: goto Reduce79;
		case TOKEN_neq: goto Reduce79;
		case TOKEN_eq: goto Reduce79;
		case TOKEN_gt: goto Reduce79;
		case TOKEN_gteq: goto Reduce79;
		case TOKEN_le: goto Reduce79;
		case TOKEN_leeq: goto Reduce79;
		case TOKEN_plus: goto Reduce79;
		case TOKEN_minus: goto Reduce79;
		case TOKEN_modulo: goto Reduce79;
		case TOKEN_division: goto Reduce79;
		case TOKEN_multiply: goto Reduce79;
		case TOKEN_right_b: goto Reduce79;
		case TOKEN_left_c: goto Reduce79;
		case TOKEN_colon: goto Reduce79;
		case TOKEN_right_p: goto Reduce79;
		case TOKEN_comma: goto Reduce79;
		case TOKEN_right_c: goto Reduce79;
		default: goto ERROR;
	}

Goto75:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift76:
/*
{argblock -> [left_p] ~ args [right_p], [semicolon]}
{argblock -> [left_p] ~ args [right_p], [dot]}
{argblock -> [left_p] ~ args [right_p], [or]}
{argblock -> [left_p] ~ args [right_p], [and]}
{argblock -> [left_p] ~ args [right_p], [bitor]}
{argblock -> [left_p] ~ args [right_p], [bitand]}
{argblock -> [left_p] ~ args [right_p], [neq]}
{argblock -> [left_p] ~ args [right_p], [eq]}
{argblock -> [left_p] ~ args [right_p], [gt]}
{argblock -> [left_p] ~ args [right_p], [gteq]}
{argblock -> [left_p] ~ args [right_p], [le]}
{argblock -> [left_p] ~ args [right_p], [leeq]}
{argblock -> [left_p] ~ args [right_p], [plus]}
{argblock -> [left_p] ~ args [right_p], [minus]}
{argblock -> [left_p] ~ args [right_p], [modulo]}
{argblock -> [left_p] ~ args [right_p], [division]}
{argblock -> [left_p] ~ args [right_p], [multiply]}
{argblock -> [left_p] ~ args [right_p], [right_b]}
{argblock -> [left_p] ~ args [right_p], [left_c]}
{argblock -> [left_p] ~ args [right_p], [colon]}
{argblock -> [left_p] ~ args [right_p], [right_p]}
{argblock -> [left_p] ~ args [right_p], [comma]}
{argblock -> [left_p] ~ args [right_p], [right_c]}
{argblock -> [left_p] ~ [right_p], [semicolon]}
{argblock -> [left_p] ~ [right_p], [dot]}
{argblock -> [left_p] ~ [right_p], [or]}
{argblock -> [left_p] ~ [right_p], [and]}
{argblock -> [left_p] ~ [right_p], [bitor]}
{argblock -> [left_p] ~ [right_p], [bitand]}
{argblock -> [left_p] ~ [right_p], [neq]}
{argblock -> [left_p] ~ [right_p], [eq]}
{argblock -> [left_p] ~ [right_p], [gt]}
{argblock -> [left_p] ~ [right_p], [gteq]}
{argblock -> [left_p] ~ [right_p], [le]}
{argblock -> [left_p] ~ [right_p], [leeq]}
{argblock -> [left_p] ~ [right_p], [plus]}
{argblock -> [left_p] ~ [right_p], [minus]}
{argblock -> [left_p] ~ [right_p], [modulo]}
{argblock -> [left_p] ~ [right_p], [division]}
{argblock -> [left_p] ~ [right_p], [multiply]}
{argblock -> [left_p] ~ [right_p], [right_b]}
{argblock -> [left_p] ~ [right_p], [left_c]}
{argblock -> [left_p] ~ [right_p], [colon]}
{argblock -> [left_p] ~ [right_p], [right_p]}
{argblock -> [left_p] ~ [right_p], [comma]}
{argblock -> [left_p] ~ [right_p], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State76:
	states.push(&&Goto76);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift82;
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto76:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State83;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_args: goto State80;
		case SYMBOL_arg: goto State77;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift77:
/*
{args -> arg ~ [comma] args, [right_p]}
{args -> arg ~, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State77:
	states.push(&&Goto77);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Shift78;
		case TOKEN_right_p: goto Reduce46;
		default: goto ERROR;
	}

Goto77:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift78:
/*
{args -> arg [comma] ~ args, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State78:
	states.push(&&Goto78);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto78:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State83;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_args: goto State79;
		case SYMBOL_arg: goto State77;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift79:
/*
{args -> arg [comma] args ~, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State79:
	states.push(&&Goto79);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce45;
		default: goto ERROR;
	}

Goto79:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift80:
/*
{argblock -> [left_p] args ~ [right_p], [semicolon]}
{argblock -> [left_p] args ~ [right_p], [dot]}
{argblock -> [left_p] args ~ [right_p], [or]}
{argblock -> [left_p] args ~ [right_p], [and]}
{argblock -> [left_p] args ~ [right_p], [bitor]}
{argblock -> [left_p] args ~ [right_p], [bitand]}
{argblock -> [left_p] args ~ [right_p], [neq]}
{argblock -> [left_p] args ~ [right_p], [eq]}
{argblock -> [left_p] args ~ [right_p], [gt]}
{argblock -> [left_p] args ~ [right_p], [gteq]}
{argblock -> [left_p] args ~ [right_p], [le]}
{argblock -> [left_p] args ~ [right_p], [leeq]}
{argblock -> [left_p] args ~ [right_p], [plus]}
{argblock -> [left_p] args ~ [right_p], [minus]}
{argblock -> [left_p] args ~ [right_p], [modulo]}
{argblock -> [left_p] args ~ [right_p], [division]}
{argblock -> [left_p] args ~ [right_p], [multiply]}
{argblock -> [left_p] args ~ [right_p], [right_b]}
{argblock -> [left_p] args ~ [right_p], [left_c]}
{argblock -> [left_p] args ~ [right_p], [colon]}
{argblock -> [left_p] args ~ [right_p], [right_p]}
{argblock -> [left_p] args ~ [right_p], [comma]}
{argblock -> [left_p] args ~ [right_p], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State80:
	states.push(&&Goto80);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift81;
		default: goto ERROR;
	}

Goto80:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift81:
/*
{argblock -> [left_p] args [right_p] ~, [semicolon]}
{argblock -> [left_p] args [right_p] ~, [dot]}
{argblock -> [left_p] args [right_p] ~, [or]}
{argblock -> [left_p] args [right_p] ~, [and]}
{argblock -> [left_p] args [right_p] ~, [bitor]}
{argblock -> [left_p] args [right_p] ~, [bitand]}
{argblock -> [left_p] args [right_p] ~, [neq]}
{argblock -> [left_p] args [right_p] ~, [eq]}
{argblock -> [left_p] args [right_p] ~, [gt]}
{argblock -> [left_p] args [right_p] ~, [gteq]}
{argblock -> [left_p] args [right_p] ~, [le]}
{argblock -> [left_p] args [right_p] ~, [leeq]}
{argblock -> [left_p] args [right_p] ~, [plus]}
{argblock -> [left_p] args [right_p] ~, [minus]}
{argblock -> [left_p] args [right_p] ~, [modulo]}
{argblock -> [left_p] args [right_p] ~, [division]}
{argblock -> [left_p] args [right_p] ~, [multiply]}
{argblock -> [left_p] args [right_p] ~, [right_b]}
{argblock -> [left_p] args [right_p] ~, [left_c]}
{argblock -> [left_p] args [right_p] ~, [colon]}
{argblock -> [left_p] args [right_p] ~, [right_p]}
{argblock -> [left_p] args [right_p] ~, [comma]}
{argblock -> [left_p] args [right_p] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State81:
	states.push(&&Goto81);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce43;
		case TOKEN_dot: goto Reduce43;
		case TOKEN_or: goto Reduce43;
		case TOKEN_and: goto Reduce43;
		case TOKEN_bitor: goto Reduce43;
		case TOKEN_bitand: goto Reduce43;
		case TOKEN_neq: goto Reduce43;
		case TOKEN_eq: goto Reduce43;
		case TOKEN_gt: goto Reduce43;
		case TOKEN_gteq: goto Reduce43;
		case TOKEN_le: goto Reduce43;
		case TOKEN_leeq: goto Reduce43;
		case TOKEN_plus: goto Reduce43;
		case TOKEN_minus: goto Reduce43;
		case TOKEN_modulo: goto Reduce43;
		case TOKEN_division: goto Reduce43;
		case TOKEN_multiply: goto Reduce43;
		case TOKEN_right_b: goto Reduce43;
		case TOKEN_left_c: goto Reduce43;
		case TOKEN_colon: goto Reduce43;
		case TOKEN_right_p: goto Reduce43;
		case TOKEN_comma: goto Reduce43;
		case TOKEN_right_c: goto Reduce43;
		default: goto ERROR;
	}

Goto81:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift82:
/*
{argblock -> [left_p] [right_p] ~, [semicolon]}
{argblock -> [left_p] [right_p] ~, [dot]}
{argblock -> [left_p] [right_p] ~, [or]}
{argblock -> [left_p] [right_p] ~, [and]}
{argblock -> [left_p] [right_p] ~, [bitor]}
{argblock -> [left_p] [right_p] ~, [bitand]}
{argblock -> [left_p] [right_p] ~, [neq]}
{argblock -> [left_p] [right_p] ~, [eq]}
{argblock -> [left_p] [right_p] ~, [gt]}
{argblock -> [left_p] [right_p] ~, [gteq]}
{argblock -> [left_p] [right_p] ~, [le]}
{argblock -> [left_p] [right_p] ~, [leeq]}
{argblock -> [left_p] [right_p] ~, [plus]}
{argblock -> [left_p] [right_p] ~, [minus]}
{argblock -> [left_p] [right_p] ~, [modulo]}
{argblock -> [left_p] [right_p] ~, [division]}
{argblock -> [left_p] [right_p] ~, [multiply]}
{argblock -> [left_p] [right_p] ~, [right_b]}
{argblock -> [left_p] [right_p] ~, [left_c]}
{argblock -> [left_p] [right_p] ~, [colon]}
{argblock -> [left_p] [right_p] ~, [right_p]}
{argblock -> [left_p] [right_p] ~, [comma]}
{argblock -> [left_p] [right_p] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State82:
	states.push(&&Goto82);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce44;
		case TOKEN_dot: goto Reduce44;
		case TOKEN_or: goto Reduce44;
		case TOKEN_and: goto Reduce44;
		case TOKEN_bitor: goto Reduce44;
		case TOKEN_bitand: goto Reduce44;
		case TOKEN_neq: goto Reduce44;
		case TOKEN_eq: goto Reduce44;
		case TOKEN_gt: goto Reduce44;
		case TOKEN_gteq: goto Reduce44;
		case TOKEN_le: goto Reduce44;
		case TOKEN_leeq: goto Reduce44;
		case TOKEN_plus: goto Reduce44;
		case TOKEN_minus: goto Reduce44;
		case TOKEN_modulo: goto Reduce44;
		case TOKEN_division: goto Reduce44;
		case TOKEN_multiply: goto Reduce44;
		case TOKEN_right_b: goto Reduce44;
		case TOKEN_left_c: goto Reduce44;
		case TOKEN_colon: goto Reduce44;
		case TOKEN_right_p: goto Reduce44;
		case TOKEN_comma: goto Reduce44;
		case TOKEN_right_c: goto Reduce44;
		default: goto ERROR;
	}

Goto82:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift83:
/*
{arg -> expr ~, [right_p]}
{arg -> expr ~, [comma]}
{expr -> expr ~ [multiply] expr, [right_p]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [comma]}
{expr -> expr ~ [division] expr, [right_p]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [comma]}
{expr -> expr ~ [modulo] expr, [right_p]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [leeq] expr, [right_p]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [comma]}
{expr -> expr ~ [le] expr, [right_p]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [comma]}
{expr -> expr ~ [gteq] expr, [right_p]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [comma]}
{expr -> expr ~ [gt] expr, [right_p]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [bitand] expr, [right_p]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [comma]}
{expr -> expr ~ [bitor] expr, [right_p]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [comma]}
{expr -> expr ~ [and] expr, [right_p]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [comma]}
{expr -> expr ~ [or] expr, [right_p]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [comma]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State83:
	states.push(&&Goto83);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce47;
		case TOKEN_comma: goto Reduce47;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto83:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift84:
/*
{tuprefblock -> [left_p] ~ tuprefs [right_p], [assignment]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State84:
	states.push(&&Goto84);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift89;
		default: goto ERROR;
	}

Goto84:
	switch(top_non_terminal){
		case SYMBOL_tuprefs: goto State85;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift85:
/*
{tuprefblock -> [left_p] tuprefs ~ [right_p], [assignment]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [right_p]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State85:
	states.push(&&Goto85);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift88;
		case TOKEN_comma: goto Shift86;
		default: goto ERROR;
	}

Goto85:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift86:
/*
{tuprefs -> tuprefs [comma] ~ tuprefs, [right_p]}
{tuprefs -> tuprefs [comma] ~ tuprefs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State86:
	states.push(&&Goto86);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift89;
		default: goto ERROR;
	}

Goto86:
	switch(top_non_terminal){
		case SYMBOL_tuprefs: goto State87;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift87:
/*
{tuprefs -> tuprefs [comma] tuprefs ~, [right_p]}
{tuprefs -> tuprefs [comma] tuprefs ~, [comma]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [comma]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State87:
	states.push(&&Goto87);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce54;
		case TOKEN_comma: goto Reduce54;
		default: goto ERROR;
	}

Goto87:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift88:
/*
{tuprefblock -> [left_p] tuprefs [right_p] ~, [assignment]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State88:
	states.push(&&Goto88);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Reduce53;
		default: goto ERROR;
	}

Goto88:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift89:
/*
{tuprefs -> [id] ~, [right_p]}
{tuprefs -> [id] ~, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State89:
	states.push(&&Goto89);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce55;
		case TOKEN_comma: goto Reduce55;
		default: goto ERROR;
	}

Goto89:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift90:
/*
{stmt -> expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State90:
	states.push(&&Goto90);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce17;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto90:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift91:
/*
{stmt -> tuprefblock ~ [assignment] expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State91:
	states.push(&&Goto91);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Shift92;
		default: goto ERROR;
	}

Goto91:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift92:
/*
{stmt -> tuprefblock [assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State92:
	states.push(&&Goto92);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto92:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State93;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift93:
/*
{stmt -> tuprefblock [assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State93:
	states.push(&&Goto93);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce16;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto93:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift94:
/*
{stmt -> varAssign ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State94:
	states.push(&&Goto94);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce15;
		default: goto ERROR;
	}

Goto94:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift95:
/*
{stmt -> [return] ~ returnStmt, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State95:
	states.push(&&Goto95);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto95:
	switch(top_non_terminal){
		case SYMBOL_returnStmt: goto State97;
		case SYMBOL_expr: goto State96;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift96:
/*
{returnStmt -> expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State96:
	states.push(&&Goto96);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce34;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto96:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift97:
/*
{stmt -> [return] returnStmt ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State97:
	states.push(&&Goto97);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce14;
		default: goto ERROR;
	}

Goto97:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift98:
/*
{stmt -> [in] ~ inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State98:
	states.push(&&Goto98);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift102;
		default: goto ERROR;
	}

Goto98:
	switch(top_non_terminal){
		case SYMBOL_inDecl: goto State99;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift99:
/*
{stmt -> [in] inDecl ~, [semicolon]}
{inDecl -> inDecl ~ [comma] inDecl, [comma]}
{inDecl -> inDecl ~ [comma] inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State99:
	states.push(&&Goto99);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce13;
		case TOKEN_comma: goto Shift100;
		default: goto ERROR;
	}

Goto99:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift100:
/*
{inDecl -> inDecl [comma] ~ inDecl, [comma]}
{inDecl -> inDecl [comma] ~ inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State100:
	states.push(&&Goto100);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift102;
		default: goto ERROR;
	}

Goto100:
	switch(top_non_terminal){
		case SYMBOL_inDecl: goto State101;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift101:
/*
{inDecl -> inDecl [comma] inDecl ~, [comma]}
{inDecl -> inDecl [comma] inDecl ~, [semicolon]}
{inDecl -> inDecl ~ [comma] inDecl, [comma]}
{inDecl -> inDecl ~ [comma] inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State101:
	states.push(&&Goto101);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Reduce24;
		case TOKEN_semicolon: goto Reduce24;
		default: goto ERROR;
	}

Goto101:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift102:
/*
{inDecl -> [id] ~, [comma]}
{inDecl -> [id] ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State102:
	states.push(&&Goto102);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Reduce25;
		case TOKEN_semicolon: goto Reduce25;
		default: goto ERROR;
	}

Goto102:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift103:
/*
{stmt -> [out] ~ outDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State103:
	states.push(&&Goto103);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift105;
		default: goto ERROR;
	}

Goto103:
	switch(top_non_terminal){
		case SYMBOL_outDecl: goto State104;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift104:
/*
{stmt -> [out] outDecl ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State104:
	states.push(&&Goto104);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce12;
		default: goto ERROR;
	}

Goto104:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift105:
/*
{outDecl -> [id] ~ [assignment] expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State105:
	states.push(&&Goto105);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Shift106;
		default: goto ERROR;
	}

Goto105:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift106:
/*
{outDecl -> [id] [assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State106:
	states.push(&&Goto106);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto106:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State107;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift107:
/*
{outDecl -> [id] [assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State107:
	states.push(&&Goto107);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce23;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto107:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift108:
/*
{stmts -> closedStmt ~ stmts, [right_c]}
{stmts -> closedStmt ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State108:
	states.push(&&Goto108);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce11;
		case TOKEN_if: goto Shift61;
		case TOKEN_while: goto Shift58;
		case TOKEN_for: goto Shift53;
		case TOKEN_out: goto Shift103;
		case TOKEN_in: goto Shift98;
		case TOKEN_return: goto Shift95;
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift115;
		case TOKEN_left_c: goto Shift64;
		case TOKEN_left_p: goto Shift84;
		default: goto ERROR;
	}

Goto108:
	switch(top_non_terminal){
		case SYMBOL_stmts: goto State109;
		case SYMBOL_stmt: goto State110;
		case SYMBOL_closedStmt: goto State108;
		case SYMBOL_varAssign: goto State94;
		case SYMBOL_tuprefblock: goto State91;
		case SYMBOL_expr: goto State90;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift109:
/*
{stmts -> closedStmt stmts ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State109:
	states.push(&&Goto109);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce9;
		default: goto ERROR;
	}

Goto109:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift110:
/*
{stmts -> stmt ~ [semicolon] stmts, [right_c]}
{stmts -> stmt ~ [semicolon], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State110:
	states.push(&&Goto110);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Shift111;
		default: goto ERROR;
	}

Goto110:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift111:
/*
{stmts -> stmt [semicolon] ~ stmts, [right_c]}
{stmts -> stmt [semicolon] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State111:
	states.push(&&Goto111);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce10;
		case TOKEN_if: goto Shift61;
		case TOKEN_while: goto Shift58;
		case TOKEN_for: goto Shift53;
		case TOKEN_out: goto Shift103;
		case TOKEN_in: goto Shift98;
		case TOKEN_return: goto Shift95;
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift115;
		case TOKEN_left_c: goto Shift64;
		case TOKEN_left_p: goto Shift84;
		default: goto ERROR;
	}

Goto111:
	switch(top_non_terminal){
		case SYMBOL_stmts: goto State112;
		case SYMBOL_stmt: goto State110;
		case SYMBOL_closedStmt: goto State108;
		case SYMBOL_varAssign: goto State94;
		case SYMBOL_tuprefblock: goto State91;
		case SYMBOL_expr: goto State90;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift112:
/*
{stmts -> stmt [semicolon] stmts ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State112:
	states.push(&&Goto112);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce8;
		default: goto ERROR;
	}

Goto112:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift113:
/*
{block -> [left_c] stmts ~ [right_c], [def]}
{block -> [left_c] stmts ~ [right_c], [EOF]}
{block -> [left_c] stmts ~ [right_c], [right_c]}
{block -> [left_c] stmts ~ [right_c], [out]}
{block -> [left_c] stmts ~ [right_c], [in]}
{block -> [left_c] stmts ~ [right_c], [return]}
{block -> [left_c] stmts ~ [right_c], [id]}
{block -> [left_c] stmts ~ [right_c], [left_p]}
{block -> [left_c] stmts ~ [right_c], [left_c]}
{block -> [left_c] stmts ~ [right_c], [not]}
{block -> [left_c] stmts ~ [right_c], [int]}
{block -> [left_c] stmts ~ [right_c], [if]}
{block -> [left_c] stmts ~ [right_c], [while]}
{block -> [left_c] stmts ~ [right_c], [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State113:
	states.push(&&Goto113);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Shift114;
		default: goto ERROR;
	}

Goto113:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift114:
/*
{block -> [left_c] stmts [right_c] ~, [def]}
{block -> [left_c] stmts [right_c] ~, [EOF]}
{block -> [left_c] stmts [right_c] ~, [right_c]}
{block -> [left_c] stmts [right_c] ~, [out]}
{block -> [left_c] stmts [right_c] ~, [in]}
{block -> [left_c] stmts [right_c] ~, [return]}
{block -> [left_c] stmts [right_c] ~, [id]}
{block -> [left_c] stmts [right_c] ~, [left_p]}
{block -> [left_c] stmts [right_c] ~, [left_c]}
{block -> [left_c] stmts [right_c] ~, [not]}
{block -> [left_c] stmts [right_c] ~, [int]}
{block -> [left_c] stmts [right_c] ~, [if]}
{block -> [left_c] stmts [right_c] ~, [while]}
{block -> [left_c] stmts [right_c] ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State114:
	states.push(&&Goto114);
	switch(current_terminal->token()){
		case TOKEN_def: goto Reduce38;
		case TOKEN_EOF: goto Reduce38;
		case TOKEN_right_c: goto Reduce38;
		case TOKEN_out: goto Reduce38;
		case TOKEN_in: goto Reduce38;
		case TOKEN_return: goto Reduce38;
		case TOKEN_id: goto Reduce38;
		case TOKEN_left_p: goto Reduce38;
		case TOKEN_left_c: goto Reduce38;
		case TOKEN_not: goto Reduce38;
		case TOKEN_int: goto Reduce38;
		case TOKEN_if: goto Reduce38;
		case TOKEN_while: goto Reduce38;
		case TOKEN_for: goto Reduce38;
		default: goto ERROR;
	}

Goto114:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift115:
/*
{varexpr -> [id] ~ [left_b] expr [right_b], [semicolon]}
{varexpr -> [id] ~ [left_b] expr [right_b], [dot]}
{varexpr -> [id] ~ [left_b] expr [right_b], [left_p]}
{varexpr -> [id] ~ [left_b] expr [right_b], [or]}
{varexpr -> [id] ~ [left_b] expr [right_b], [and]}
{varexpr -> [id] ~ [left_b] expr [right_b], [bitor]}
{varexpr -> [id] ~ [left_b] expr [right_b], [bitand]}
{varexpr -> [id] ~ [left_b] expr [right_b], [neq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [eq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [gt]}
{varexpr -> [id] ~ [left_b] expr [right_b], [gteq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [le]}
{varexpr -> [id] ~ [left_b] expr [right_b], [leeq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [plus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [minus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [modulo]}
{varexpr -> [id] ~ [left_b] expr [right_b], [division]}
{varexpr -> [id] ~ [left_b] expr [right_b], [multiply]}
{varexpr -> [id] ~, [semicolon]}
{varexpr -> [id] ~, [dot]}
{varexpr -> [id] ~, [left_p]}
{varexpr -> [id] ~, [or]}
{varexpr -> [id] ~, [and]}
{varexpr -> [id] ~, [bitor]}
{varexpr -> [id] ~, [bitand]}
{varexpr -> [id] ~, [neq]}
{varexpr -> [id] ~, [eq]}
{varexpr -> [id] ~, [gt]}
{varexpr -> [id] ~, [gteq]}
{varexpr -> [id] ~, [le]}
{varexpr -> [id] ~, [leeq]}
{varexpr -> [id] ~, [plus]}
{varexpr -> [id] ~, [minus]}
{varexpr -> [id] ~, [modulo]}
{varexpr -> [id] ~, [division]}
{varexpr -> [id] ~, [multiply]}
{varAssign -> [id] ~ [assignment] expr, [semicolon]}
{varAssign -> [id] ~ [plus_assignment] expr, [semicolon]}
{varAssign -> [id] ~ [minus_assignment] expr, [semicolon]}
{varAssign -> [id] ~ [multiply_assignment] expr, [semicolon]}
{varAssign -> [id] ~ [division_assignment] expr, [semicolon]}
{varAssign -> [id] ~ [bitand_assignment] expr, [semicolon]}
{varAssign -> [id] ~ [bitor_assignment] expr, [semicolon]}
{varAssign -> [id] ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State115:
	states.push(&&Goto115);
	switch(current_terminal->token()){
		case TOKEN_left_b: goto Shift49;
		case TOKEN_dot: goto Reduce36;
		case TOKEN_left_p: goto Reduce36;
		case TOKEN_or: goto Reduce36;
		case TOKEN_and: goto Reduce36;
		case TOKEN_bitor: goto Reduce36;
		case TOKEN_bitand: goto Reduce36;
		case TOKEN_neq: goto Reduce36;
		case TOKEN_eq: goto Reduce36;
		case TOKEN_gt: goto Reduce36;
		case TOKEN_gteq: goto Reduce36;
		case TOKEN_le: goto Reduce36;
		case TOKEN_leeq: goto Reduce36;
		case TOKEN_plus: goto Reduce36;
		case TOKEN_minus: goto Reduce36;
		case TOKEN_modulo: goto Reduce36;
		case TOKEN_division: goto Reduce36;
		case TOKEN_multiply: goto Reduce36;
		case TOKEN_assignment: goto Shift128;
		case TOKEN_plus_assignment: goto Shift126;
		case TOKEN_minus_assignment: goto Shift124;
		case TOKEN_multiply_assignment: goto Shift122;
		case TOKEN_division_assignment: goto Shift120;
		case TOKEN_bitand_assignment: goto Shift118;
		case TOKEN_bitor_assignment: goto Shift116;
		case TOKEN_semicolon: goto Reduce33;
		default: goto ERROR;
	}

Goto115:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift116:
/*
{varAssign -> [id] [bitor_assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State116:
	states.push(&&Goto116);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto116:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State117;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift117:
/*
{varAssign -> [id] [bitor_assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State117:
	states.push(&&Goto117);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce32;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto117:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift118:
/*
{varAssign -> [id] [bitand_assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State118:
	states.push(&&Goto118);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto118:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State119;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift119:
/*
{varAssign -> [id] [bitand_assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State119:
	states.push(&&Goto119);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce31;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto119:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift120:
/*
{varAssign -> [id] [division_assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State120:
	states.push(&&Goto120);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto120:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State121;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift121:
/*
{varAssign -> [id] [division_assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State121:
	states.push(&&Goto121);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce30;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto121:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift122:
/*
{varAssign -> [id] [multiply_assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State122:
	states.push(&&Goto122);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto122:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State123;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift123:
/*
{varAssign -> [id] [multiply_assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State123:
	states.push(&&Goto123);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce29;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto123:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift124:
/*
{varAssign -> [id] [minus_assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State124:
	states.push(&&Goto124);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto124:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State125;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift125:
/*
{varAssign -> [id] [minus_assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State125:
	states.push(&&Goto125);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce28;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto125:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift126:
/*
{varAssign -> [id] [plus_assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State126:
	states.push(&&Goto126);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto126:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State127;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift127:
/*
{varAssign -> [id] [plus_assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State127:
	states.push(&&Goto127);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce27;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto127:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift128:
/*
{varAssign -> [id] [assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State128:
	states.push(&&Goto128);
	switch(current_terminal->token()){
		case TOKEN_not: goto Shift14;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift48;
		case TOKEN_left_c: goto Shift64;
		default: goto ERROR;
	}

Goto128:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State129;
		case SYMBOL_varexpr: goto State74;
		case SYMBOL_dictblock: goto State52;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift129:
/*
{varAssign -> [id] [assignment] expr ~, [semicolon]}
{expr -> expr ~ [multiply] expr, [dot]}
{expr -> expr ~ [multiply] expr, [or]}
{expr -> expr ~ [multiply] expr, [and]}
{expr -> expr ~ [multiply] expr, [bitor]}
{expr -> expr ~ [multiply] expr, [bitand]}
{expr -> expr ~ [multiply] expr, [neq]}
{expr -> expr ~ [multiply] expr, [eq]}
{expr -> expr ~ [multiply] expr, [gt]}
{expr -> expr ~ [multiply] expr, [gteq]}
{expr -> expr ~ [multiply] expr, [le]}
{expr -> expr ~ [multiply] expr, [leeq]}
{expr -> expr ~ [multiply] expr, [plus]}
{expr -> expr ~ [multiply] expr, [minus]}
{expr -> expr ~ [multiply] expr, [modulo]}
{expr -> expr ~ [multiply] expr, [division]}
{expr -> expr ~ [multiply] expr, [multiply]}
{expr -> expr ~ [multiply] expr, [semicolon]}
{expr -> expr ~ [division] expr, [dot]}
{expr -> expr ~ [division] expr, [or]}
{expr -> expr ~ [division] expr, [and]}
{expr -> expr ~ [division] expr, [bitor]}
{expr -> expr ~ [division] expr, [bitand]}
{expr -> expr ~ [division] expr, [neq]}
{expr -> expr ~ [division] expr, [eq]}
{expr -> expr ~ [division] expr, [gt]}
{expr -> expr ~ [division] expr, [gteq]}
{expr -> expr ~ [division] expr, [le]}
{expr -> expr ~ [division] expr, [leeq]}
{expr -> expr ~ [division] expr, [plus]}
{expr -> expr ~ [division] expr, [minus]}
{expr -> expr ~ [division] expr, [modulo]}
{expr -> expr ~ [division] expr, [division]}
{expr -> expr ~ [division] expr, [multiply]}
{expr -> expr ~ [division] expr, [semicolon]}
{expr -> expr ~ [modulo] expr, [dot]}
{expr -> expr ~ [modulo] expr, [or]}
{expr -> expr ~ [modulo] expr, [and]}
{expr -> expr ~ [modulo] expr, [bitor]}
{expr -> expr ~ [modulo] expr, [bitand]}
{expr -> expr ~ [modulo] expr, [neq]}
{expr -> expr ~ [modulo] expr, [eq]}
{expr -> expr ~ [modulo] expr, [gt]}
{expr -> expr ~ [modulo] expr, [gteq]}
{expr -> expr ~ [modulo] expr, [le]}
{expr -> expr ~ [modulo] expr, [leeq]}
{expr -> expr ~ [modulo] expr, [plus]}
{expr -> expr ~ [modulo] expr, [minus]}
{expr -> expr ~ [modulo] expr, [modulo]}
{expr -> expr ~ [modulo] expr, [division]}
{expr -> expr ~ [modulo] expr, [multiply]}
{expr -> expr ~ [modulo] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [or]}
{expr -> expr ~ [minus] expr, [and]}
{expr -> expr ~ [minus] expr, [bitor]}
{expr -> expr ~ [minus] expr, [bitand]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [gt]}
{expr -> expr ~ [minus] expr, [gteq]}
{expr -> expr ~ [minus] expr, [le]}
{expr -> expr ~ [minus] expr, [leeq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [modulo]}
{expr -> expr ~ [minus] expr, [division]}
{expr -> expr ~ [minus] expr, [multiply]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [or]}
{expr -> expr ~ [plus] expr, [and]}
{expr -> expr ~ [plus] expr, [bitor]}
{expr -> expr ~ [plus] expr, [bitand]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [gt]}
{expr -> expr ~ [plus] expr, [gteq]}
{expr -> expr ~ [plus] expr, [le]}
{expr -> expr ~ [plus] expr, [leeq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [modulo]}
{expr -> expr ~ [plus] expr, [division]}
{expr -> expr ~ [plus] expr, [multiply]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [leeq] expr, [dot]}
{expr -> expr ~ [leeq] expr, [or]}
{expr -> expr ~ [leeq] expr, [and]}
{expr -> expr ~ [leeq] expr, [bitor]}
{expr -> expr ~ [leeq] expr, [bitand]}
{expr -> expr ~ [leeq] expr, [neq]}
{expr -> expr ~ [leeq] expr, [eq]}
{expr -> expr ~ [leeq] expr, [gt]}
{expr -> expr ~ [leeq] expr, [gteq]}
{expr -> expr ~ [leeq] expr, [le]}
{expr -> expr ~ [leeq] expr, [leeq]}
{expr -> expr ~ [leeq] expr, [plus]}
{expr -> expr ~ [leeq] expr, [minus]}
{expr -> expr ~ [leeq] expr, [modulo]}
{expr -> expr ~ [leeq] expr, [division]}
{expr -> expr ~ [leeq] expr, [multiply]}
{expr -> expr ~ [leeq] expr, [semicolon]}
{expr -> expr ~ [le] expr, [dot]}
{expr -> expr ~ [le] expr, [or]}
{expr -> expr ~ [le] expr, [and]}
{expr -> expr ~ [le] expr, [bitor]}
{expr -> expr ~ [le] expr, [bitand]}
{expr -> expr ~ [le] expr, [neq]}
{expr -> expr ~ [le] expr, [eq]}
{expr -> expr ~ [le] expr, [gt]}
{expr -> expr ~ [le] expr, [gteq]}
{expr -> expr ~ [le] expr, [le]}
{expr -> expr ~ [le] expr, [leeq]}
{expr -> expr ~ [le] expr, [plus]}
{expr -> expr ~ [le] expr, [minus]}
{expr -> expr ~ [le] expr, [modulo]}
{expr -> expr ~ [le] expr, [division]}
{expr -> expr ~ [le] expr, [multiply]}
{expr -> expr ~ [le] expr, [semicolon]}
{expr -> expr ~ [gteq] expr, [dot]}
{expr -> expr ~ [gteq] expr, [or]}
{expr -> expr ~ [gteq] expr, [and]}
{expr -> expr ~ [gteq] expr, [bitor]}
{expr -> expr ~ [gteq] expr, [bitand]}
{expr -> expr ~ [gteq] expr, [neq]}
{expr -> expr ~ [gteq] expr, [eq]}
{expr -> expr ~ [gteq] expr, [gt]}
{expr -> expr ~ [gteq] expr, [gteq]}
{expr -> expr ~ [gteq] expr, [le]}
{expr -> expr ~ [gteq] expr, [leeq]}
{expr -> expr ~ [gteq] expr, [plus]}
{expr -> expr ~ [gteq] expr, [minus]}
{expr -> expr ~ [gteq] expr, [modulo]}
{expr -> expr ~ [gteq] expr, [division]}
{expr -> expr ~ [gteq] expr, [multiply]}
{expr -> expr ~ [gteq] expr, [semicolon]}
{expr -> expr ~ [gt] expr, [dot]}
{expr -> expr ~ [gt] expr, [or]}
{expr -> expr ~ [gt] expr, [and]}
{expr -> expr ~ [gt] expr, [bitor]}
{expr -> expr ~ [gt] expr, [bitand]}
{expr -> expr ~ [gt] expr, [neq]}
{expr -> expr ~ [gt] expr, [eq]}
{expr -> expr ~ [gt] expr, [gt]}
{expr -> expr ~ [gt] expr, [gteq]}
{expr -> expr ~ [gt] expr, [le]}
{expr -> expr ~ [gt] expr, [leeq]}
{expr -> expr ~ [gt] expr, [plus]}
{expr -> expr ~ [gt] expr, [minus]}
{expr -> expr ~ [gt] expr, [modulo]}
{expr -> expr ~ [gt] expr, [division]}
{expr -> expr ~ [gt] expr, [multiply]}
{expr -> expr ~ [gt] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [or]}
{expr -> expr ~ [eq] expr, [and]}
{expr -> expr ~ [eq] expr, [bitor]}
{expr -> expr ~ [eq] expr, [bitand]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [gt]}
{expr -> expr ~ [eq] expr, [gteq]}
{expr -> expr ~ [eq] expr, [le]}
{expr -> expr ~ [eq] expr, [leeq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [modulo]}
{expr -> expr ~ [eq] expr, [division]}
{expr -> expr ~ [eq] expr, [multiply]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [or]}
{expr -> expr ~ [neq] expr, [and]}
{expr -> expr ~ [neq] expr, [bitor]}
{expr -> expr ~ [neq] expr, [bitand]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [gt]}
{expr -> expr ~ [neq] expr, [gteq]}
{expr -> expr ~ [neq] expr, [le]}
{expr -> expr ~ [neq] expr, [leeq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [modulo]}
{expr -> expr ~ [neq] expr, [division]}
{expr -> expr ~ [neq] expr, [multiply]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [bitand] expr, [dot]}
{expr -> expr ~ [bitand] expr, [or]}
{expr -> expr ~ [bitand] expr, [and]}
{expr -> expr ~ [bitand] expr, [bitor]}
{expr -> expr ~ [bitand] expr, [bitand]}
{expr -> expr ~ [bitand] expr, [neq]}
{expr -> expr ~ [bitand] expr, [eq]}
{expr -> expr ~ [bitand] expr, [gt]}
{expr -> expr ~ [bitand] expr, [gteq]}
{expr -> expr ~ [bitand] expr, [le]}
{expr -> expr ~ [bitand] expr, [leeq]}
{expr -> expr ~ [bitand] expr, [plus]}
{expr -> expr ~ [bitand] expr, [minus]}
{expr -> expr ~ [bitand] expr, [modulo]}
{expr -> expr ~ [bitand] expr, [division]}
{expr -> expr ~ [bitand] expr, [multiply]}
{expr -> expr ~ [bitand] expr, [semicolon]}
{expr -> expr ~ [bitor] expr, [dot]}
{expr -> expr ~ [bitor] expr, [or]}
{expr -> expr ~ [bitor] expr, [and]}
{expr -> expr ~ [bitor] expr, [bitor]}
{expr -> expr ~ [bitor] expr, [bitand]}
{expr -> expr ~ [bitor] expr, [neq]}
{expr -> expr ~ [bitor] expr, [eq]}
{expr -> expr ~ [bitor] expr, [gt]}
{expr -> expr ~ [bitor] expr, [gteq]}
{expr -> expr ~ [bitor] expr, [le]}
{expr -> expr ~ [bitor] expr, [leeq]}
{expr -> expr ~ [bitor] expr, [plus]}
{expr -> expr ~ [bitor] expr, [minus]}
{expr -> expr ~ [bitor] expr, [modulo]}
{expr -> expr ~ [bitor] expr, [division]}
{expr -> expr ~ [bitor] expr, [multiply]}
{expr -> expr ~ [bitor] expr, [semicolon]}
{expr -> expr ~ [and] expr, [dot]}
{expr -> expr ~ [and] expr, [or]}
{expr -> expr ~ [and] expr, [and]}
{expr -> expr ~ [and] expr, [bitor]}
{expr -> expr ~ [and] expr, [bitand]}
{expr -> expr ~ [and] expr, [neq]}
{expr -> expr ~ [and] expr, [eq]}
{expr -> expr ~ [and] expr, [gt]}
{expr -> expr ~ [and] expr, [gteq]}
{expr -> expr ~ [and] expr, [le]}
{expr -> expr ~ [and] expr, [leeq]}
{expr -> expr ~ [and] expr, [plus]}
{expr -> expr ~ [and] expr, [minus]}
{expr -> expr ~ [and] expr, [modulo]}
{expr -> expr ~ [and] expr, [division]}
{expr -> expr ~ [and] expr, [multiply]}
{expr -> expr ~ [and] expr, [semicolon]}
{expr -> expr ~ [or] expr, [dot]}
{expr -> expr ~ [or] expr, [or]}
{expr -> expr ~ [or] expr, [and]}
{expr -> expr ~ [or] expr, [bitor]}
{expr -> expr ~ [or] expr, [bitand]}
{expr -> expr ~ [or] expr, [neq]}
{expr -> expr ~ [or] expr, [eq]}
{expr -> expr ~ [or] expr, [gt]}
{expr -> expr ~ [or] expr, [gteq]}
{expr -> expr ~ [or] expr, [le]}
{expr -> expr ~ [or] expr, [leeq]}
{expr -> expr ~ [or] expr, [plus]}
{expr -> expr ~ [or] expr, [minus]}
{expr -> expr ~ [or] expr, [modulo]}
{expr -> expr ~ [or] expr, [division]}
{expr -> expr ~ [or] expr, [multiply]}
{expr -> expr ~ [or] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [or]}
{varexpr -> expr ~ [dot] [id], [and]}
{varexpr -> expr ~ [dot] [id], [bitor]}
{varexpr -> expr ~ [dot] [id], [bitand]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [gt]}
{varexpr -> expr ~ [dot] [id], [gteq]}
{varexpr -> expr ~ [dot] [id], [le]}
{varexpr -> expr ~ [dot] [id], [leeq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [modulo]}
{varexpr -> expr ~ [dot] [id], [division]}
{varexpr -> expr ~ [dot] [id], [multiply]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State129:
	states.push(&&Goto129);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce26;
		case TOKEN_multiply: goto Shift44;
		case TOKEN_division: goto Shift42;
		case TOKEN_modulo: goto Shift40;
		case TOKEN_minus: goto Shift38;
		case TOKEN_plus: goto Shift36;
		case TOKEN_leeq: goto Shift34;
		case TOKEN_le: goto Shift32;
		case TOKEN_gteq: goto Shift30;
		case TOKEN_gt: goto Shift28;
		case TOKEN_eq: goto Shift26;
		case TOKEN_neq: goto Shift24;
		case TOKEN_bitand: goto Shift22;
		case TOKEN_bitor: goto Shift20;
		case TOKEN_and: goto Shift18;
		case TOKEN_or: goto Shift16;
		case TOKEN_dot: goto Shift46;
		default: goto ERROR;
	}

Goto129:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift130:
/*
{method -> [def] [id] paramsblock block ~, [def]}
{method -> [def] [id] paramsblock block ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State130:
	states.push(&&Goto130);
	switch(current_terminal->token()){
		case TOKEN_def: goto Reduce7;
		case TOKEN_EOF: goto Reduce7;
		default: goto ERROR;
	}

Goto130:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift131:
/*
{top_def -> method ~, [def]}
{top_def -> method ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State131:
	states.push(&&Goto131);
	switch(current_terminal->token()){
		case TOKEN_def: goto Reduce6;
		case TOKEN_EOF: goto Reduce6;
		default: goto ERROR;
	}

Goto131:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift132:
/*
{top_defs -> top_def ~ top_defs, [EOF]}
{top_defs -> top_def ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State132:
	states.push(&&Goto132);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce5;
		case TOKEN_def: goto Shift1;
		default: goto ERROR;
	}

Goto132:
	switch(top_non_terminal){
		case SYMBOL_top_defs: goto State133;
		case SYMBOL_top_def: goto State132;
		case SYMBOL_method: goto State131;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift133:
/*
{top_defs -> top_def top_defs ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State133:
	states.push(&&Goto133);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce4;
		default: goto ERROR;
	}

Goto133:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift134:
/*
{program -> [error] ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State134:
	states.push(&&Goto134);
Switch134:
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce3;
		default:
			((ErrorTerminal*)symbols.top())->discard(current_terminal);
			current_terminal = lexer->nextToken();
			goto Switch134;
	}

Goto134:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift135:
/*
{program -> top_defs ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State135:
	states.push(&&Goto135);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce2;
		default: goto ERROR;
	}

Goto135:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift136:
/*
{program -> [newline] ~ top_defs, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State136:
	states.push(&&Goto136);
	switch(current_terminal->token()){
		case TOKEN_def: goto Shift1;
		default: goto ERROR;
	}

Goto136:
	switch(top_non_terminal){
		case SYMBOL_top_defs: goto State137;
		case SYMBOL_top_def: goto State132;
		case SYMBOL_method: goto State131;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift137:
/*
{program -> [newline] top_defs ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State137:
	states.push(&&Goto137);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce1;
		default: goto ERROR;
	}

Goto137:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift138:
/*
{root -> program ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State138:
	states.push(&&Goto138);
	switch(current_terminal->token()){
		case TOKEN_EOF: return symbols.top();
		default: goto ERROR;
	}

Goto138:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

	/*** Reductions ****/
Reduce0: //root -> program
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_root;
	goto *states.top();

Reduce1: //program -> [newline] top_defs
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_program;
	goto *states.top();

Reduce2: //program -> top_defs
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_program;
	goto *states.top();

Reduce3: //program -> [error]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE error"<<endl;result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_program;
	goto *states.top();

Reduce4: //top_defs -> top_def top_defs
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	((NodeTop*)arg0)->setNext((NodeTop*)arg1); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_top_defs;
	goto *states.top();

Reduce5: //top_defs -> top_def
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_top_defs;
	goto *states.top();

Reduce6: //top_def -> method
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_top_def;
	goto *states.top();

Reduce7: //method -> [def] [id] paramsblock block
	arg3 = symbols.top();
	symbols.pop();
	states.pop();
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE method"<<endl;result = new NodeMethod((TypeDenoter*)arg0, (Identifier*)arg1, (NodeParam*)arg2, (NodeStmt*)arg3);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_method;
	goto *states.top();

Reduce8: //stmts -> stmt [semicolon] stmts
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE stmt semicolon stmts"<<endl;((NodeStmt*)arg0)->setNext((NodeStmt*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmts;
	goto *states.top();

Reduce9: //stmts -> closedStmt stmts
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE stmt semicolon stmts"<<endl;((NodeStmt*)arg0)->setNext((NodeStmt*)arg1); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmts;
	goto *states.top();

Reduce10: //stmts -> stmt [semicolon]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE stmt"<<endl;result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmts;
	goto *states.top();

Reduce11: //stmts -> closedStmt
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE stmt semicolon stmts"<<endl; result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmts;
	goto *states.top();

Reduce12: //stmt -> [out] outDecl
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE out outDecl"<<endl;result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce13: //stmt -> [in] inDecl
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE in inDecl"<<endl;result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce14: //stmt -> [return] returnStmt
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE return returnStmt"<<endl;result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce15: //stmt -> varAssign
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE varAssign Stmt"<<endl;result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce16: //stmt -> tuprefblock [assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tuprefblock assignment expr"<<endl;result = new NodeTupAssignStmt((NodeTupDref*)arg0, (NodeExpr*)arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce17: //stmt -> expr
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE expr"<<endl; result = new NodeExprStmt((NodeExpr*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce18: //paramsblock -> [left_p] params [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_paramsblock;
	goto *states.top();

Reduce19: //paramsblock -> [left_p] [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = NULL;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_paramsblock;
	goto *states.top();

Reduce20: //params -> param [comma] params
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	((NodeParam*)arg0)->setNext((NodeParam*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_params;
	goto *states.top();

Reduce21: //params -> param
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_params;
	goto *states.top();

Reduce22: //param -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = new NodeParam(NULL, (Identifier*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_param;
	goto *states.top();

Reduce23: //outDecl -> [id] [assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE id assignment expr"<<endl;result = new NodeOutdeclStmt((Identifier*)arg0,(NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_outDecl;
	goto *states.top();

Reduce24: //inDecl -> inDecl [comma] inDecl
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE in decl block"<<endl;((NodeIndeclStmt*)arg0)->setNext((NodeIndeclStmt*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_inDecl;
	goto *states.top();

Reduce25: //inDecl -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE in decl"<<endl;result = new NodeIndeclStmt((Identifier*)arg0, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_inDecl;
	goto *states.top();

Reduce26: //varAssign -> [id] [assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE id assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce27: //varAssign -> [id] [plus_assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE add assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce28: //varAssign -> [id] [minus_assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE minus assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce29: //varAssign -> [id] [multiply_assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE multiply assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce30: //varAssign -> [id] [division_assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE division assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce31: //varAssign -> [id] [bitand_assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE bitand assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce32: //varAssign -> [id] [bitor_assignment] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE bitor assignment expr"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, (Terminal*)arg1, (NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce33: //varAssign -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE id"<<endl; result = new NodeVardeclStmt((Identifier*)arg0, NULL, NULL, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varAssign;
	goto *states.top();

Reduce34: //returnStmt -> expr
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE returnStmt"<<endl;result = new NodeRtnStmt((NodeExpr*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_returnStmt;
	goto *states.top();

Reduce35: //varexpr -> [id] [left_b] expr [right_b]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE varexpr: left_b expr right_b"<<endl;result = new NodeKeyAccessVariable((Identifier*)arg0, (NodeExpr*)arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varexpr;
	goto *states.top();

Reduce36: //varexpr -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE varexpr: id"<<endl;result = new NodeVariable((Identifier*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varexpr;
	goto *states.top();

Reduce37: //varexpr -> expr [dot] [id]
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE varexpr: expr dot id"<<endl;result = new NodeAttributeAccessVariable((NodeExpr*)arg0, (Identifier*)arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varexpr;
	goto *states.top();

Reduce38: //block -> [left_c] stmts [right_c]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE block"<<endl;result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_block;
	goto *states.top();

Reduce39: //closedStmt -> [if] expr block
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE if"<<endl; result = new NodeIfStmt((NodeExpr*)arg1, (NodeStmt*)arg2, NULL, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_closedStmt;
	goto *states.top();

Reduce40: //closedStmt -> [while] expr block
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE while"<<endl; result = new NodeWhileStmt((NodeExpr*)arg1, (NodeStmt*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_closedStmt;
	goto *states.top();

Reduce41: //closedStmt -> [for] [id] [in] expr block
	arg4 = symbols.top();
	symbols.pop();
	states.pop();
	arg3 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE for i in"<<endl; result = new NodeForEachStmt((Identifier*)arg1, (NodeExpr*)arg3, (NodeStmt*)arg4, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_closedStmt;
	goto *states.top();

Reduce42: //type -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	result = new TypeDenoter((Identifier*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_type;
	goto *states.top();

Reduce43: //argblock -> [left_p] args [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE argblock"<<endl; result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_argblock;
	goto *states.top();

Reduce44: //argblock -> [left_p] [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE argblock"<<endl; result = NULL;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_argblock;
	goto *states.top();

Reduce45: //args -> arg [comma] args
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE args"<<endl; ((NodeArg*)arg0)->setNext((NodeArg*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_args;
	goto *states.top();

Reduce46: //args -> arg
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE args"<<endl; result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_args;
	goto *states.top();

Reduce47: //arg -> expr
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE arg"<<endl; result = new NodeArg((NodeExpr*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_arg;
	goto *states.top();

Reduce48: //tupblock -> [left_p] tups [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tupblock"<<endl; result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tupblock;
	goto *states.top();

Reduce49: //tupblock -> [left_p] [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tupblock"<<endl; result = NULL;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tupblock;
	goto *states.top();

Reduce50: //tups -> tup [comma] tups
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tups"<<endl; ((NodeArg*)arg0)->setNext((NodeArg*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tups;
	goto *states.top();

Reduce51: //tups -> tup
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tups"<<endl; result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tups;
	goto *states.top();

Reduce52: //tup -> expr
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tup"<<endl; result = new NodeArg((NodeExpr*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tup;
	goto *states.top();

Reduce53: //tuprefblock -> [left_p] tuprefs [right_p]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE tuprefblock: left_p tuprefs right_p "<<endl; result = arg1;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tuprefblock;
	goto *states.top();

Reduce54: //tuprefs -> tuprefs [comma] tuprefs
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE reftups: varexpr comma tups"<<endl; ((NodeTupDref*)arg0)->setNext((NodeTupDref*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tuprefs;
	goto *states.top();

Reduce55: //tuprefs -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE reftups: varexpr"<<endl; result = new NodeTupDref(new NodeVariable((Identifier*)arg0)) ;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_tuprefs;
	goto *states.top();

Reduce56: //dictblock -> [left_c] pairs [right_c]
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE dictblock: left_c tuprefs right_c"<<endl; result = new NodeDictExpr((NodePair*)arg1);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_dictblock;
	goto *states.top();

Reduce57: //dictblock -> [left_c] [right_c]
	delete symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE dictblock: left_c right_c"<<endl; result = new NodeDictExpr(NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_dictblock;
	goto *states.top();

Reduce58: //pairs -> pairs [comma] pairs
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE pairs comma pairs  "<<endl; ((NodePair*)arg0)->setNext((NodePair*)arg2); result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_pairs;
	goto *states.top();

Reduce59: //pairs -> pair
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE pair"<<endl; result = ((NodePair*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_pairs;
	goto *states.top();

Reduce60: //pair -> expr [colon] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE expr colon expr"<<endl; result = new NodePair((NodeExpr*)arg0 , (NodeExpr*)arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_pair;
	goto *states.top();

Reduce61: //expr -> dictblock
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE dictblock"<<endl; result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce62: //expr -> [not] expr
	delete symbols.top();
	symbols.pop();
	states.pop();
	delete symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE not not implemented"<<endl; result = NULL;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce63: //expr -> expr [multiply] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE multiply"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce64: //expr -> expr [division] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE division"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce65: //expr -> expr [modulo] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE modulo"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce66: //expr -> expr [minus] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE minus"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce67: //expr -> expr [plus] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE plus"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce68: //expr -> expr [leeq] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE leeq"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce69: //expr -> expr [le] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE le"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce70: //expr -> expr [gteq] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE gteq"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce71: //expr -> expr [gt] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE gt"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce72: //expr -> expr [eq] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE eq"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce73: //expr -> expr [neq] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE neq"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce74: //expr -> expr [bitand] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE bitand"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce75: //expr -> expr [bitor] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE bitor"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce76: //expr -> expr [and] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE and"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce77: //expr -> expr [or] expr
	arg2 = symbols.top();
	symbols.pop();
	states.pop();
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE or"<<endl; result = BinOp(arg0, arg1, arg2);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce78: //expr -> [int]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE int"<<endl; result = new NodeLiteralExpr((IntegerLiteral*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce79: //expr -> varexpr argblock
	arg1 = symbols.top();
	symbols.pop();
	states.pop();
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE call"<<endl; result = new NodeCallExpr(new NodeVariableExpr((NodeVariable*)arg0), (NodeArg*)arg1);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();

Reduce80: //expr -> varexpr
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE varexpr"<<endl; result = new NodeVariableExpr((NodeVariable*)arg0);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_expr;
	goto *states.top();


ERROR:
	current_terminal = new ErrorTerminal(current_terminal);
	top_non_terminal = SYMBOL_error;
	goto *states.top();
FATAL_ERROR:
	fprintf(stderr, "Fatal error occured, this shouldn't be possible!");
	exit(9);
}

string TokenToString(Token token){
	switch(token){
		case TOKEN_EOF: return "EOF";
		case TOKEN_newline: return "newline";
		case TOKEN_error: return "error";
		case TOKEN_def: return "def";
		case TOKEN_id: return "id";
		case TOKEN_semicolon: return "semicolon";
		case TOKEN_out: return "out";
		case TOKEN_in: return "in";
		case TOKEN_return: return "return";
		case TOKEN_assignment: return "assignment";
		case TOKEN_left_p: return "left_p";
		case TOKEN_right_p: return "right_p";
		case TOKEN_comma: return "comma";
		case TOKEN_plus_assignment: return "plus_assignment";
		case TOKEN_minus_assignment: return "minus_assignment";
		case TOKEN_multiply_assignment: return "multiply_assignment";
		case TOKEN_division_assignment: return "division_assignment";
		case TOKEN_bitand_assignment: return "bitand_assignment";
		case TOKEN_bitor_assignment: return "bitor_assignment";
		case TOKEN_left_b: return "left_b";
		case TOKEN_right_b: return "right_b";
		case TOKEN_dot: return "dot";
		case TOKEN_left_c: return "left_c";
		case TOKEN_right_c: return "right_c";
		case TOKEN_if: return "if";
		case TOKEN_while: return "while";
		case TOKEN_for: return "for";
		case TOKEN_colon: return "colon";
		case TOKEN_not: return "not";
		case TOKEN_multiply: return "multiply";
		case TOKEN_division: return "division";
		case TOKEN_modulo: return "modulo";
		case TOKEN_minus: return "minus";
		case TOKEN_plus: return "plus";
		case TOKEN_leeq: return "leeq";
		case TOKEN_le: return "le";
		case TOKEN_gteq: return "gteq";
		case TOKEN_gt: return "gt";
		case TOKEN_eq: return "eq";
		case TOKEN_neq: return "neq";
		case TOKEN_bitand: return "bitand";
		case TOKEN_bitor: return "bitor";
		case TOKEN_and: return "and";
		case TOKEN_or: return "or";
		case TOKEN_int: return "int";
		default: return "Unknown token";
	}
}


