//#include<QtWidget>
#pragma once
#include <QList.h>
#include <QApplication.h>
#include <QMainWindow.h>

#include"MMainWindow.h"

namespace UI {
    class MainWindow;
}

class MApplication : public QApplication
{
    Q_OBJECT
public:
    MApplication(int argc,char** argv);
    ~MApplication();

    void ShowWindow();
protected:
	MyWindow m_window;
};