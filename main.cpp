#include<iostream>

#include"globals.h"
#include<queue>
using namespace std;

FILE* fd = nullptr;
extern FILE* yyin;
void sstrcpy(char* a,char* b)
{
    int i=0;
    while(i<9&&b[i]!='\0')
    {
        a[i] = b[i];
        i++;
    }
    a[i]='\0';
}
int main()
{
    //fd = fopen("a.txt", "r");
    yyin = fopen("test2.txt", "r");
    TreeNode* root = parse(); 
    printtree(root, 0);
    /*
    while(!r.empty())
    {
        int i = r.size();
        while(i--)
        {
            TreeNode* w = r.front();
            r.pop();
            if(w->nkind == WhileK) cout<<"whilek"<<endl;
            while(w->sibling) {r.push(w->sibling); w=w->sibling;}
            int j = 0;
            while(w->child[j]) { cout<<"push"<<endl;r.push(w->child[j++]);}
            cout<<"------------"<<endl; 
        }
    }*/
    system("pause");
    return 0;
}
