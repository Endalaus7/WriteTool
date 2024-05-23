#pragma once

#include <QString>
#include <QVector>
#include <QMap>
//�������Ľӿ�
//����Ԫ�ض���qstring



class ITable
{
public:
	ITable();
	
	//����,����ͷ
	struct TableProperty
	{
		TableProperty(const QString& name);
		QString m_propName;
		
	};


	void AddProperty(const QString& propName);

	void WriteProperty(unsigned int no, const QString& propName, const QString& element);
	void WriteProperty(unsigned int no, QStringList& row);
protected:

	unsigned int m_rowNum;
	QVector<TableProperty> m_propsNames;
	QMap<unsigned int, QStringList> m_table;
};