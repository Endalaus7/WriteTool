#pragma once

#include <QString>
#include "IComponent.h"

//制作表格的组件

//设计思路：需要制表时，调用此组件，输入表的内容

class MTableView;

class TableComponent :public IComponent
{
public:
	TableComponent();

	virtual void Init();
	//属性,即表头
	struct TableProperty
	{
		TableProperty(const QString& name);
		QString m_propName;
		
	};

	void AddProperty(const QString& propName);
	void SetTargetTable(MTableView* table);


protected:
	unsigned int m_rowNum;
	std::vector<TableProperty> m_propsNames;
	MTableView* m_table;
};