#include<iostream>


#include"globals.h"

using namespace std;

FILE* fd;

int main()
{
    fd = fopen("a.txt", "r");
    enum TokenType a;
    while(a = getToken())
    {
        cout<<a<<endl;
    }
    //fclose(fd);
    system("pause");
    return 0;
}
