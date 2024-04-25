#include"MMainWindow.h"
#include <iostream>
#include <QWidget>
#include <QTabWidget>
//#include <QTabBar>
#include "../form/ui_mainwindow.h"

#include "MTabBar.h"

#include "ComponentXml.h"
#include "config.h"

MyWindow::MyWindow(QWidget* parent)
	:QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	InitMWindow();
	m_componentManager = new ComponentManager;
	m_componentManager->AddComponent<ComponentXml>();

};

MyWindow::~MyWindow()
{
	delete ui;
}

void MyWindow::InitMWindow()
{
	for (int tabIndex = 1; tabIndex < ui->tabWidget->count(); tabIndex++)
		ui->tabWidget->tabBar()->setTabEnabled(tabIndex, false);
	//ui->tabWidget->currentIndex();

	//m_components.insert(std::pair<int, XmlComponent*>(0, new XmlComponent));
}
