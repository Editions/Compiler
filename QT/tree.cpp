#include"globals.h"
#include<iostream>

using namespace std;


void printOP(OPType type)
{
    switch(type){
    case Less: fprintf(fd,"<"); break;
    case Lessqual: fprintf(fd,"<="); break;
    case More: fprintf(fd,">"); break;
    case Moreequal: fprintf(fd,">="); break;
    case Equal: fprintf(fd,"=="); break;
    case Notequal:fprintf(fd,"!="); break;
    case Plus: fprintf(fd,"+"); break;
    case Multi: fprintf(fd,"*"); break;
    case Minus: fprintf(fd,"-"); break;
    case Divide: fprintf(fd,"/"); break;
    default:
        fprintf(fd,"Error: Unknown operator");
    }
}
void printnode(TreeNode* node)
{
    if(!node) return;
    switch (node->nkind)
        {
        case IfK:
            fprintf(fd,"if\n");
            break;
        case VarDeclK:
            fprintf(fd,"variable declare\n");
            break;
        case IDK:
            fprintf(fd, "id %s %s\n", node->attr.name, (node->array_len !=0 ?"(array)":""));
            break;
        case TypeK:
            fprintf(fd, "type %s \n", (node->type == TYPE_INT?"int":"void"));
            break;
        case FunK:
            fprintf(fd,"function\n");
            break;
        case ParamK:
            fprintf(fd,"parameter\n");
            break;
        case WhileK:
            fprintf(fd,"while\n");
            break;
        case ExprK:
            fprintf(fd,"assignment\n");
            break;
        case OPK:
            fprintf(fd,"operator ");
            printOP(node->attr.op);
            fprintf(fd,"\n");
            break;
        case CallK:
            fprintf(fd,"call function\n");
            break;
        case ReturnK:
            fprintf(fd,"return\n");
            break;
        case VarK:
            fprintf(fd,"varaible  %s\n", (node->array_len?"(array)":""));
            break;
        case NumK:
            fprintf(fd, "number %d \n", node->value);
            break;
        default:
            fprintf(fd, "Error:unknown node kind\n");
            break;
        }
}
void printtree(TreeNode* root, int tab)
{
    TreeNode* t = root;
    while(t)
    {
        int j = 0;
        while(j++<tab)fprintf(fd, " ");
        printnode(t);
        j=0;
        while(t->child[j]) printtree(t->child[j++], tab+3);
        t = t->sibling; 
    }
}
void deletetree(TreeNode* node)
{
    if(node == nullptr) return;

    for(int i = 0; i < MAX_CHILD; i++)
        deletetree(node->child[i]);
    deletetree(node->sibling);
    delete node;
}
