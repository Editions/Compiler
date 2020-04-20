%option noyywrap   
%{
#include <stdlib.h>
#include"globals.h"
#include"bison.tab.h"
char id[10];
int value;
int lineno;
void comment(); 
// typedef enum TokenType{
//     PLUS,MINUS,MULTI,DIVIDE,
//     LESS,LESSEQUAL,MORE,MOREEQUAL,EQUAL,NOTEQUAL,
//     ASSIGN,
//     SEMI,COMMA,
//     LPAREN,RPAREN,LBRACE,RBRACE,LBRACKET,RBRACKET,LCOMM,RCOMM,
//     IF,ELSE,INT,RETURN,VOID,WHILE,
//     ID,NUM
// }TokenType;
%}

newline     [\n\r]
whitespace  [ \t]+
letter [a-zA-Z]
digit [0-9]
%%
if     {return IF;}
else   {return ELSE;}
int    {return INT;}
return {return RETURN;}
void   {return VOID;}
while  {return WHILE;}
"+"    {return PLUS;}
"-"    {return MINUS;}
"*"    {return MULTI;}
"/"    {return DIVIDE;}
"<"    {return LESS;}
"<="   {return LESSEQUAL;}
">"    {return MORE;}
">="   {return MOREEQUAL;}
"=="   {return EQUAL;}
"!="   {return NOTEQUAL;}
"="    {return ASSIGN;}
";"    {return SEMI;}
","    {return COMMA;}
"("    {return LPAREN;}
")"    {return RPAREN;}
"["    {return LBRACKET;}
"]"    {return RBRACKET;}
"{"    {return LBRACE;}
"}"    {return RBRACE;}
"/*"   {comment();}
{newline}       {}
{whitespace}    {}
{letter}|{letter}* { sstrcpy(id, yytext); return ID;}
{digit}|{digit}*   { value = atoi(yytext);return NUM;}

%%
void comment()
{
    while(1){
        while(yyinput()!='*');
        if(yyinput() == '/') return;
    }
}
/*
TokenType getToken()
{
    yyin = fd;
    int type = yylex();
    if(type == ID) id = yytext;
    else if(type == NUM) value = atoi(yytext);
    return TokenType(type);
}
*/
