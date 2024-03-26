//#include<QtWidget>
#pragma once
#include <QList.h>
#include <QApplication.h>
#include <QMainWindow.h>

namespace Ui {
    class MainWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

private:
    Ui::MainWindow* ui;
};