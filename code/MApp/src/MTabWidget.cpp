#pragma once

#include "MTabWidget.h"
#include "MTabBar.h"

MTabWidget::MTabWidget(QWidget* p /*= nullptr*/)
	:QTabWidget(p)
{
	setTabBar(new MTabBar);
	setTabPosition(QTabWidget::West);
}

MTabWidget::~MTabWidget()
{

}
