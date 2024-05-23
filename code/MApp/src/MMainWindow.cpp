#include"MMainWindow.h"
#include <iostream>
#include <QWidget>
#include <QTabWidget>
//#include <QTabBar>
#include "../form/ui_mainwindow.h"

#include "MTabBar.h"

#include "MMainWidgets.h"

#include "ComponentXml.h"
#include "config.h"

MyWindow::MyWindow(QWidget* parent)
	:QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	InitMWindow();
	m_componentManager = ComponentManager::GetInstance();
	m_componentManager->AddComponent<ComponentXml>();
	SetBookGuidePath(MAIN_GUIDE_PATH);
	m_createWidget = nullptr;
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

void MyWindow::SetBookGuidePath(QString path)
{
	ComponentXml* xmlcomponent = (ComponentXml*)m_componentManager->GetComponent<ComponentXml>();
	if (xmlcomponent) 
	{
		xmlcomponent->SetBookGuidePath(path);
		xmlcomponent->ReadBookguide();
	}
}

void MyWindow::on_btn_book_Create_clicked()
{
	if(!m_createWidget)
		m_createWidget = new MCreateBookWindow;
	m_createWidget->show();
}

void MyWindow::on_btn_book_Help_clicked()
{
	if (!m_helpWidget)
		m_helpWidget = new MHelpBookWindow;
	m_helpWidget->show();
}
