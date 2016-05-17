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
	TOKEN_plus_assignment,
	TOKEN_minus_assignment,
	TOKEN_multiply_assignment,
	TOKEN_division_assignment,
	TOKEN_bitand_assignment,
	TOKEN_bitor_assignment,
	TOKEN_left_b,
	TOKEN_right_b,
	TOKEN_dot,
	TOKEN_left_c,
	TOKEN_right_c,
	TOKEN_if,
	TOKEN_while,
	TOKEN_for,
	TOKEN_colon,
	TOKEN_not,
	TOKEN_multiply,
	TOKEN_division,
	TOKEN_modulo,
	TOKEN_minus,
	TOKEN_plus,
	TOKEN_leeq,
	TOKEN_le,
	TOKEN_gteq,
	TOKEN_gt,
	TOKEN_eq,
	TOKEN_neq,
	TOKEN_bitand,
	TOKEN_bitor,
	TOKEN_and,
	TOKEN_or,
	TOKEN_int
};


string TokenToString(Token token);

#endif /* PARSER_H */
