%{
#include"globals.h"
#include<stack>
extern int yylex();
void yyerror(const char* s);
#define YYSTYPE TreeNode*
extern char id[10];
struct TreeNode* root;
void type_check(char* val, ValType type, ValType correct_type);
char savedname[10];

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

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%

program                 : declaration_list  {root = $1;}
                        ;
declaration_list        : declaration_list declaration  { 
                            YYSTYPE t = $1;
                            $$ = t;
                            while(t->sibling) t = t->sibling;
                            t->sibling = $2;
                        }
                        | declaration  {$$ = $1;}          
                        ;
declaration             : var_declaration  {$$ = $1;}
                        | fun_declaration  {$$ = $1;}
                        ;
var_declaration         : type_specifier ID SEMI {  
                            $$ = new TreeNode(VarDeclK);
                            $$->child[0] = $1;
                            $$->child[1] = new TreeNode(IDK);
                            strcpy($$->child[1]->attr.name, id);
                            // type_check(id, $$->type, TYPE_INT);
                        }
                        | type_specifier ID LBRACKET NUM RBRACKET SEMI  {  
                            $$ = new TreeNode(VarDeclK);
                            $$->child[0] = $1;
                            $$->child[1] = new TreeNode(IDK);
                            strcpy($$->child[1]->attr.name,id);
                            $$->child[2] = new TreeNode(NumK);
                            $$->child[2]->value = value;
                            //$$->child[1]->array_len = value;
                        }
                        ;
type_specifier          : INT  {$$ = new TreeNode(TypeK); $$->type = TYPE_INT;}
                        | VOID {$$ = new TreeNode(TypeK); $$->type = TYPE_VOID;}
                        ;
fun_declaration         : type_specifier ID LPAREN {$$=new TreeNode(IDK);strcpy($$->attr.name,id);strcpy(savedname,id); }
                            params RPAREN compound_stmt  {
                            $$ = new TreeNode(FunK);
                            $$->child[0] = $1;
                            //$$->child[1] = new TreeNode(IDK);
                            $$->child[1] = $4;
                            $$->child[2] = $5;
                            $$->child[3] = $7;
                            //strcpy($$->child[1]->attr.name,savedname);
                            //type_check(id, $$->type, TYPE_VOID);
                        }
                        ;
                                  
params                  : param_list  { $$ = $1;}
                        | VOID  {
                            $$ = new TreeNode(TypeK);
                            $$->type = TYPE_VOID;
                        }
                        ;
param_list              : param_list COMMA param {  
                            YYSTYPE t = $1; 
                            $$ = t;
                            while(t->sibling) t = t->sibling;
                            t->sibling = $3;
                        }
                        | param { $$ = $1;}
                        ;
param                   : type_specifier ID {   
                            $$ = new TreeNode(ParamK);
                            $$->child[0] = $1;
                            $$->child[1] = new TreeNode(IDK);
                            strcpy($$->child[1]->attr.name, id);
                        }
                        | type_specifier ID LBRACKET RBRACKET {
                            $$ = new TreeNode(ParamK);
                            $$->child[0] = $1;
                            $$->child[1] = new TreeNode(IDK);
                            strcpy($$->child[1]->attr.name, id);
                            $$->child[1]->array_len = -1;
                        }
                        ;

compound_stmt           : LBRACE local_declarations statement_list RBRACE{
                            YYSTYPE t = $2;
                            if(!t) $$ = $3;
                            else{
                                $$ = t;
                                while(t->sibling) t = t->sibling;
                                t->sibling = $3;
                            }  
                        }
                        ;
local_declarations      : local_declarations var_declaration {
                            if($1 == NULL)
                                $$ = $2;
                            else
                            {
                                YYSTYPE t = $1;
                                $$ = t;
                                while(t->sibling) t = t->sibling;
                                t->sibling = $2;
                            }
                        }
                        |    {$$ = NULL;}//empty 
                        ;
statement_list          : statement_list statement{
                            if($1 == NULL) 
                                $$ = $2;
                            else
                            {
                                YYSTYPE t = $1;
                                $$ = t;
                                while(t->sibling) t = t->sibling;
                                t->sibling = $2;
                            }
                        }
                        |   {$$ = NULL;}//empty 
                        ;

expression_stmt         : expression SEMI { $$ = $1;}
                //      | SEMI  ??
                        ;
statement               : expression_stmt  {$$ = $1;}
                        | compound_stmt    {$$ = $1;}
                        | selection_stmt   {$$ = $1;}
                        | iteration_stmt   {$$ = $1;}
                        | return_stmt      {$$ = $1;}
                        ;     
selection_stmt          : IF LPAREN expression RPAREN statement  %prec LOWER_THEN_ELSE 
                        {   $$ = new TreeNode(IfK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                        }
                        | IF LPAREN expression RPAREN statement ELSE statement
                        {   $$ = new TreeNode(IfK);
                           $$->child[0] = $3;
                            $$->child[1] = $5;
                            $$->child[2] = $7;
                        }
                        ;        

iteration_stmt          : WHILE LPAREN expression RPAREN statement
                        {   $$ = new TreeNode(WhileK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                        }
                        ;
return_stmt             : RETURN SEMI { $$ = new TreeNode(ReturnK);}
                        | RETURN expression SEMI { $$ = new TreeNode(ReturnK); $$->child[0] = $2;}
                        ;
expression              : var ASSIGN expression 
                        {   $$ = new TreeNode(ExprK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | simple_expression { $$ = $1;}
                        ;
var                     : ID {$$ = new TreeNode(IDK); strcpy($$->attr.name, id);
                        }
                        | ID LBRACKET {$$=new TreeNode(IDK);strcpy($$->attr.name,id);strcpy(savedname, id);}
                        expression RBRACKET
                        {   $$ = new TreeNode(VarK);
                            //strcpy($$->attr.name, id);
                            //$$->child[0] = new TreeNode(IDK);
                            //strcpy($$->child[0]->attr.name, savedname); 
                            $$->child[0] = $3;
                            $$->array_len = -1;  // or -2;
                            $$->child[1] = $4;
                        }
                        ;
simple_expression       : additive_expression relop additive_expression
                        {   $$ = $2; 
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | additive_expression {$$ = $1;}
                        ;
relop                   : LESS  { $$ = new TreeNode(OPK); $$->attr.op = Less;}
                        | LESSEQUAL { $$ = new TreeNode(OPK); $$->attr.op = Lessqual;}
                        | MORE { $$ = new TreeNode(OPK); $$->attr.op = More;}
                        | MOREEQUAL { $$ = new TreeNode(OPK); $$->attr.op = Moreequal;}
                        | EQUAL { $$ = new TreeNode(OPK); $$->attr.op = Equal;}
                        | NOTEQUAL { $$ = new TreeNode(OPK); $$->attr.op = Notequal;}
                        ;
additive_expression     : additive_expression addop term 
                        {   $$ = $2; 
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | term {$$ = $1;}
                        ;
addop                   : PLUS {$$ = new TreeNode(OPK); $$->attr.op = Plus;}
                        | MINUS {$$ = new TreeNode(OPK); $$->attr.op=Minus;}
                        ;
term                    : term mulop factor 
                        {   $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | factor  {$$ = $1;}
                        ;
mulop                   : MULTI {$$ = new TreeNode(OPK); $$->attr.op=Multi;}
                        | DIVIDE {$$ = new TreeNode(OPK);$$->attr.op = Divide;}
                        ;
factor                  : LPAREN expression RPAREN {$$ = $2;}
                        | var {$$ = $1;}
                        | call {$$ = $1;}
                        | NUM {$$=new TreeNode(NumK);$$->value = value;}
                        ;
call                    : ID LPAREN {$$=new TreeNode(IDK);strcpy($$->attr.name,id);strcpy(savedname, id);}
                        args RPAREN 
                        {   $$ = new TreeNode(CallK);
                            //$$->child[0] = new TreeNode(IDK);
                            $$->child[0] = $3;
                            //strcpy($$->child[0]->attr.name, id);
                            //strcpy($$->child[0]->attr.name,savedname);
                            $$->child[1] = $4;
                        }
                        ;
args                    : arg_list {$$ = $1;}
                        | {$$ = NULL; } //empty 
                        ;
arg_list                : arg_list COMMA expression 
                        {   YYSTYPE t = $1;
                            $$ = t;
                            while(t->sibling) t = t->sibling;
                            t->sibling = $3;
                        }
                        | expression {$$ = $1;}
                        ;
                  

%%

void type_check(char* val, ValType type, ValType correct_type)
{
    if(correct_type == type) return;
    if(type == TYPE_INT)printf("类型检查错误, 变量%s的类型应为int\n", val);
    else printf("类型检查错误, 函数%s的返回类型应为void\n", val);
}
/*
int yyerror(char * message)
{ //fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  //fprintf(listing,"Current token: ");
  //printToken(yychar,tokenString);
  //Error = TRUE;
  return 0;
}
*/
/*
static int yylex(void)
{ return getToken(); }
*/
void yyerror(const char* s){
    fprintf(stderr, "error: %s at line %d\n", s, lineno);
}
TreeNode * parse(void)
{ yyparse();
  return root;
}

