//#include<QtWidget>
#pragma once
#include <QList.h>
#include <QApplication.h>
#include <QMainWindow.h>

#include <unordered_map>

#include "ComponentManager.h"

namespace Ui {
    class MainWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

    virtual void InitMWindow();
    
private:
    Ui::MainWindow* ui;
    ComponentManager* m_componentManager;
};