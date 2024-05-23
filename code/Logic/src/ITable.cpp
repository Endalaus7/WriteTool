#include<iostream>

#include "ITable.h"
#include "logicLog.h"

ITable::TableProperty::TableProperty(const QString& name)
{
	m_propName = name;
}

ITable::ITable()
{
	m_rowNum = 0;

}

void ITable::AddProperty(const QString& propNamev)
{
	m_propsNames.push_back(TableProperty(propNamev));
}

void ITable::WriteProperty(unsigned int no, const QString& propName, const QString& element)
{
	if (m_table.find(no) == m_table.end())//新行，执行回调
	{
		//callback
	}
	for (int i = 0; i < m_propsNames.size(); i++)
	{
		if (m_propsNames[i].m_propName == propName) 
		{
			m_table[no].at(i);
			return;
		}
	}
	logicLog::Instance()->showLog("Not Found property!"); 
	return;
}

void ITable::WriteProperty(unsigned int no, QStringList& row)
{
	if (m_table.find(no) == m_table.end())//新行，执行回调
	{
		//callback
	}
	int diff = row.size() - m_propsNames.size();
	if (diff > 0) {
		while(diff--)
			row.removeLast();
	}
	else if (diff < 0)
	{
		while (diff++)
			row.push_back("");
	}
	m_table[no] = row;
}

