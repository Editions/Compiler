%{
#include"globals.h"

#define YYSTYPE TreeNode*
static TreeNode* root;
}
%start program // 开始符号

%union{
    int num;   // 属性值
    char* id;  // 标识符
    int type;  // +-*/ (0123)
}
%token VOID INT
%token IF ELSE
%token WHILE
%token RETURN
%token ASSIGN
%token SEMI COMMA,
%token LBRACE RBRACE LBRACKET RBRACKET
%token LCOMM RCOMM 

%token <id>ID 
%token <num>NUM

// 指导书标明无结合性
// %left '<=' '<' '>' '>=' '==' '!='  
%token LESS LESSEQUAL MORE MOREEQUAL EQUAL NOTEQUAL

%left PLUS MINUS
%left MULTI DIVIDE
%left LPAREN RPAREN

%%

program                 : declaration_list  {root = $1;}
                        ;
declaration_list        : declaration_list declaration  { YYSTYPE t = $1;
                                                          while(t->sibling) t = t->sibling;
                                                          t->sibling = $2;
                                                          $$ = t;
                                                        }
                        | declaration  {$$ = $1;}          
                       idid
declaration             : var_declaration  {$$ = $1;}
                        | fun_declaration  {$$ = $1;}
                        ;
var_declaration         : type_specifier ID SEMI {  $$ = $1; 
                                                    $$->name = id;
                                                    type_check(id, $$->type, INT);
                                                 }
                        | type_specifier ID LBRACKET NUM RBRACKET SEMI  {  $$ = $1;
                                                                           $$->name = id;
                                                                           $$->array_len = val;
                                                                           type_check(id, $$->type, INT);
                                                                        }
                        ;
type_specifier          : INT  {$$ = new TreeNode(); $$->type = INT;}
                        | VOID {$$ = new TreeNode(); $$->type = VOID;}
                        ;
fun_declaration         : type_specifier ID LPAREN params RPAREN compound_stmt  
                            {   $$ = $1;
                                $$ -> name = id;
                                $$ -> child[0] = $4;
                                $$ -> child[1] = $6;
                                type_check(id, $$->type, VOID);
                            }
                        ;
params                  : param_list  { $$ = $1;}
                        | param  {$$ = $1;}
                        ;
param_list              : param_list COMMA param {  YYSTYPE t = $1; 
                                                    while(t->sibling) t = t->sibling;
                                                    t->sibling = $3;
                                                    $$ = t;
                                                 }
                        | param { $$ = $1;}
                        ;
param                   : type_specifier ID {   $$ = $1; 
                                                $$->name = id; 
                                                type_check(id, $$->type, INT);
                                            } 
                        | type_specifier ID LBRACKET RBRACKET 
                        {   $$->$1; 
                            $$->name = id;
                            $$->array_len = -1;
                            type_check(id, $$->type, INT);
                        }
                        ;
compound_stmt           : LBRACE local_declarations statement_list RBRACE
                        {   $$ = new TreeNode();
                            $$->child[0] = $1;
                            $$->child[1] = $2;
                        }
                        ;
local_declarations      : local_declarations var_declaration 
                        {   if($1 == NULL){
                                $$ = $1;
                            }
                            elseYYSTYPE t = $1;
                            while(t->sibling) t=t->sibling;
                            t->sibling = $2;

                        }
                        |    { $$ = NULL; }//empty /////////////////
                        ;
statement_list          : statement_list statement
                        | empty  /////////////
                        ;
statement               : expression_stmt
                        | compound_stmt
                        | selection-stmt
                        | iteration_stmt
                        | return_stmt
                        ;
expression_stmt         : expression_stmt SEMI
                        | SEMI
                        ;
selection-stmt          : IF LPAREN expression RPAREN statement
                        | IF LPAREN expression RPAREN ELSE statement
                        ;
iteration_stmt          : WHILE LPAREN expression RPAREN statement
                        ;
return_stmt             : RETURN SEMI
                        | RETURN expression SEMI
                        ;
expression_stmt         : var ASSIGN expression
                        | simple_expression
                        ;
var                     : ID
                        | ID LBRACKET expression RBRACKET
                        ;
simple_expression       : additive_expression relop additive_expression
                        | additive_expression
                        ;
relop                   : LESS
                        | LESSEQUAL
                        | MORE
                        | MOREEQUAL
                        | EQUAL
                        | NOTEQUAL
                        ;
additive_expression     : additive_expression addop term
                        | term
                        ;
addop                   : PLUS
                        | MINUS
                        ;
term                    : term mulop factor 
                        | factor   
                        ;
mulop                   : MULTI
                        | DIVIDE
                        ;
factor                  : LPAREN expression RPAREN
                        | var
                        | call
                        | NUM
                        ;
call                    : ID LPAREN args RPAREN
                        ;
arg                     : arg_list
                        | empty //////////
                        ;
arg_list                : arg_list COMMA expression
                        | expression
                        ;
                  

%%

void type_check(char* val, ValType type, ValType correct_type)
{
    if(correct_type == type) return;
    if(type == INT)printf("类型检查错误, 变量%s的类型应为int\n", val);
    else printf("类型检查错误, 函数%s的返回类型应为void\n", val);
}