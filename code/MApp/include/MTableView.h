#pragma once
#include <QTableView>
#include <QStandardItemModel>

class MTableView :public QTableView
{
public:
	MTableView(QWidget* parent);
	~MTableView();

	void AddTableTitle(const QString& title);

	int FindElement(const QString& title, const QString& element) {}
protected:
	QStandardItemModel m_model;
};

