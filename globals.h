#pragma once

#define MAX_CHILD 5
static char* id;
static int value;
extern FILE* fd;

typedef enum TokenType
{
    END_OF_FILE, 
    PLUS,MINUS,MULTI,DIVIDE,
    LESS,LESSEQUAL,MORE,MOREEQUAL,EQUAL,NOTEQUAL,
    ASSIGN,
    SEMI,COMMA,
    LPAREN,RPAREN,LBRACE,RBRACE,LBRACKET,RBRACKET,LCOMM,RCOMM,
    IF,ELSE,INT,RETURN,VOID,WHILE,
    ID,NUM
}TokenType;

typedef enum ValType
{
    INT, VOID
}ValType;
struct TreeNode
{
    struct TreeNode *child[MAX_CHILD];
    struct TreeNode* sibling;
    char* name; //变量名
    int value;
    int array_len = 0;  //数组长度，负数为函数参数
    ValType type; // 变量类型
};
enum TokenType getToken();