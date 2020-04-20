#include"globals.h"
#include<iostream>
using namespace std;

void printOP(OPType type)
{
    switch(type){
    case Less: cout<<"<"; break;
    case Lessqual: cout<<"<="; break;
    case More: cout<<">"; break;
    case Moreequal: cout<<">="; break;
    case Equal: cout<<"=="; break;
    case Notequal:cout<<"!="; break;
    case Plus: cout<<"+"; break;
    case Multi: cout<<"*"; break;
    case Minus: cout<<"-"; break;
    case Divide: cout<<"/"; break;
    default:
        cout<<"Error: Unknown operator";
    } 
}
void printnode(TreeNode* node)
{
    if(!node) return;
    switch (node->nkind)
        {
        case IfK:
            cout<<"if"<<endl;
            break;
        case VarDeclK:
            cout<<"variable declare"<<endl;
            break;
        case IDK:
            cout<<"id "<<node->attr.name<<(node->array_len!=0 ?" array":"")<<endl;
           // if(node->array_len!=0) cout<<"array";
            //cout<<endl;
            break;
        case TypeK:
            //cout<<"type"<<endl;
            cout<<"type "<<(node->type == TYPE_INT ? "int":"void")<<endl;
            break;
        case FunK:
            cout<<"function"<<endl;
            break;
        case ParamK:
            cout<<"parameter"<<endl;
            break;
        case WhileK:
            cout<<"while"<<endl;
            break;
        case ExprK:
            cout<<"assignment"<<endl;
            break;
        case OPK:
            cout<<"operator ";
            printOP(node->attr.op);
            cout<<endl;
            break;
        case CallK:
            cout<<"call function"<<endl;
            break;
        case ReturnK:
            cout<<"return"<<endl;
            break;
        case VarK:
            cout<<"varaible "<<node->attr.name<<(node->array_len?"(array)":"")<<endl;
            break;
        case NumK:
            cout<<"number "<<node->value<<endl;
            break;
        default:
            cout<<"Error: Unknown node kind"<<node->nkind<<" "<<node->value<<node->type<<endl;
            break;
        }
}
void printtree(TreeNode* root, int tab)
{
    TreeNode* t = root;
    while(t)
    {
        int j = 0;
        while(j++<tab)cout<<" ";
        printnode(t);
        j=0;
        while(t->child[j]) printtree(t->child[j++], tab+2);
        t = t->sibling; 
    }
}