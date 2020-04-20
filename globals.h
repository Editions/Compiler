#pragma once
#include<iostream>
using namespace std;
#include<cstring>
#define MAX_CHILD 5
//#define MAX_ID_LENGTH 10
//extern char id[MAX_ID_LENGTH];
//char savedname[MAX_ID_LENGTH];
//extern char* id;
extern int value;
extern FILE* fd;
extern int lineno;

/*
typedef enum //TokenType
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
*/
typedef enum OpType{
    Plus,Minus,Multi,Divide,
    Less,Lessqual,More,Moreequal,Equal,Notequal
}OPType;
typedef enum ValType
{
    TYPE_INT, TYPE_VOID
}ValType;
typedef enum NodeKind
{
    IfK, VarDeclK, IDK, TypeK,FunK,ParamK,
    WhileK, ExprK, OPK,CallK,ReturnK,VarK,NumK
}NodeKind;
struct TreeNode
{
    struct TreeNode *child[MAX_CHILD];
    struct TreeNode* sibling;
    char* name; //变量名
    int value;
    int array_len;  //数组长度，负数为数组类型，函数参数
    ValType type; // 变量类型
    union{
        OPType op; // TYPE_INT， TYPE_VOID
        int val; // 变量值
        char name[10]; //变量名，函数名
    }attr;
    NodeKind nkind;
    TreeNode(NodeKind n){nkind = n;for(int i = 0; i < MAX_CHILD; i++) child[i]=NULL;sibling=NULL;array_len=0;value=0;}
};
//TokenType getToken();
struct TreeNode * parse(void);

void printtree(TreeNode* root, int tab);
void sstrcpy(char* a,char* b);
