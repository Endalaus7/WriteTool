#include<iostream>
#include"MApplication.h"
int main(int argc, char* argv[])
{
    MApplication a(argc,argv);
    a.ShowWindow();
    return a.exec();
}