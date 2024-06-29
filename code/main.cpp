#include<iostream>
#include"MainApplication.h"
int main(int argc, char* argv[])
{
    MainApplication a(argc,argv);
    a.ShowWindow();
    return a.exec();
}