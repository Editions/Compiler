%option noyywrap   
%{
#include <stdlib.h>
#include"globals.h"
// char* id;
// int value;
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
"/*"   {return LCOMM;}
"*/"   {return RCOMM;}
<<EOF>>     return END_OF_FILE;
{letter}|{letter}* {return ID;}
{digit}|{digit}*   {return NUM;}

%%

enum TokenType getToken()
{
    yyin = fd;
    int type = yylex();
    if(type == ID) id = yytext;
    else if(type == NUM) value = atoi(yytext);
    return TokenType(type);
}
