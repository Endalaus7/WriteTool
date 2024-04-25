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
	//������Բ�����Ϊqtable����У���ҪΪxml�������
	QList<QStandardItem*> list;
	list.resize(m_model.rowCount());
	m_model.appendColumn(list);
	m_model.setHorizontalHeaderItem(m_model.columnCount(), new QStandardItem(title));
	setModel(&m_model);
}

