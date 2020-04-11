
%{
#include"globals.h"
%}
%token PLUS,MINUS,MULTI,DIVIDE,
%token LESS,LESSEQUAL,MORE,MOREEQUAL,EQUAL,NOTEQUAL,
%token ASSIGN,
%token SEMI,COMMA,
%token LPAREN,RPAREN,LBRACE,RBRACE,LBRACKET,RBRACKET,LCOMM,RCOMM,
%token IF,ELSE,INT,RETURN,VOID,WHILE,
%token ID,NUM
%%

program              : declaration_list                         {$$ = $1;}
                     ;
declaration_list     : declaration_list declaration             {$$ = S1;}
                     | declaration                              
                     ;
declaration          : var_declaration
                     | fun_declaration
                     ;
var_declaration      : type_specifier ID ';'
                     | type_specifier ID '['NUM'] ';'
                     ;
type_specifier
fun_declaration
params
param_list
param
compound_stmt
local_declarations
statement_list
statement
expression_stmt
iteration_stmt
return_stmt
expression_stmt
var
simple_expression
relop
additive_expression
addop 
term
mulop 
factor 
call
args 
arg_list
%%
