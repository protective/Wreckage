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
	SYMBOL_varDecl,
	SYMBOL_expr,
	SYMBOL_tuprefblock,
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
		case TOKEN_newline: goto Shift102;
		case TOKEN_error: goto Shift100;
		case TOKEN_def: goto Shift1;
		default: goto ERROR;
	}

Goto0:
	switch(top_non_terminal){
		case SYMBOL_program: goto State104;
		case SYMBOL_top_defs: goto State101;
		case SYMBOL_top_def: goto State98;
		case SYMBOL_method: goto State97;
		case SYMBOL_error:
			goto Shift100;
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
		case SYMBOL_block: goto State96;
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
{block -> [left_c] ~ stmts [right_c], [left_c]}
{block -> [left_c] ~ stmts [right_c], [int]}
{block -> [left_c] ~ stmts [right_c], [left_p]}
{block -> [left_c] ~ stmts [right_c], [if]}
{block -> [left_c] ~ stmts [right_c], [while]}
{block -> [left_c] ~ stmts [right_c], [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State12:
	states.push(&&Goto12);
	switch(current_terminal->token()){
		case TOKEN_if: goto Shift37;
		case TOKEN_while: goto Shift34;
		case TOKEN_for: goto Shift15;
		case TOKEN_out: goto Shift81;
		case TOKEN_in: goto Shift76;
		case TOKEN_return: goto Shift73;
		case TOKEN_left_p: goto Shift62;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift93;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto12:
	switch(top_non_terminal){
		case SYMBOL_stmts: goto State91;
		case SYMBOL_stmt: goto State88;
		case SYMBOL_closedStmt: goto State86;
		case SYMBOL_varDecl: goto State72;
		case SYMBOL_expr: goto State71;
		case SYMBOL_tuprefblock: goto State68;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
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
{expr -> [int] ~, [neq]}
{expr -> [int] ~, [eq]}
{expr -> [int] ~, [plus]}
{expr -> [int] ~, [minus]}
{expr -> [int] ~, [left_c]}
{expr -> [int] ~, [right_b]}
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
		case TOKEN_semicolon: goto Reduce60;
		case TOKEN_dot: goto Reduce60;
		case TOKEN_neq: goto Reduce60;
		case TOKEN_eq: goto Reduce60;
		case TOKEN_plus: goto Reduce60;
		case TOKEN_minus: goto Reduce60;
		case TOKEN_left_c: goto Reduce60;
		case TOKEN_right_b: goto Reduce60;
		case TOKEN_colon: goto Reduce60;
		case TOKEN_right_p: goto Reduce60;
		case TOKEN_comma: goto Reduce60;
		case TOKEN_right_c: goto Reduce60;
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
{expr -> dictblock ~, [semicolon]}
{expr -> dictblock ~, [dot]}
{expr -> dictblock ~, [neq]}
{expr -> dictblock ~, [eq]}
{expr -> dictblock ~, [plus]}
{expr -> dictblock ~, [minus]}
{expr -> dictblock ~, [left_c]}
{expr -> dictblock ~, [right_b]}
{expr -> dictblock ~, [colon]}
{expr -> dictblock ~, [right_p]}
{expr -> dictblock ~, [comma]}
{expr -> dictblock ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State14:
	states.push(&&Goto14);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce55;
		case TOKEN_dot: goto Reduce55;
		case TOKEN_neq: goto Reduce55;
		case TOKEN_eq: goto Reduce55;
		case TOKEN_plus: goto Reduce55;
		case TOKEN_minus: goto Reduce55;
		case TOKEN_left_c: goto Reduce55;
		case TOKEN_right_b: goto Reduce55;
		case TOKEN_colon: goto Reduce55;
		case TOKEN_right_p: goto Reduce55;
		case TOKEN_comma: goto Reduce55;
		case TOKEN_right_c: goto Reduce55;
		default: goto ERROR;
	}

Goto14:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift15:
/*
{closedStmt -> [for] ~ [id] [in] expr block, [right_c]}
{closedStmt -> [for] ~ [id] [in] expr block, [out]}
{closedStmt -> [for] ~ [id] [in] expr block, [in]}
{closedStmt -> [for] ~ [id] [in] expr block, [return]}
{closedStmt -> [for] ~ [id] [in] expr block, [id]}
{closedStmt -> [for] ~ [id] [in] expr block, [left_c]}
{closedStmt -> [for] ~ [id] [in] expr block, [int]}
{closedStmt -> [for] ~ [id] [in] expr block, [left_p]}
{closedStmt -> [for] ~ [id] [in] expr block, [if]}
{closedStmt -> [for] ~ [id] [in] expr block, [while]}
{closedStmt -> [for] ~ [id] [in] expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State15:
	states.push(&&Goto15);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift16;
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
{closedStmt -> [for] [id] ~ [in] expr block, [right_c]}
{closedStmt -> [for] [id] ~ [in] expr block, [out]}
{closedStmt -> [for] [id] ~ [in] expr block, [in]}
{closedStmt -> [for] [id] ~ [in] expr block, [return]}
{closedStmt -> [for] [id] ~ [in] expr block, [id]}
{closedStmt -> [for] [id] ~ [in] expr block, [left_c]}
{closedStmt -> [for] [id] ~ [in] expr block, [int]}
{closedStmt -> [for] [id] ~ [in] expr block, [left_p]}
{closedStmt -> [for] [id] ~ [in] expr block, [if]}
{closedStmt -> [for] [id] ~ [in] expr block, [while]}
{closedStmt -> [for] [id] ~ [in] expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State16:
	states.push(&&Goto16);
	switch(current_terminal->token()){
		case TOKEN_in: goto Shift17;
		default: goto ERROR;
	}

Goto16:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift17:
/*
{closedStmt -> [for] [id] [in] ~ expr block, [right_c]}
{closedStmt -> [for] [id] [in] ~ expr block, [out]}
{closedStmt -> [for] [id] [in] ~ expr block, [in]}
{closedStmt -> [for] [id] [in] ~ expr block, [return]}
{closedStmt -> [for] [id] [in] ~ expr block, [id]}
{closedStmt -> [for] [id] [in] ~ expr block, [left_c]}
{closedStmt -> [for] [id] [in] ~ expr block, [int]}
{closedStmt -> [for] [id] [in] ~ expr block, [left_p]}
{closedStmt -> [for] [id] [in] ~ expr block, [if]}
{closedStmt -> [for] [id] [in] ~ expr block, [while]}
{closedStmt -> [for] [id] [in] ~ expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State17:
	states.push(&&Goto17);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto17:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State18;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift18:
/*
{closedStmt -> [for] [id] [in] expr ~ block, [right_c]}
{closedStmt -> [for] [id] [in] expr ~ block, [out]}
{closedStmt -> [for] [id] [in] expr ~ block, [in]}
{closedStmt -> [for] [id] [in] expr ~ block, [return]}
{closedStmt -> [for] [id] [in] expr ~ block, [id]}
{closedStmt -> [for] [id] [in] expr ~ block, [left_c]}
{closedStmt -> [for] [id] [in] expr ~ block, [int]}
{closedStmt -> [for] [id] [in] expr ~ block, [left_p]}
{closedStmt -> [for] [id] [in] expr ~ block, [if]}
{closedStmt -> [for] [id] [in] expr ~ block, [while]}
{closedStmt -> [for] [id] [in] expr ~ block, [for]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State18:
	states.push(&&Goto18);
	switch(current_terminal->token()){
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto18:
	switch(top_non_terminal){
		case SYMBOL_block: goto State29;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift19:
/*
{expr -> expr [neq] ~ expr, [left_c]}
{expr -> expr [neq] ~ expr, [dot]}
{expr -> expr [neq] ~ expr, [neq]}
{expr -> expr [neq] ~ expr, [eq]}
{expr -> expr [neq] ~ expr, [plus]}
{expr -> expr [neq] ~ expr, [minus]}
{expr -> expr [neq] ~ expr, [right_b]}
{expr -> expr [neq] ~ expr, [colon]}
{expr -> expr [neq] ~ expr, [right_c]}
{expr -> expr [neq] ~ expr, [comma]}
{expr -> expr [neq] ~ expr, [right_p]}
{expr -> expr [neq] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State19:
	states.push(&&Goto19);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto19:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State20;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift20:
/*
{expr -> expr [neq] expr ~, [left_c]}
{expr -> expr [neq] expr ~, [dot]}
{expr -> expr [neq] expr ~, [neq]}
{expr -> expr [neq] expr ~, [eq]}
{expr -> expr [neq] expr ~, [plus]}
{expr -> expr [neq] expr ~, [minus]}
{expr -> expr [neq] expr ~, [right_b]}
{expr -> expr [neq] expr ~, [colon]}
{expr -> expr [neq] expr ~, [right_c]}
{expr -> expr [neq] expr ~, [comma]}
{expr -> expr [neq] expr ~, [right_p]}
{expr -> expr [neq] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_c]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State20:
	states.push(&&Goto20);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Reduce59;
		case TOKEN_neq: goto Reduce59;
		case TOKEN_right_b: goto Reduce59;
		case TOKEN_colon: goto Reduce59;
		case TOKEN_right_c: goto Reduce59;
		case TOKEN_comma: goto Reduce59;
		case TOKEN_right_p: goto Reduce59;
		case TOKEN_semicolon: goto Reduce59;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto20:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift21:
/*
{expr -> expr [eq] ~ expr, [left_c]}
{expr -> expr [eq] ~ expr, [dot]}
{expr -> expr [eq] ~ expr, [neq]}
{expr -> expr [eq] ~ expr, [eq]}
{expr -> expr [eq] ~ expr, [plus]}
{expr -> expr [eq] ~ expr, [minus]}
{expr -> expr [eq] ~ expr, [right_b]}
{expr -> expr [eq] ~ expr, [colon]}
{expr -> expr [eq] ~ expr, [right_c]}
{expr -> expr [eq] ~ expr, [comma]}
{expr -> expr [eq] ~ expr, [right_p]}
{expr -> expr [eq] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State21:
	states.push(&&Goto21);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto21:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State22;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift22:
/*
{expr -> expr [eq] expr ~, [left_c]}
{expr -> expr [eq] expr ~, [dot]}
{expr -> expr [eq] expr ~, [neq]}
{expr -> expr [eq] expr ~, [eq]}
{expr -> expr [eq] expr ~, [plus]}
{expr -> expr [eq] expr ~, [minus]}
{expr -> expr [eq] expr ~, [right_b]}
{expr -> expr [eq] expr ~, [colon]}
{expr -> expr [eq] expr ~, [right_c]}
{expr -> expr [eq] expr ~, [comma]}
{expr -> expr [eq] expr ~, [right_p]}
{expr -> expr [eq] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_c]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State22:
	states.push(&&Goto22);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Reduce58;
		case TOKEN_neq: goto Reduce58;
		case TOKEN_eq: goto Reduce58;
		case TOKEN_right_b: goto Reduce58;
		case TOKEN_colon: goto Reduce58;
		case TOKEN_right_c: goto Reduce58;
		case TOKEN_comma: goto Reduce58;
		case TOKEN_right_p: goto Reduce58;
		case TOKEN_semicolon: goto Reduce58;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto22:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift23:
/*
{expr -> expr [plus] ~ expr, [left_c]}
{expr -> expr [plus] ~ expr, [dot]}
{expr -> expr [plus] ~ expr, [neq]}
{expr -> expr [plus] ~ expr, [eq]}
{expr -> expr [plus] ~ expr, [plus]}
{expr -> expr [plus] ~ expr, [minus]}
{expr -> expr [plus] ~ expr, [right_b]}
{expr -> expr [plus] ~ expr, [colon]}
{expr -> expr [plus] ~ expr, [right_c]}
{expr -> expr [plus] ~ expr, [comma]}
{expr -> expr [plus] ~ expr, [right_p]}
{expr -> expr [plus] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State23:
	states.push(&&Goto23);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto23:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State24;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift24:
/*
{expr -> expr [plus] expr ~, [left_c]}
{expr -> expr [plus] expr ~, [dot]}
{expr -> expr [plus] expr ~, [neq]}
{expr -> expr [plus] expr ~, [eq]}
{expr -> expr [plus] expr ~, [plus]}
{expr -> expr [plus] expr ~, [minus]}
{expr -> expr [plus] expr ~, [right_b]}
{expr -> expr [plus] expr ~, [colon]}
{expr -> expr [plus] expr ~, [right_c]}
{expr -> expr [plus] expr ~, [comma]}
{expr -> expr [plus] expr ~, [right_p]}
{expr -> expr [plus] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_c]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State24:
	states.push(&&Goto24);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Reduce57;
		case TOKEN_neq: goto Reduce57;
		case TOKEN_eq: goto Reduce57;
		case TOKEN_plus: goto Reduce57;
		case TOKEN_right_b: goto Reduce57;
		case TOKEN_colon: goto Reduce57;
		case TOKEN_right_c: goto Reduce57;
		case TOKEN_comma: goto Reduce57;
		case TOKEN_right_p: goto Reduce57;
		case TOKEN_semicolon: goto Reduce57;
		case TOKEN_minus: goto Shift25;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto24:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift25:
/*
{expr -> expr [minus] ~ expr, [left_c]}
{expr -> expr [minus] ~ expr, [dot]}
{expr -> expr [minus] ~ expr, [neq]}
{expr -> expr [minus] ~ expr, [eq]}
{expr -> expr [minus] ~ expr, [plus]}
{expr -> expr [minus] ~ expr, [minus]}
{expr -> expr [minus] ~ expr, [right_b]}
{expr -> expr [minus] ~ expr, [colon]}
{expr -> expr [minus] ~ expr, [right_c]}
{expr -> expr [minus] ~ expr, [comma]}
{expr -> expr [minus] ~ expr, [right_p]}
{expr -> expr [minus] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State25:
	states.push(&&Goto25);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto25:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State26;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift26:
/*
{expr -> expr [minus] expr ~, [left_c]}
{expr -> expr [minus] expr ~, [dot]}
{expr -> expr [minus] expr ~, [neq]}
{expr -> expr [minus] expr ~, [eq]}
{expr -> expr [minus] expr ~, [plus]}
{expr -> expr [minus] expr ~, [minus]}
{expr -> expr [minus] expr ~, [right_b]}
{expr -> expr [minus] expr ~, [colon]}
{expr -> expr [minus] expr ~, [right_c]}
{expr -> expr [minus] expr ~, [comma]}
{expr -> expr [minus] expr ~, [right_p]}
{expr -> expr [minus] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_c]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State26:
	states.push(&&Goto26);
	switch(current_terminal->token()){
		case TOKEN_left_c: goto Reduce56;
		case TOKEN_neq: goto Reduce56;
		case TOKEN_eq: goto Reduce56;
		case TOKEN_plus: goto Reduce56;
		case TOKEN_minus: goto Reduce56;
		case TOKEN_right_b: goto Reduce56;
		case TOKEN_colon: goto Reduce56;
		case TOKEN_right_c: goto Reduce56;
		case TOKEN_comma: goto Reduce56;
		case TOKEN_right_p: goto Reduce56;
		case TOKEN_semicolon: goto Reduce56;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto26:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift27:
/*
{varexpr -> expr [dot] ~ [id], [assignment]}
{varexpr -> expr [dot] ~ [id], [dot]}
{varexpr -> expr [dot] ~ [id], [left_p]}
{varexpr -> expr [dot] ~ [id], [neq]}
{varexpr -> expr [dot] ~ [id], [eq]}
{varexpr -> expr [dot] ~ [id], [plus]}
{varexpr -> expr [dot] ~ [id], [minus]}
{varexpr -> expr [dot] ~ [id], [left_c]}
{varexpr -> expr [dot] ~ [id], [right_b]}
{varexpr -> expr [dot] ~ [id], [colon]}
{varexpr -> expr [dot] ~ [id], [right_c]}
{varexpr -> expr [dot] ~ [id], [comma]}
{varexpr -> expr [dot] ~ [id], [right_p]}
{varexpr -> expr [dot] ~ [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State27:
	states.push(&&Goto27);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift28;
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
{varexpr -> expr [dot] [id] ~, [assignment]}
{varexpr -> expr [dot] [id] ~, [dot]}
{varexpr -> expr [dot] [id] ~, [left_p]}
{varexpr -> expr [dot] [id] ~, [neq]}
{varexpr -> expr [dot] [id] ~, [eq]}
{varexpr -> expr [dot] [id] ~, [plus]}
{varexpr -> expr [dot] [id] ~, [minus]}
{varexpr -> expr [dot] [id] ~, [left_c]}
{varexpr -> expr [dot] [id] ~, [right_b]}
{varexpr -> expr [dot] [id] ~, [colon]}
{varexpr -> expr [dot] [id] ~, [right_c]}
{varexpr -> expr [dot] [id] ~, [comma]}
{varexpr -> expr [dot] [id] ~, [right_p]}
{varexpr -> expr [dot] [id] ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State28:
	states.push(&&Goto28);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Reduce31;
		case TOKEN_dot: goto Reduce31;
		case TOKEN_left_p: goto Reduce31;
		case TOKEN_neq: goto Reduce31;
		case TOKEN_eq: goto Reduce31;
		case TOKEN_plus: goto Reduce31;
		case TOKEN_minus: goto Reduce31;
		case TOKEN_left_c: goto Reduce31;
		case TOKEN_right_b: goto Reduce31;
		case TOKEN_colon: goto Reduce31;
		case TOKEN_right_c: goto Reduce31;
		case TOKEN_comma: goto Reduce31;
		case TOKEN_right_p: goto Reduce31;
		case TOKEN_semicolon: goto Reduce31;
		default: goto ERROR;
	}

Goto28:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift29:
/*
{closedStmt -> [for] [id] [in] expr block ~, [right_c]}
{closedStmt -> [for] [id] [in] expr block ~, [out]}
{closedStmt -> [for] [id] [in] expr block ~, [in]}
{closedStmt -> [for] [id] [in] expr block ~, [return]}
{closedStmt -> [for] [id] [in] expr block ~, [id]}
{closedStmt -> [for] [id] [in] expr block ~, [left_c]}
{closedStmt -> [for] [id] [in] expr block ~, [int]}
{closedStmt -> [for] [id] [in] expr block ~, [left_p]}
{closedStmt -> [for] [id] [in] expr block ~, [if]}
{closedStmt -> [for] [id] [in] expr block ~, [while]}
{closedStmt -> [for] [id] [in] expr block ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State29:
	states.push(&&Goto29);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce35;
		case TOKEN_out: goto Reduce35;
		case TOKEN_in: goto Reduce35;
		case TOKEN_return: goto Reduce35;
		case TOKEN_id: goto Reduce35;
		case TOKEN_left_c: goto Reduce35;
		case TOKEN_int: goto Reduce35;
		case TOKEN_left_p: goto Reduce35;
		case TOKEN_if: goto Reduce35;
		case TOKEN_while: goto Reduce35;
		case TOKEN_for: goto Reduce35;
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
{varexpr -> [id] ~ [left_b] expr [right_b], [assignment]}
{varexpr -> [id] ~ [left_b] expr [right_b], [dot]}
{varexpr -> [id] ~ [left_b] expr [right_b], [left_p]}
{varexpr -> [id] ~ [left_b] expr [right_b], [neq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [eq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [plus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [minus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [left_c]}
{varexpr -> [id] ~ [left_b] expr [right_b], [right_b]}
{varexpr -> [id] ~ [left_b] expr [right_b], [colon]}
{varexpr -> [id] ~ [left_b] expr [right_b], [right_p]}
{varexpr -> [id] ~ [left_b] expr [right_b], [comma]}
{varexpr -> [id] ~ [left_b] expr [right_b], [right_c]}
{varexpr -> [id] ~ [left_b] expr [right_b], [semicolon]}
{varexpr -> [id] ~, [assignment]}
{varexpr -> [id] ~, [dot]}
{varexpr -> [id] ~, [left_p]}
{varexpr -> [id] ~, [neq]}
{varexpr -> [id] ~, [eq]}
{varexpr -> [id] ~, [plus]}
{varexpr -> [id] ~, [minus]}
{varexpr -> [id] ~, [left_c]}
{varexpr -> [id] ~, [right_b]}
{varexpr -> [id] ~, [colon]}
{varexpr -> [id] ~, [right_p]}
{varexpr -> [id] ~, [comma]}
{varexpr -> [id] ~, [right_c]}
{varexpr -> [id] ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State30:
	states.push(&&Goto30);
	switch(current_terminal->token()){
		case TOKEN_left_b: goto Shift31;
		case TOKEN_assignment: goto Reduce30;
		case TOKEN_dot: goto Reduce30;
		case TOKEN_left_p: goto Reduce30;
		case TOKEN_neq: goto Reduce30;
		case TOKEN_eq: goto Reduce30;
		case TOKEN_plus: goto Reduce30;
		case TOKEN_minus: goto Reduce30;
		case TOKEN_left_c: goto Reduce30;
		case TOKEN_right_b: goto Reduce30;
		case TOKEN_colon: goto Reduce30;
		case TOKEN_right_p: goto Reduce30;
		case TOKEN_comma: goto Reduce30;
		case TOKEN_right_c: goto Reduce30;
		case TOKEN_semicolon: goto Reduce30;
		default: goto ERROR;
	}

Goto30:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift31:
/*
{varexpr -> [id] [left_b] ~ expr [right_b], [assignment]}
{varexpr -> [id] [left_b] ~ expr [right_b], [dot]}
{varexpr -> [id] [left_b] ~ expr [right_b], [left_p]}
{varexpr -> [id] [left_b] ~ expr [right_b], [neq]}
{varexpr -> [id] [left_b] ~ expr [right_b], [eq]}
{varexpr -> [id] [left_b] ~ expr [right_b], [plus]}
{varexpr -> [id] [left_b] ~ expr [right_b], [minus]}
{varexpr -> [id] [left_b] ~ expr [right_b], [left_c]}
{varexpr -> [id] [left_b] ~ expr [right_b], [right_b]}
{varexpr -> [id] [left_b] ~ expr [right_b], [colon]}
{varexpr -> [id] [left_b] ~ expr [right_b], [right_p]}
{varexpr -> [id] [left_b] ~ expr [right_b], [comma]}
{varexpr -> [id] [left_b] ~ expr [right_b], [semicolon]}
{varexpr -> [id] [left_b] ~ expr [right_b], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State31:
	states.push(&&Goto31);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto31:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State32;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift32:
/*
{varexpr -> [id] [left_b] expr ~ [right_b], [assignment]}
{varexpr -> [id] [left_b] expr ~ [right_b], [dot]}
{varexpr -> [id] [left_b] expr ~ [right_b], [left_p]}
{varexpr -> [id] [left_b] expr ~ [right_b], [neq]}
{varexpr -> [id] [left_b] expr ~ [right_b], [eq]}
{varexpr -> [id] [left_b] expr ~ [right_b], [plus]}
{varexpr -> [id] [left_b] expr ~ [right_b], [minus]}
{varexpr -> [id] [left_b] expr ~ [right_b], [left_c]}
{varexpr -> [id] [left_b] expr ~ [right_b], [right_b]}
{varexpr -> [id] [left_b] expr ~ [right_b], [colon]}
{varexpr -> [id] [left_b] expr ~ [right_b], [right_p]}
{varexpr -> [id] [left_b] expr ~ [right_b], [comma]}
{varexpr -> [id] [left_b] expr ~ [right_b], [semicolon]}
{varexpr -> [id] [left_b] expr ~ [right_b], [right_c]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [right_b]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State32:
	states.push(&&Goto32);
	switch(current_terminal->token()){
		case TOKEN_right_b: goto Shift33;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto32:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift33:
/*
{varexpr -> [id] [left_b] expr [right_b] ~, [assignment]}
{varexpr -> [id] [left_b] expr [right_b] ~, [dot]}
{varexpr -> [id] [left_b] expr [right_b] ~, [left_p]}
{varexpr -> [id] [left_b] expr [right_b] ~, [neq]}
{varexpr -> [id] [left_b] expr [right_b] ~, [eq]}
{varexpr -> [id] [left_b] expr [right_b] ~, [plus]}
{varexpr -> [id] [left_b] expr [right_b] ~, [minus]}
{varexpr -> [id] [left_b] expr [right_b] ~, [left_c]}
{varexpr -> [id] [left_b] expr [right_b] ~, [right_b]}
{varexpr -> [id] [left_b] expr [right_b] ~, [colon]}
{varexpr -> [id] [left_b] expr [right_b] ~, [right_p]}
{varexpr -> [id] [left_b] expr [right_b] ~, [comma]}
{varexpr -> [id] [left_b] expr [right_b] ~, [semicolon]}
{varexpr -> [id] [left_b] expr [right_b] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State33:
	states.push(&&Goto33);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Reduce29;
		case TOKEN_dot: goto Reduce29;
		case TOKEN_left_p: goto Reduce29;
		case TOKEN_neq: goto Reduce29;
		case TOKEN_eq: goto Reduce29;
		case TOKEN_plus: goto Reduce29;
		case TOKEN_minus: goto Reduce29;
		case TOKEN_left_c: goto Reduce29;
		case TOKEN_right_b: goto Reduce29;
		case TOKEN_colon: goto Reduce29;
		case TOKEN_right_p: goto Reduce29;
		case TOKEN_comma: goto Reduce29;
		case TOKEN_semicolon: goto Reduce29;
		case TOKEN_right_c: goto Reduce29;
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
{closedStmt -> [while] ~ expr block, [right_c]}
{closedStmt -> [while] ~ expr block, [out]}
{closedStmt -> [while] ~ expr block, [in]}
{closedStmt -> [while] ~ expr block, [return]}
{closedStmt -> [while] ~ expr block, [id]}
{closedStmt -> [while] ~ expr block, [left_c]}
{closedStmt -> [while] ~ expr block, [int]}
{closedStmt -> [while] ~ expr block, [left_p]}
{closedStmt -> [while] ~ expr block, [if]}
{closedStmt -> [while] ~ expr block, [while]}
{closedStmt -> [while] ~ expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State34:
	states.push(&&Goto34);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto34:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State35;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift35:
/*
{closedStmt -> [while] expr ~ block, [right_c]}
{closedStmt -> [while] expr ~ block, [out]}
{closedStmt -> [while] expr ~ block, [in]}
{closedStmt -> [while] expr ~ block, [return]}
{closedStmt -> [while] expr ~ block, [id]}
{closedStmt -> [while] expr ~ block, [left_c]}
{closedStmt -> [while] expr ~ block, [int]}
{closedStmt -> [while] expr ~ block, [left_p]}
{closedStmt -> [while] expr ~ block, [if]}
{closedStmt -> [while] expr ~ block, [while]}
{closedStmt -> [while] expr ~ block, [for]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State35:
	states.push(&&Goto35);
	switch(current_terminal->token()){
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto35:
	switch(top_non_terminal){
		case SYMBOL_block: goto State36;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift36:
/*
{closedStmt -> [while] expr block ~, [right_c]}
{closedStmt -> [while] expr block ~, [out]}
{closedStmt -> [while] expr block ~, [in]}
{closedStmt -> [while] expr block ~, [return]}
{closedStmt -> [while] expr block ~, [id]}
{closedStmt -> [while] expr block ~, [left_c]}
{closedStmt -> [while] expr block ~, [int]}
{closedStmt -> [while] expr block ~, [left_p]}
{closedStmt -> [while] expr block ~, [if]}
{closedStmt -> [while] expr block ~, [while]}
{closedStmt -> [while] expr block ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State36:
	states.push(&&Goto36);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce34;
		case TOKEN_out: goto Reduce34;
		case TOKEN_in: goto Reduce34;
		case TOKEN_return: goto Reduce34;
		case TOKEN_id: goto Reduce34;
		case TOKEN_left_c: goto Reduce34;
		case TOKEN_int: goto Reduce34;
		case TOKEN_left_p: goto Reduce34;
		case TOKEN_if: goto Reduce34;
		case TOKEN_while: goto Reduce34;
		case TOKEN_for: goto Reduce34;
		default: goto ERROR;
	}

Goto36:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift37:
/*
{closedStmt -> [if] ~ expr block, [right_c]}
{closedStmt -> [if] ~ expr block, [out]}
{closedStmt -> [if] ~ expr block, [in]}
{closedStmt -> [if] ~ expr block, [return]}
{closedStmt -> [if] ~ expr block, [id]}
{closedStmt -> [if] ~ expr block, [left_c]}
{closedStmt -> [if] ~ expr block, [int]}
{closedStmt -> [if] ~ expr block, [left_p]}
{closedStmt -> [if] ~ expr block, [if]}
{closedStmt -> [if] ~ expr block, [while]}
{closedStmt -> [if] ~ expr block, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State37:
	states.push(&&Goto37);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto37:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State38;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift38:
/*
{closedStmt -> [if] expr ~ block, [right_c]}
{closedStmt -> [if] expr ~ block, [out]}
{closedStmt -> [if] expr ~ block, [in]}
{closedStmt -> [if] expr ~ block, [return]}
{closedStmt -> [if] expr ~ block, [id]}
{closedStmt -> [if] expr ~ block, [left_c]}
{closedStmt -> [if] expr ~ block, [int]}
{closedStmt -> [if] expr ~ block, [left_p]}
{closedStmt -> [if] expr ~ block, [if]}
{closedStmt -> [if] expr ~ block, [while]}
{closedStmt -> [if] expr ~ block, [for]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [left_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State38:
	states.push(&&Goto38);
	switch(current_terminal->token()){
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		case TOKEN_left_c: goto Shift12;
		default: goto ERROR;
	}

Goto38:
	switch(top_non_terminal){
		case SYMBOL_block: goto State39;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift39:
/*
{closedStmt -> [if] expr block ~, [right_c]}
{closedStmt -> [if] expr block ~, [out]}
{closedStmt -> [if] expr block ~, [in]}
{closedStmt -> [if] expr block ~, [return]}
{closedStmt -> [if] expr block ~, [id]}
{closedStmt -> [if] expr block ~, [left_c]}
{closedStmt -> [if] expr block ~, [int]}
{closedStmt -> [if] expr block ~, [left_p]}
{closedStmt -> [if] expr block ~, [if]}
{closedStmt -> [if] expr block ~, [while]}
{closedStmt -> [if] expr block ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State39:
	states.push(&&Goto39);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce33;
		case TOKEN_out: goto Reduce33;
		case TOKEN_in: goto Reduce33;
		case TOKEN_return: goto Reduce33;
		case TOKEN_id: goto Reduce33;
		case TOKEN_left_c: goto Reduce33;
		case TOKEN_int: goto Reduce33;
		case TOKEN_left_p: goto Reduce33;
		case TOKEN_if: goto Reduce33;
		case TOKEN_while: goto Reduce33;
		case TOKEN_for: goto Reduce33;
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
{dictblock -> [left_c] ~ pairs [right_c], [minus]}
{dictblock -> [left_c] ~ pairs [right_c], [plus]}
{dictblock -> [left_c] ~ pairs [right_c], [eq]}
{dictblock -> [left_c] ~ pairs [right_c], [neq]}
{dictblock -> [left_c] ~ pairs [right_c], [dot]}
{dictblock -> [left_c] ~ pairs [right_c], [semicolon]}
{dictblock -> [left_c] ~ pairs [right_c], [left_c]}
{dictblock -> [left_c] ~ pairs [right_c], [right_b]}
{dictblock -> [left_c] ~ pairs [right_c], [colon]}
{dictblock -> [left_c] ~ pairs [right_c], [right_p]}
{dictblock -> [left_c] ~ pairs [right_c], [comma]}
{dictblock -> [left_c] ~ pairs [right_c], [right_c]}
{dictblock -> [left_c] ~ [right_c], [minus]}
{dictblock -> [left_c] ~ [right_c], [plus]}
{dictblock -> [left_c] ~ [right_c], [eq]}
{dictblock -> [left_c] ~ [right_c], [neq]}
{dictblock -> [left_c] ~ [right_c], [dot]}
{dictblock -> [left_c] ~ [right_c], [semicolon]}
{dictblock -> [left_c] ~ [right_c], [left_c]}
{dictblock -> [left_c] ~ [right_c], [right_b]}
{dictblock -> [left_c] ~ [right_c], [colon]}
{dictblock -> [left_c] ~ [right_c], [right_p]}
{dictblock -> [left_c] ~ [right_c], [comma]}
{dictblock -> [left_c] ~ [right_c], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State40:
	states.push(&&Goto40);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Shift46;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto40:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State47;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_pairs: goto State42;
		case SYMBOL_pair: goto State41;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift41:
/*
{pairs -> pair ~, [right_c]}
{pairs -> pair ~, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State41:
	states.push(&&Goto41);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce53;
		case TOKEN_comma: goto Reduce53;
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
{dictblock -> [left_c] pairs ~ [right_c], [minus]}
{dictblock -> [left_c] pairs ~ [right_c], [plus]}
{dictblock -> [left_c] pairs ~ [right_c], [eq]}
{dictblock -> [left_c] pairs ~ [right_c], [neq]}
{dictblock -> [left_c] pairs ~ [right_c], [dot]}
{dictblock -> [left_c] pairs ~ [right_c], [semicolon]}
{dictblock -> [left_c] pairs ~ [right_c], [left_c]}
{dictblock -> [left_c] pairs ~ [right_c], [right_b]}
{dictblock -> [left_c] pairs ~ [right_c], [colon]}
{dictblock -> [left_c] pairs ~ [right_c], [right_p]}
{dictblock -> [left_c] pairs ~ [right_c], [comma]}
{dictblock -> [left_c] pairs ~ [right_c], [right_c]}
{pairs -> pairs ~ [comma] pairs, [right_c]}
{pairs -> pairs ~ [comma] pairs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State42:
	states.push(&&Goto42);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Shift43;
		case TOKEN_comma: goto Shift44;
		default: goto ERROR;
	}

Goto42:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift43:
/*
{dictblock -> [left_c] pairs [right_c] ~, [minus]}
{dictblock -> [left_c] pairs [right_c] ~, [plus]}
{dictblock -> [left_c] pairs [right_c] ~, [eq]}
{dictblock -> [left_c] pairs [right_c] ~, [neq]}
{dictblock -> [left_c] pairs [right_c] ~, [dot]}
{dictblock -> [left_c] pairs [right_c] ~, [semicolon]}
{dictblock -> [left_c] pairs [right_c] ~, [left_c]}
{dictblock -> [left_c] pairs [right_c] ~, [right_b]}
{dictblock -> [left_c] pairs [right_c] ~, [colon]}
{dictblock -> [left_c] pairs [right_c] ~, [right_p]}
{dictblock -> [left_c] pairs [right_c] ~, [comma]}
{dictblock -> [left_c] pairs [right_c] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State43:
	states.push(&&Goto43);
	switch(current_terminal->token()){
		case TOKEN_minus: goto Reduce50;
		case TOKEN_plus: goto Reduce50;
		case TOKEN_eq: goto Reduce50;
		case TOKEN_neq: goto Reduce50;
		case TOKEN_dot: goto Reduce50;
		case TOKEN_semicolon: goto Reduce50;
		case TOKEN_left_c: goto Reduce50;
		case TOKEN_right_b: goto Reduce50;
		case TOKEN_colon: goto Reduce50;
		case TOKEN_right_p: goto Reduce50;
		case TOKEN_comma: goto Reduce50;
		case TOKEN_right_c: goto Reduce50;
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
{pairs -> pairs [comma] ~ pairs, [right_c]}
{pairs -> pairs [comma] ~ pairs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State44:
	states.push(&&Goto44);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto44:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State47;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_pairs: goto State45;
		case SYMBOL_pair: goto State41;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift45:
/*
{pairs -> pairs [comma] pairs ~, [right_c]}
{pairs -> pairs [comma] pairs ~, [comma]}
{pairs -> pairs ~ [comma] pairs, [comma]}
{pairs -> pairs ~ [comma] pairs, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State45:
	states.push(&&Goto45);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce52;
		case TOKEN_comma: goto Reduce52;
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
{dictblock -> [left_c] [right_c] ~, [minus]}
{dictblock -> [left_c] [right_c] ~, [plus]}
{dictblock -> [left_c] [right_c] ~, [eq]}
{dictblock -> [left_c] [right_c] ~, [neq]}
{dictblock -> [left_c] [right_c] ~, [dot]}
{dictblock -> [left_c] [right_c] ~, [semicolon]}
{dictblock -> [left_c] [right_c] ~, [left_c]}
{dictblock -> [left_c] [right_c] ~, [right_b]}
{dictblock -> [left_c] [right_c] ~, [colon]}
{dictblock -> [left_c] [right_c] ~, [right_p]}
{dictblock -> [left_c] [right_c] ~, [comma]}
{dictblock -> [left_c] [right_c] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State46:
	states.push(&&Goto46);
	switch(current_terminal->token()){
		case TOKEN_minus: goto Reduce51;
		case TOKEN_plus: goto Reduce51;
		case TOKEN_eq: goto Reduce51;
		case TOKEN_neq: goto Reduce51;
		case TOKEN_dot: goto Reduce51;
		case TOKEN_semicolon: goto Reduce51;
		case TOKEN_left_c: goto Reduce51;
		case TOKEN_right_b: goto Reduce51;
		case TOKEN_colon: goto Reduce51;
		case TOKEN_right_p: goto Reduce51;
		case TOKEN_comma: goto Reduce51;
		case TOKEN_right_c: goto Reduce51;
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
{pair -> expr ~ [colon] expr, [right_c]}
{pair -> expr ~ [colon] expr, [comma]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [colon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State47:
	states.push(&&Goto47);
	switch(current_terminal->token()){
		case TOKEN_colon: goto Shift48;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
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
{pair -> expr [colon] ~ expr, [right_c]}
{pair -> expr [colon] ~ expr, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State48:
	states.push(&&Goto48);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto48:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State49;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift49:
/*
{pair -> expr [colon] expr ~, [right_c]}
{pair -> expr [colon] expr ~, [comma]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [comma]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [right_c]}
{varexpr -> expr ~ [dot] [id], [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State49:
	states.push(&&Goto49);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce54;
		case TOKEN_comma: goto Reduce54;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto49:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift50:
/*
{expr -> varexpr ~ argblock, [semicolon]}
{expr -> varexpr ~ argblock, [dot]}
{expr -> varexpr ~ argblock, [neq]}
{expr -> varexpr ~ argblock, [eq]}
{expr -> varexpr ~ argblock, [plus]}
{expr -> varexpr ~ argblock, [minus]}
{expr -> varexpr ~ argblock, [left_c]}
{expr -> varexpr ~ argblock, [right_b]}
{expr -> varexpr ~ argblock, [colon]}
{expr -> varexpr ~ argblock, [right_p]}
{expr -> varexpr ~ argblock, [comma]}
{expr -> varexpr ~ argblock, [right_c]}
{expr -> varexpr ~, [semicolon]}
{expr -> varexpr ~, [dot]}
{expr -> varexpr ~, [neq]}
{expr -> varexpr ~, [eq]}
{expr -> varexpr ~, [plus]}
{expr -> varexpr ~, [minus]}
{expr -> varexpr ~, [left_c]}
{expr -> varexpr ~, [right_b]}
{expr -> varexpr ~, [colon]}
{expr -> varexpr ~, [right_p]}
{expr -> varexpr ~, [comma]}
{expr -> varexpr ~, [right_c]}
{expr -> varexpr ~ [assignment] expr, [semicolon]}
{expr -> varexpr ~ [assignment] expr, [dot]}
{expr -> varexpr ~ [assignment] expr, [neq]}
{expr -> varexpr ~ [assignment] expr, [eq]}
{expr -> varexpr ~ [assignment] expr, [plus]}
{expr -> varexpr ~ [assignment] expr, [minus]}
{expr -> varexpr ~ [assignment] expr, [left_c]}
{expr -> varexpr ~ [assignment] expr, [right_b]}
{expr -> varexpr ~ [assignment] expr, [colon]}
{expr -> varexpr ~ [assignment] expr, [right_p]}
{expr -> varexpr ~ [assignment] expr, [comma]}
{expr -> varexpr ~ [assignment] expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State50:
	states.push(&&Goto50);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce62;
		case TOKEN_dot: goto Reduce62;
		case TOKEN_neq: goto Reduce62;
		case TOKEN_eq: goto Reduce62;
		case TOKEN_plus: goto Reduce62;
		case TOKEN_minus: goto Reduce62;
		case TOKEN_left_c: goto Reduce62;
		case TOKEN_right_b: goto Reduce62;
		case TOKEN_colon: goto Reduce62;
		case TOKEN_right_p: goto Reduce62;
		case TOKEN_comma: goto Reduce62;
		case TOKEN_right_c: goto Reduce62;
		case TOKEN_assignment: goto Shift60;
		case TOKEN_left_p: goto Shift52;
		default: goto ERROR;
	}

Goto50:
	switch(top_non_terminal){
		case SYMBOL_argblock: goto State51;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift51:
/*
{expr -> varexpr argblock ~, [semicolon]}
{expr -> varexpr argblock ~, [dot]}
{expr -> varexpr argblock ~, [neq]}
{expr -> varexpr argblock ~, [eq]}
{expr -> varexpr argblock ~, [plus]}
{expr -> varexpr argblock ~, [minus]}
{expr -> varexpr argblock ~, [left_c]}
{expr -> varexpr argblock ~, [right_b]}
{expr -> varexpr argblock ~, [colon]}
{expr -> varexpr argblock ~, [right_p]}
{expr -> varexpr argblock ~, [comma]}
{expr -> varexpr argblock ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State51:
	states.push(&&Goto51);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce61;
		case TOKEN_dot: goto Reduce61;
		case TOKEN_neq: goto Reduce61;
		case TOKEN_eq: goto Reduce61;
		case TOKEN_plus: goto Reduce61;
		case TOKEN_minus: goto Reduce61;
		case TOKEN_left_c: goto Reduce61;
		case TOKEN_right_b: goto Reduce61;
		case TOKEN_colon: goto Reduce61;
		case TOKEN_right_p: goto Reduce61;
		case TOKEN_comma: goto Reduce61;
		case TOKEN_right_c: goto Reduce61;
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
{argblock -> [left_p] ~ args [right_p], [semicolon]}
{argblock -> [left_p] ~ args [right_p], [dot]}
{argblock -> [left_p] ~ args [right_p], [neq]}
{argblock -> [left_p] ~ args [right_p], [eq]}
{argblock -> [left_p] ~ args [right_p], [plus]}
{argblock -> [left_p] ~ args [right_p], [minus]}
{argblock -> [left_p] ~ args [right_p], [left_c]}
{argblock -> [left_p] ~ args [right_p], [right_b]}
{argblock -> [left_p] ~ args [right_p], [colon]}
{argblock -> [left_p] ~ args [right_p], [right_p]}
{argblock -> [left_p] ~ args [right_p], [comma]}
{argblock -> [left_p] ~ args [right_p], [right_c]}
{argblock -> [left_p] ~ [right_p], [semicolon]}
{argblock -> [left_p] ~ [right_p], [dot]}
{argblock -> [left_p] ~ [right_p], [neq]}
{argblock -> [left_p] ~ [right_p], [eq]}
{argblock -> [left_p] ~ [right_p], [plus]}
{argblock -> [left_p] ~ [right_p], [minus]}
{argblock -> [left_p] ~ [right_p], [left_c]}
{argblock -> [left_p] ~ [right_p], [right_b]}
{argblock -> [left_p] ~ [right_p], [colon]}
{argblock -> [left_p] ~ [right_p], [right_p]}
{argblock -> [left_p] ~ [right_p], [comma]}
{argblock -> [left_p] ~ [right_p], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State52:
	states.push(&&Goto52);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift58;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto52:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State59;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_args: goto State56;
		case SYMBOL_arg: goto State53;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift53:
/*
{args -> arg ~ [comma] args, [right_p]}
{args -> arg ~, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State53:
	states.push(&&Goto53);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Shift54;
		case TOKEN_right_p: goto Reduce40;
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
{args -> arg [comma] ~ args, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State54:
	states.push(&&Goto54);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto54:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State59;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_args: goto State55;
		case SYMBOL_arg: goto State53;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift55:
/*
{args -> arg [comma] args ~, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State55:
	states.push(&&Goto55);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce39;
		default: goto ERROR;
	}

Goto55:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift56:
/*
{argblock -> [left_p] args ~ [right_p], [semicolon]}
{argblock -> [left_p] args ~ [right_p], [dot]}
{argblock -> [left_p] args ~ [right_p], [neq]}
{argblock -> [left_p] args ~ [right_p], [eq]}
{argblock -> [left_p] args ~ [right_p], [plus]}
{argblock -> [left_p] args ~ [right_p], [minus]}
{argblock -> [left_p] args ~ [right_p], [left_c]}
{argblock -> [left_p] args ~ [right_p], [right_b]}
{argblock -> [left_p] args ~ [right_p], [colon]}
{argblock -> [left_p] args ~ [right_p], [right_p]}
{argblock -> [left_p] args ~ [right_p], [comma]}
{argblock -> [left_p] args ~ [right_p], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State56:
	states.push(&&Goto56);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift57;
		default: goto ERROR;
	}

Goto56:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift57:
/*
{argblock -> [left_p] args [right_p] ~, [semicolon]}
{argblock -> [left_p] args [right_p] ~, [dot]}
{argblock -> [left_p] args [right_p] ~, [neq]}
{argblock -> [left_p] args [right_p] ~, [eq]}
{argblock -> [left_p] args [right_p] ~, [plus]}
{argblock -> [left_p] args [right_p] ~, [minus]}
{argblock -> [left_p] args [right_p] ~, [left_c]}
{argblock -> [left_p] args [right_p] ~, [right_b]}
{argblock -> [left_p] args [right_p] ~, [colon]}
{argblock -> [left_p] args [right_p] ~, [right_p]}
{argblock -> [left_p] args [right_p] ~, [comma]}
{argblock -> [left_p] args [right_p] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State57:
	states.push(&&Goto57);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce37;
		case TOKEN_dot: goto Reduce37;
		case TOKEN_neq: goto Reduce37;
		case TOKEN_eq: goto Reduce37;
		case TOKEN_plus: goto Reduce37;
		case TOKEN_minus: goto Reduce37;
		case TOKEN_left_c: goto Reduce37;
		case TOKEN_right_b: goto Reduce37;
		case TOKEN_colon: goto Reduce37;
		case TOKEN_right_p: goto Reduce37;
		case TOKEN_comma: goto Reduce37;
		case TOKEN_right_c: goto Reduce37;
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
{argblock -> [left_p] [right_p] ~, [semicolon]}
{argblock -> [left_p] [right_p] ~, [dot]}
{argblock -> [left_p] [right_p] ~, [neq]}
{argblock -> [left_p] [right_p] ~, [eq]}
{argblock -> [left_p] [right_p] ~, [plus]}
{argblock -> [left_p] [right_p] ~, [minus]}
{argblock -> [left_p] [right_p] ~, [left_c]}
{argblock -> [left_p] [right_p] ~, [right_b]}
{argblock -> [left_p] [right_p] ~, [colon]}
{argblock -> [left_p] [right_p] ~, [right_p]}
{argblock -> [left_p] [right_p] ~, [comma]}
{argblock -> [left_p] [right_p] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State58:
	states.push(&&Goto58);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce38;
		case TOKEN_dot: goto Reduce38;
		case TOKEN_neq: goto Reduce38;
		case TOKEN_eq: goto Reduce38;
		case TOKEN_plus: goto Reduce38;
		case TOKEN_minus: goto Reduce38;
		case TOKEN_left_c: goto Reduce38;
		case TOKEN_right_b: goto Reduce38;
		case TOKEN_colon: goto Reduce38;
		case TOKEN_right_p: goto Reduce38;
		case TOKEN_comma: goto Reduce38;
		case TOKEN_right_c: goto Reduce38;
		default: goto ERROR;
	}

Goto58:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift59:
/*
{arg -> expr ~, [right_p]}
{arg -> expr ~, [comma]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [comma]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State59:
	states.push(&&Goto59);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce41;
		case TOKEN_comma: goto Reduce41;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto59:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift60:
/*
{expr -> varexpr [assignment] ~ expr, [semicolon]}
{expr -> varexpr [assignment] ~ expr, [dot]}
{expr -> varexpr [assignment] ~ expr, [neq]}
{expr -> varexpr [assignment] ~ expr, [eq]}
{expr -> varexpr [assignment] ~ expr, [plus]}
{expr -> varexpr [assignment] ~ expr, [minus]}
{expr -> varexpr [assignment] ~ expr, [left_c]}
{expr -> varexpr [assignment] ~ expr, [right_b]}
{expr -> varexpr [assignment] ~ expr, [colon]}
{expr -> varexpr [assignment] ~ expr, [right_p]}
{expr -> varexpr [assignment] ~ expr, [comma]}
{expr -> varexpr [assignment] ~ expr, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State60:
	states.push(&&Goto60);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto60:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State61;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift61:
/*
{expr -> varexpr [assignment] expr ~, [semicolon]}
{expr -> varexpr [assignment] expr ~, [dot]}
{expr -> varexpr [assignment] expr ~, [neq]}
{expr -> varexpr [assignment] expr ~, [eq]}
{expr -> varexpr [assignment] expr ~, [plus]}
{expr -> varexpr [assignment] expr ~, [minus]}
{expr -> varexpr [assignment] expr ~, [left_c]}
{expr -> varexpr [assignment] expr ~, [right_b]}
{expr -> varexpr [assignment] expr ~, [colon]}
{expr -> varexpr [assignment] expr ~, [right_p]}
{expr -> varexpr [assignment] expr ~, [comma]}
{expr -> varexpr [assignment] expr ~, [right_c]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [left_c]}
{expr -> expr ~ [minus] expr, [right_b]}
{expr -> expr ~ [minus] expr, [colon]}
{expr -> expr ~ [minus] expr, [right_p]}
{expr -> expr ~ [minus] expr, [comma]}
{expr -> expr ~ [minus] expr, [right_c]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [left_c]}
{expr -> expr ~ [plus] expr, [right_b]}
{expr -> expr ~ [plus] expr, [colon]}
{expr -> expr ~ [plus] expr, [right_p]}
{expr -> expr ~ [plus] expr, [comma]}
{expr -> expr ~ [plus] expr, [right_c]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [left_c]}
{expr -> expr ~ [eq] expr, [right_b]}
{expr -> expr ~ [eq] expr, [colon]}
{expr -> expr ~ [eq] expr, [right_p]}
{expr -> expr ~ [eq] expr, [comma]}
{expr -> expr ~ [eq] expr, [right_c]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [left_c]}
{expr -> expr ~ [neq] expr, [right_b]}
{expr -> expr ~ [neq] expr, [colon]}
{expr -> expr ~ [neq] expr, [right_p]}
{expr -> expr ~ [neq] expr, [comma]}
{expr -> expr ~ [neq] expr, [right_c]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
{varexpr -> expr ~ [dot] [id], [left_c]}
{varexpr -> expr ~ [dot] [id], [right_b]}
{varexpr -> expr ~ [dot] [id], [colon]}
{varexpr -> expr ~ [dot] [id], [right_p]}
{varexpr -> expr ~ [dot] [id], [comma]}
{varexpr -> expr ~ [dot] [id], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State61:
	states.push(&&Goto61);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce63;
		case TOKEN_left_c: goto Reduce63;
		case TOKEN_right_b: goto Reduce63;
		case TOKEN_colon: goto Reduce63;
		case TOKEN_right_p: goto Reduce63;
		case TOKEN_comma: goto Reduce63;
		case TOKEN_right_c: goto Reduce63;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto61:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift62:
/*
{tuprefblock -> [left_p] ~ tuprefs [right_p], [assignment]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State62:
	states.push(&&Goto62);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift67;
		default: goto ERROR;
	}

Goto62:
	switch(top_non_terminal){
		case SYMBOL_tuprefs: goto State63;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift63:
/*
{tuprefblock -> [left_p] tuprefs ~ [right_p], [assignment]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [right_p]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State63:
	states.push(&&Goto63);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Shift66;
		case TOKEN_comma: goto Shift64;
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
{tuprefs -> tuprefs [comma] ~ tuprefs, [right_p]}
{tuprefs -> tuprefs [comma] ~ tuprefs, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State64:
	states.push(&&Goto64);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift67;
		default: goto ERROR;
	}

Goto64:
	switch(top_non_terminal){
		case SYMBOL_tuprefs: goto State65;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift65:
/*
{tuprefs -> tuprefs [comma] tuprefs ~, [right_p]}
{tuprefs -> tuprefs [comma] tuprefs ~, [comma]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [comma]}
{tuprefs -> tuprefs ~ [comma] tuprefs, [right_p]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State65:
	states.push(&&Goto65);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce48;
		case TOKEN_comma: goto Reduce48;
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
{tuprefblock -> [left_p] tuprefs [right_p] ~, [assignment]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State66:
	states.push(&&Goto66);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Reduce47;
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
{tuprefs -> [id] ~, [right_p]}
{tuprefs -> [id] ~, [comma]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State67:
	states.push(&&Goto67);
	switch(current_terminal->token()){
		case TOKEN_right_p: goto Reduce49;
		case TOKEN_comma: goto Reduce49;
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
{stmt -> tuprefblock ~ [assignment] expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State68:
	states.push(&&Goto68);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Shift69;
		default: goto ERROR;
	}

Goto68:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift69:
/*
{stmt -> tuprefblock [assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State69:
	states.push(&&Goto69);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto69:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State70;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift70:
/*
{stmt -> tuprefblock [assignment] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State70:
	states.push(&&Goto70);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce17;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
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
{stmt -> expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [neq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State71:
	states.push(&&Goto71);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce16;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
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
{stmt -> varDecl ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State72:
	states.push(&&Goto72);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce15;
		default: goto ERROR;
	}

Goto72:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift73:
/*
{stmt -> [return] ~ returnStmt, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State73:
	states.push(&&Goto73);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto73:
	switch(top_non_terminal){
		case SYMBOL_returnStmt: goto State75;
		case SYMBOL_expr: goto State74;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift74:
/*
{returnStmt -> expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State74:
	states.push(&&Goto74);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce26;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto74:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift75:
/*
{stmt -> [return] returnStmt ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State75:
	states.push(&&Goto75);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce14;
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
{stmt -> [in] ~ inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State76:
	states.push(&&Goto76);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift80;
		default: goto ERROR;
	}

Goto76:
	switch(top_non_terminal){
		case SYMBOL_inDecl: goto State77;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift77:
/*
{stmt -> [in] inDecl ~, [semicolon]}
{inDecl -> inDecl ~ [comma] inDecl, [comma]}
{inDecl -> inDecl ~ [comma] inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State77:
	states.push(&&Goto77);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce13;
		case TOKEN_comma: goto Shift78;
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
{inDecl -> inDecl [comma] ~ inDecl, [comma]}
{inDecl -> inDecl [comma] ~ inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State78:
	states.push(&&Goto78);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift80;
		default: goto ERROR;
	}

Goto78:
	switch(top_non_terminal){
		case SYMBOL_inDecl: goto State79;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift79:
/*
{inDecl -> inDecl [comma] inDecl ~, [comma]}
{inDecl -> inDecl [comma] inDecl ~, [semicolon]}
{inDecl -> inDecl ~ [comma] inDecl, [comma]}
{inDecl -> inDecl ~ [comma] inDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State79:
	states.push(&&Goto79);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Reduce24;
		case TOKEN_semicolon: goto Reduce24;
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
{inDecl -> [id] ~, [comma]}
{inDecl -> [id] ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State80:
	states.push(&&Goto80);
	switch(current_terminal->token()){
		case TOKEN_comma: goto Reduce25;
		case TOKEN_semicolon: goto Reduce25;
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
{stmt -> [out] ~ outDecl, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State81:
	states.push(&&Goto81);
	switch(current_terminal->token()){
		case TOKEN_id: goto Shift83;
		default: goto ERROR;
	}

Goto81:
	switch(top_non_terminal){
		case SYMBOL_outDecl: goto State82;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift82:
/*
{stmt -> [out] outDecl ~, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State82:
	states.push(&&Goto82);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce12;
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
{outDecl -> [id] ~ [assignment] expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State83:
	states.push(&&Goto83);
	switch(current_terminal->token()){
		case TOKEN_assignment: goto Shift84;
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
{outDecl -> [id] [assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State84:
	states.push(&&Goto84);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto84:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State85;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift85:
/*
{outDecl -> [id] [assignment] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State85:
	states.push(&&Goto85);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce23;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
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
{stmts -> closedStmt ~ stmts, [right_c]}
{stmts -> closedStmt ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State86:
	states.push(&&Goto86);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce11;
		case TOKEN_if: goto Shift37;
		case TOKEN_while: goto Shift34;
		case TOKEN_for: goto Shift15;
		case TOKEN_out: goto Shift81;
		case TOKEN_in: goto Shift76;
		case TOKEN_return: goto Shift73;
		case TOKEN_left_p: goto Shift62;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift93;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto86:
	switch(top_non_terminal){
		case SYMBOL_stmts: goto State87;
		case SYMBOL_stmt: goto State88;
		case SYMBOL_closedStmt: goto State86;
		case SYMBOL_varDecl: goto State72;
		case SYMBOL_expr: goto State71;
		case SYMBOL_tuprefblock: goto State68;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift87:
/*
{stmts -> closedStmt stmts ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State87:
	states.push(&&Goto87);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce9;
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
{stmts -> stmt ~ [semicolon] stmts, [right_c]}
{stmts -> stmt ~ [semicolon], [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State88:
	states.push(&&Goto88);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Shift89;
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
{stmts -> stmt [semicolon] ~ stmts, [right_c]}
{stmts -> stmt [semicolon] ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State89:
	states.push(&&Goto89);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce10;
		case TOKEN_if: goto Shift37;
		case TOKEN_while: goto Shift34;
		case TOKEN_for: goto Shift15;
		case TOKEN_out: goto Shift81;
		case TOKEN_in: goto Shift76;
		case TOKEN_return: goto Shift73;
		case TOKEN_left_p: goto Shift62;
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift93;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto89:
	switch(top_non_terminal){
		case SYMBOL_stmts: goto State90;
		case SYMBOL_stmt: goto State88;
		case SYMBOL_closedStmt: goto State86;
		case SYMBOL_varDecl: goto State72;
		case SYMBOL_expr: goto State71;
		case SYMBOL_tuprefblock: goto State68;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift90:
/*
{stmts -> stmt [semicolon] stmts ~, [right_c]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State90:
	states.push(&&Goto90);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Reduce8;
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
{block -> [left_c] stmts ~ [right_c], [def]}
{block -> [left_c] stmts ~ [right_c], [EOF]}
{block -> [left_c] stmts ~ [right_c], [right_c]}
{block -> [left_c] stmts ~ [right_c], [out]}
{block -> [left_c] stmts ~ [right_c], [in]}
{block -> [left_c] stmts ~ [right_c], [return]}
{block -> [left_c] stmts ~ [right_c], [id]}
{block -> [left_c] stmts ~ [right_c], [left_c]}
{block -> [left_c] stmts ~ [right_c], [int]}
{block -> [left_c] stmts ~ [right_c], [left_p]}
{block -> [left_c] stmts ~ [right_c], [if]}
{block -> [left_c] stmts ~ [right_c], [while]}
{block -> [left_c] stmts ~ [right_c], [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State91:
	states.push(&&Goto91);
	switch(current_terminal->token()){
		case TOKEN_right_c: goto Shift92;
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
{block -> [left_c] stmts [right_c] ~, [def]}
{block -> [left_c] stmts [right_c] ~, [EOF]}
{block -> [left_c] stmts [right_c] ~, [right_c]}
{block -> [left_c] stmts [right_c] ~, [out]}
{block -> [left_c] stmts [right_c] ~, [in]}
{block -> [left_c] stmts [right_c] ~, [return]}
{block -> [left_c] stmts [right_c] ~, [id]}
{block -> [left_c] stmts [right_c] ~, [left_c]}
{block -> [left_c] stmts [right_c] ~, [int]}
{block -> [left_c] stmts [right_c] ~, [left_p]}
{block -> [left_c] stmts [right_c] ~, [if]}
{block -> [left_c] stmts [right_c] ~, [while]}
{block -> [left_c] stmts [right_c] ~, [for]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State92:
	states.push(&&Goto92);
	switch(current_terminal->token()){
		case TOKEN_def: goto Reduce32;
		case TOKEN_EOF: goto Reduce32;
		case TOKEN_right_c: goto Reduce32;
		case TOKEN_out: goto Reduce32;
		case TOKEN_in: goto Reduce32;
		case TOKEN_return: goto Reduce32;
		case TOKEN_id: goto Reduce32;
		case TOKEN_left_c: goto Reduce32;
		case TOKEN_int: goto Reduce32;
		case TOKEN_left_p: goto Reduce32;
		case TOKEN_if: goto Reduce32;
		case TOKEN_while: goto Reduce32;
		case TOKEN_for: goto Reduce32;
		default: goto ERROR;
	}

Goto92:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift93:
/*
{varexpr -> [id] ~ [left_b] expr [right_b], [assignment]}
{varexpr -> [id] ~ [left_b] expr [right_b], [dot]}
{varexpr -> [id] ~ [left_b] expr [right_b], [left_p]}
{varexpr -> [id] ~ [left_b] expr [right_b], [neq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [eq]}
{varexpr -> [id] ~ [left_b] expr [right_b], [plus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [minus]}
{varexpr -> [id] ~ [left_b] expr [right_b], [semicolon]}
{varexpr -> [id] ~, [assignment]}
{varexpr -> [id] ~, [dot]}
{varexpr -> [id] ~, [left_p]}
{varexpr -> [id] ~, [neq]}
{varexpr -> [id] ~, [eq]}
{varexpr -> [id] ~, [plus]}
{varexpr -> [id] ~, [minus]}
{varexpr -> [id] ~, [semicolon]}
{varDecl -> [id] ~, [semicolon]}
{varDecl -> [id] ~ [assignment] expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State93:
	states.push(&&Goto93);
	switch(current_terminal->token()){
		case TOKEN_left_b: goto Shift31;
		case TOKEN_dot: goto Reduce30;
		case TOKEN_left_p: goto Reduce30;
		case TOKEN_neq: goto Reduce30;
		case TOKEN_eq: goto Reduce30;
		case TOKEN_plus: goto Reduce30;
		case TOKEN_minus: goto Reduce30;
		case TOKEN_semicolon: goto Reduce27;
		case TOKEN_assignment: goto Shift94;
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
{varDecl -> [id] [assignment] ~ expr, [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State94:
	states.push(&&Goto94);
	switch(current_terminal->token()){
		case TOKEN_int: goto Shift13;
		case TOKEN_id: goto Shift30;
		case TOKEN_left_c: goto Shift40;
		default: goto ERROR;
	}

Goto94:
	switch(top_non_terminal){
		case SYMBOL_expr: goto State95;
		case SYMBOL_varexpr: goto State50;
		case SYMBOL_dictblock: goto State14;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift95:
/*
{varDecl -> [id] [assignment] expr ~, [semicolon]}
{expr -> expr ~ [minus] expr, [dot]}
{expr -> expr ~ [minus] expr, [neq]}
{expr -> expr ~ [minus] expr, [eq]}
{expr -> expr ~ [minus] expr, [plus]}
{expr -> expr ~ [minus] expr, [minus]}
{expr -> expr ~ [minus] expr, [semicolon]}
{expr -> expr ~ [plus] expr, [dot]}
{expr -> expr ~ [plus] expr, [neq]}
{expr -> expr ~ [plus] expr, [eq]}
{expr -> expr ~ [plus] expr, [plus]}
{expr -> expr ~ [plus] expr, [minus]}
{expr -> expr ~ [plus] expr, [semicolon]}
{expr -> expr ~ [eq] expr, [dot]}
{expr -> expr ~ [eq] expr, [neq]}
{expr -> expr ~ [eq] expr, [eq]}
{expr -> expr ~ [eq] expr, [plus]}
{expr -> expr ~ [eq] expr, [minus]}
{expr -> expr ~ [eq] expr, [semicolon]}
{expr -> expr ~ [neq] expr, [dot]}
{expr -> expr ~ [neq] expr, [neq]}
{expr -> expr ~ [neq] expr, [eq]}
{expr -> expr ~ [neq] expr, [plus]}
{expr -> expr ~ [neq] expr, [minus]}
{expr -> expr ~ [neq] expr, [semicolon]}
{varexpr -> expr ~ [dot] [id], [assignment]}
{varexpr -> expr ~ [dot] [id], [dot]}
{varexpr -> expr ~ [dot] [id], [left_p]}
{varexpr -> expr ~ [dot] [id], [neq]}
{varexpr -> expr ~ [dot] [id], [eq]}
{varexpr -> expr ~ [dot] [id], [plus]}
{varexpr -> expr ~ [dot] [id], [minus]}
{varexpr -> expr ~ [dot] [id], [semicolon]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State95:
	states.push(&&Goto95);
	switch(current_terminal->token()){
		case TOKEN_semicolon: goto Reduce28;
		case TOKEN_minus: goto Shift25;
		case TOKEN_plus: goto Shift23;
		case TOKEN_eq: goto Shift21;
		case TOKEN_neq: goto Shift19;
		case TOKEN_dot: goto Shift27;
		default: goto ERROR;
	}

Goto95:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift96:
/*
{method -> [def] [id] paramsblock block ~, [def]}
{method -> [def] [id] paramsblock block ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State96:
	states.push(&&Goto96);
	switch(current_terminal->token()){
		case TOKEN_def: goto Reduce7;
		case TOKEN_EOF: goto Reduce7;
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
{top_def -> method ~, [def]}
{top_def -> method ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State97:
	states.push(&&Goto97);
	switch(current_terminal->token()){
		case TOKEN_def: goto Reduce6;
		case TOKEN_EOF: goto Reduce6;
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
{top_defs -> top_def ~ top_defs, [EOF]}
{top_defs -> top_def ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State98:
	states.push(&&Goto98);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce5;
		case TOKEN_def: goto Shift1;
		default: goto ERROR;
	}

Goto98:
	switch(top_non_terminal){
		case SYMBOL_top_defs: goto State99;
		case SYMBOL_top_def: goto State98;
		case SYMBOL_method: goto State97;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift99:
/*
{top_defs -> top_def top_defs ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State99:
	states.push(&&Goto99);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce4;
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
{program -> [error] ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State100:
	states.push(&&Goto100);
Switch100:
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce3;
		default:
			((ErrorTerminal*)symbols.top())->discard(current_terminal);
			current_terminal = lexer->nextToken();
			goto Switch100;
	}

Goto100:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift101:
/*
{program -> top_defs ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State101:
	states.push(&&Goto101);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce2;
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
{program -> [newline] ~ top_defs, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State102:
	states.push(&&Goto102);
	switch(current_terminal->token()){
		case TOKEN_def: goto Shift1;
		default: goto ERROR;
	}

Goto102:
	switch(top_non_terminal){
		case SYMBOL_top_defs: goto State103;
		case SYMBOL_top_def: goto State98;
		case SYMBOL_method: goto State97;
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift103:
/*
{program -> [newline] top_defs ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State103:
	states.push(&&Goto103);
	switch(current_terminal->token()){
		case TOKEN_EOF: goto Reduce1;
		default: goto ERROR;
	}

Goto103:
	switch(top_non_terminal){
		case SYMBOL_error:
			states.pop();
			symbols.pop();
			goto *states.top();
		default: goto FATAL_ERROR;
	}

Shift104:
/*
{root -> program ~, [EOF]}
*/
	symbols.push(current_terminal);
	current_terminal = lexer->nextToken();
State104:
	states.push(&&Goto104);
	switch(current_terminal->token()){
		case TOKEN_EOF: return symbols.top();
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

Reduce15: //stmt -> varDecl
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE varDecl Stmt"<<endl;result = arg0;
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_stmt;
	goto *states.top();

Reduce16: //stmt -> expr
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

Reduce17: //stmt -> tuprefblock [assignment] expr
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

Reduce26: //returnStmt -> expr
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

Reduce27: //varDecl -> [id]
	arg0 = symbols.top();
	symbols.pop();
	states.pop();
	result = NULL;
	{
	cerr<<"PARSE id"<<endl;result = new NodeVardeclStmt(NULL,(Identifier*)arg0, NULL, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varDecl;
	goto *states.top();

Reduce28: //varDecl -> [id] [assignment] expr
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
	cerr<<"PARSE id assignment expr"<<endl;result = new NodeVardeclStmt(NULL, (Identifier*)arg0,(NodeExpr*)arg2, NULL);
	}
	symbols.push(result);
	top_non_terminal = SYMBOL_varDecl;
	goto *states.top();

Reduce29: //varexpr -> [id] [left_b] expr [right_b]
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

Reduce30: //varexpr -> [id]
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

Reduce31: //varexpr -> expr [dot] [id]
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

Reduce32: //block -> [left_c] stmts [right_c]
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

Reduce33: //closedStmt -> [if] expr block
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

Reduce34: //closedStmt -> [while] expr block
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

Reduce35: //closedStmt -> [for] [id] [in] expr block
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

Reduce36: //type -> [id]
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

Reduce37: //argblock -> [left_p] args [right_p]
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

Reduce38: //argblock -> [left_p] [right_p]
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

Reduce39: //args -> arg [comma] args
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

Reduce40: //args -> arg
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

Reduce41: //arg -> expr
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

Reduce42: //tupblock -> [left_p] tups [right_p]
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

Reduce43: //tupblock -> [left_p] [right_p]
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

Reduce44: //tups -> tup [comma] tups
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

Reduce45: //tups -> tup
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

Reduce46: //tup -> expr
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

Reduce47: //tuprefblock -> [left_p] tuprefs [right_p]
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

Reduce48: //tuprefs -> tuprefs [comma] tuprefs
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

Reduce49: //tuprefs -> [id]
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

Reduce50: //dictblock -> [left_c] pairs [right_c]
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

Reduce51: //dictblock -> [left_c] [right_c]
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

Reduce52: //pairs -> pairs [comma] pairs
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

Reduce53: //pairs -> pair
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

Reduce54: //pair -> expr [colon] expr
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

Reduce55: //expr -> dictblock
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

Reduce56: //expr -> expr [minus] expr
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

Reduce57: //expr -> expr [plus] expr
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

Reduce58: //expr -> expr [eq] expr
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

Reduce59: //expr -> expr [neq] expr
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

Reduce60: //expr -> [int]
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

Reduce61: //expr -> varexpr argblock
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

Reduce62: //expr -> varexpr
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

Reduce63: //expr -> varexpr [assignment] expr
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
	cerr<<"PARSE varexpr assignment expr"<<endl; result = new NodeAssignExpr((NodeVariable*)arg0, (NodeExpr*)arg2);
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
		case TOKEN_left_b: return "left_b";
		case TOKEN_right_b: return "right_b";
		case TOKEN_dot: return "dot";
		case TOKEN_left_c: return "left_c";
		case TOKEN_right_c: return "right_c";
		case TOKEN_if: return "if";
		case TOKEN_while: return "while";
		case TOKEN_for: return "for";
		case TOKEN_colon: return "colon";
		case TOKEN_minus: return "minus";
		case TOKEN_plus: return "plus";
		case TOKEN_eq: return "eq";
		case TOKEN_neq: return "neq";
		case TOKEN_int: return "int";
		default: return "Unknown token";
	}
}


