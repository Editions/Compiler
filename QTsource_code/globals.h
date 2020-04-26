#pragma once
#include<iostream>
using namespace std;
#include<cstring>
#define MAX_CHILD 5

extern int value;
extern FILE* fd;
extern FILE* tokenlisting;
extern int lineno;
extern bool TokenAna;


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

int getToken();
struct TreeNode * parse(void);

void printtree(TreeNode* root, int tab);
void printToken(int type);
void sstrcpy(char* a,char* b);
void deletetree(TreeNode* node);
