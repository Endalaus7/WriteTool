//#include<QtWidget>
#pragma once
#include <QList.h>
#include <QApplication.h>
#include <QMainWindow.h>

#include <unordered_map>

#include "MWrapper.h"
//#include "ComponentManager.h"

namespace Ui {
    class CreateBook;
    class HelpBook;
}

class MCreateBookWindow : public QWidget
{
    Q_OBJECT
public:
    MCreateBookWindow(QWidget *parent = nullptr);
    ~MCreateBookWindow();
protected slots:
	void on_PathSet_clicked();
    void on_create_Btn_clicked();
protected:


private:
    Ui::CreateBook* ui;

    //ComponentXml* m_xmlcom;
};

class MHelpBookWindow : public QWidget
{
	Q_OBJECT
public:
    MHelpBookWindow(QWidget* parent = nullptr);
	~MHelpBookWindow();

private:
	Ui::HelpBook* ui;
};