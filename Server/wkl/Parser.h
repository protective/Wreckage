#ifndef PARSER_H
#define PARSER_H
class Lexer;
class Node;

Node* parse(Lexer* lex);

enum Token{
	TOKEN_error,
	TOKEN_EOF,
	TOKEN_newline,
	TOKEN_def,
	TOKEN_id,
	TOKEN_semicolon,
	TOKEN_out,
	TOKEN_in,
	TOKEN_return,
	TOKEN_assignment,
	TOKEN_left_p,
	TOKEN_right_p,
	TOKEN_comma,
	TOKEN_dot,
	TOKEN_left_c,
	TOKEN_right_c,
	TOKEN_if,
	TOKEN_while,
	TOKEN_for,
	TOKEN_minus,
	TOKEN_plus,
	TOKEN_int
};


string TokenToString(Token token);

#endif /* PARSER_H */
