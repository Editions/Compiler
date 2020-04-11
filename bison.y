%{
#include"globals.h"

#define YYSTYPE TreeNode*
static TreeNode* root;
%}
%start program // 开始符号

//%union{
  //  int num;   // 属性值
   // char* id;  // 标识符
    //int type;  // +-*/ //(0123)
//}
%token VOID INT
%token IF ELSE
%token WHILE
%token RETURN
%token ASSIGN
%token SEMI COMMA
%token LBRACE RBRACE LBRACKET RBRACKET
%token LCOMM RCOMM 

%token ID
%token NUM
//%token <id>ID 
//%token <num>NUM

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
                        ;//idid
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
                        | compound_stmt {$$ = $1;}
                        ;
params                  : param_list  { $$ = $1;}
                        | VOID  {$$ = new TreeNode();}
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
                        {   if($1 == NULL)
                                $$ = $2;
                            else
                            {
                                YYSTYPE t = $1;
                                while(t->sibling) t = t->sibling;
                                t->sibling = $2;
                                $$ = t;
                            }

                        }
                        |    {$$ = NULL;}//empty /////////////////
                        ;
statement_list          : statement_list statement
                        {   if($1 == NULL) 
                                $$ = $2;
                            else
                            {
                                YYSTYPE t = $1;
                                while(t->sibling) t = t->sibling;
                                t->sibling = $2;
                                $$ = t;
                            }
                        }
                        |   {$$ = NULL;}//empty  /////////////
                        ;

statement                 : matched_stmt {$$ = $1;}
                          | unmatched_stmt {$$ = $1;}
expression_stmt         : expression SEMI { $$ = $1;} //////////////////////////////////////////
                //        | SEMI///////////////////////////////////
                        ;
                   ;
matched_stmt            : IF LPAREN expression RPAREN matched_stmt ELSE matched_stmt
                        {   $$ = new TreeNode();
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                            $$->child[2] = $7;
                        }
                        | expression_stmt {$$ = $1;}
                        | compound_stmt {$$ = $1;}
                        | iteration_stmt {$$ = $1;}
                        | return_stmt {$$ = $1;}
                        ;
unmatched_stmt          : IF LPAREN expression RPAREN statement
                        {   $$ = new TreeNode();
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                        }
                        | IF LPAREN expression RPAREN matched_stmt ELSE unmatched_stmt
                        {   $$ = new TreeNode();
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                            $$->child[2] = $7;
                        };

iteration_stmt          : WHILE LPAREN expression RPAREN statement
                        {   $$ = new TreeNode();
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                        }
                        ;
return_stmt             : RETURN SEMI { $$ = new TreeNode();}
                        | RETURN expression SEMI { $$ = new TreeNode(); $$->child[0] = $1;}
                        ;
expression              : var ASSIGN expression 
                        {   $$ = new TreeNode();
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | simple_expression { $$ = $1;}
                        ;
var                     : ID {$$ = new TreeNode(); $$->name = id, $$->value = value;}
                        | ID LBRACKET expression RBRACKET
                        {   $$ = new TreeNode();
                            $$->id = ID;
                            $$->child[0] = $3;
                            ////$$->value = $3->value;   /////////////////////////////////////////////
                        }
                        ;
simple_expression       : additive_expression relop additive_expression
                        {   $$ = $2; /////
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | additive_expression {$$ = $1;}
                        ;
relop                   : LESS  { $$ = new TreeNode();}
                        | LESSEQUAL { $$ = new TreeNode();}
                        | MORE { $$ = new TreeNode();}
                        | MOREEQUAL { $$ = new TreeNode();}
                        | EQUAL { $$ = new TreeNode();}
                        | NOTEQUAL { $$ = new TreeNode();}
                        ;
additive_expression     : additive_expression addop term 
                        {   $$ = $2; 
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | term {$$ = $1;}
                        ;
addop                   : PLUS {$$ = new TreeNode();}
                        | MINUS {$$ = new TreeNode();}
                        ;
term                    : term mulop factor 
                        {   $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | factor  {$$ = $1;}
                        ;
mulop                   : MULTI {$$ = new TreeNode();}
                        | DIVIDE {$$ = new TreeNode();}
                        ;
factor                  : LPAREN expression RPAREN {$$ = $2;}
                        | var {$$ = $1;}
                        | call {$$ = $1;}
                        | NUM {$$ = $1;}
                        ;
call                    : ID LPAREN args RPAREN 
                        {   $$ = new TreeNode();
                            $$->child[0] =ID;
                            $$->child[1] = $3;
                        }
                        ;
args                     : arg_list {$$ = $1;}
                        | {$$ = NULL; } //empty //////////
                        ;
arg_list                : arg_list COMMA expression 
                        {   YYSTYPE t = $1;
                            while(t->sibling) t = t->sibling;
                            t->sibling = $3;
                        }
                        | expression {$$ = $1;}
                        ;
                  

%%

void type_check(char* val, ValType type, ValType correct_type)
{
    if(correct_type == type) return;
    if(type == INT)printf("类型检查错误, 变量%s的类型应为int\n", val);
    else printf("类型检查错误, 函数%s的返回类型应为void\n", val);
}
