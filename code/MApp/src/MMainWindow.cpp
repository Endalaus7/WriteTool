#include"MMainWindow.h"
#include <iostream>
#include <QWidget>
#include "../form/ui_mainwindow.h"

MyWindow::MyWindow(QWidget* parent)
	:QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
};

MyWindow::~MyWindow()
{
	delete ui;
}
