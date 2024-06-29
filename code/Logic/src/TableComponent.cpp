#include<iostream>

#include "logicLog.h"
#include "TableComponent.h"

TableComponent::TableProperty::TableProperty(const QString& name)
{
	m_propName = name;
}

TableComponent::TableComponent()
{
	m_rowNum = 0;
	m_table = nullptr;
}

void TableComponent::Init()
{

}

void TableComponent::AddProperty(const QString& propNamev)
{
	m_propsNames.push_back(TableProperty(propNamev));

}

void TableComponent::SetTargetTable(MTableView* table)
{
	if (!table)
		return;
	m_table = table;
}

