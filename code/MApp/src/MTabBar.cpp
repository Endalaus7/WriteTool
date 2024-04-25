#pragma once

#include "MTabBar.h"
#include <QStylePainter>
#include "QStyleOption"

MTabBar::MTabBar(QWidget* p)
	:QTabBar(p)
{
};

MTabBar::~MTabBar()
{

}

QSize MTabBar::tabSizeHint(int index) const
{
	QSize s = QTabBar::tabSizeHint(index);
	s.transpose();

	s.rwidth() = 90;
	s.rheight() = 40;
	return s;
}

void MTabBar::paintEvent(QPaintEvent* event)
{
	QStylePainter painter(this);
	QStyleOptionTab opt;

	for (int i = 0; i < count(); i++)
	{
		initStyleOption(&opt, i);
		painter.drawControl(QStyle::CE_TabBarTabShape, opt);
		painter.save();

		QSize s = opt.rect.size();
		s.transpose();
		QRect r(QPoint(), s);
		r.moveCenter(opt.rect.center());
		opt.rect = r;

		QPoint c = tabRect(i).center();
		painter.translate(c);
		painter.rotate(90);
		painter.translate(-c);
		painter.drawControl(QStyle::CE_TabBarTabLabel, opt);
		painter.restore();

	}
}
