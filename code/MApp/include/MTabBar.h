#pragma once

#include<QTabBar>

class MTabBar : public QTabBar
{
public:
    MTabBar(QWidget* p = nullptr);
    ~MTabBar();
    QSize tabSizeHint(int index)const override;
protected:
    void paintEvent(QPaintEvent* event)override;
};