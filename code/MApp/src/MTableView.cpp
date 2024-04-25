#pragma once

#include "MTableView.h"

MTableView::MTableView(QWidget* parent)
{

}

MTableView::~MTableView()
{

}

void MTableView::AddTableTitle(const QString& title)
{
	//添加属性不仅是为qtable添加列，还要为xml添加属性
	QList<QStandardItem*> list;
	list.resize(m_model.rowCount());
	m_model.appendColumn(list);
	m_model.setHorizontalHeaderItem(m_model.columnCount(), new QStandardItem(title));
	setModel(&m_model);
}

