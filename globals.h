#pragma once

static char* id;
static int value;
extern FILE* fd;

typedef enum TokenType{
    END_OF_FILE, 
    PLUS,MINUS,MULTI,DIVIDE,
    LESS,LESSEQUAL,MORE,MOREEQUAL,EQUAL,NOTEQUAL,
    ASSIGN,
    SEMI,COMMA,
    LPAREN,RPAREN,LBRACE,RBRACE,LBRACKET,RBRACKET,LCOMM,RCOMM,
    IF,ELSE,INT,RETURN,VOID,WHILE,
    ID,NUM
}TokenType;

enum TokenType getToken();