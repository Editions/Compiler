#include<iostream>
#include "mainwindow.h"

#include <QApplication>
#include"globals.h"
using namespace std;

FILE* fd = nullptr;
FILE* tokenlisting = nullptr;
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
