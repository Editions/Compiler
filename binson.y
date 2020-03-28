
%{
#include"globals.h"
%}
%token NUM
%%

program              : declaration_list
                     ;
declaration_list     : declaration_list declaration
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
