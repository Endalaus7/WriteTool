#include"MApplication.h"
#include <iostream>
#include <QWidget>
#include "../form/ui_mainwindow.h"

MApplication::MApplication(int argc,char** argv)
	:QApplication(argc,argv)
{
};

MApplication::~MApplication()
{

}

void MApplication::ShowWindow()
{
	m_window.show();
}
