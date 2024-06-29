#pragma once

#include <QString>
#include "IComponent.h"

//�����������

//���˼·����Ҫ�Ʊ�ʱ�����ô����������������

class MTableView;

class TableComponent :public IComponent
{
public:
	TableComponent();

	virtual void Init();
	//����,����ͷ
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