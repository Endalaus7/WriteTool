//#include<QtWidget>
#pragma once
#include <QList.h>
#include <QApplication.h>
#include <QMainWindow.h>

#include <unordered_map>

namespace Ui {
    class MainWindow;
}

class MCreateBookWindow;
class MHelpBookWindow;

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

    virtual void InitMWindow();
    
    void SetBookGuidePath(QString path);
protected slots:
    void on_btn_book_Create_clicked();
    void on_btn_book_Help_clicked();
protected:

private:
    Ui::MainWindow* ui;

    MCreateBookWindow* m_createWidget;
    MHelpBookWindow* m_helpWidget;

};