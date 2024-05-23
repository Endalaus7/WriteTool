#include<iostream>

#include "ComponentXml.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

// ComponentXml::ComponentXml(QString dataDir)
// {
// 	//m_menudir = QString::fromLocal8Bit(DATA_PATH) + "/menu.xml";
// 	m_menudir = dataDir + "/menu.xml";
// }

ComponentXml::ComponentXml()
{
	m_menudir = "";
	m_minNo = 0;
}

ComponentXml::~ComponentXml()
{

}

void ComponentXml::Init()
{
	__super::Init();

}

bool ComponentXml::ReadBookguide()
{
	QFile file(m_menudir);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		logicLog::Instance()->showLog("Can't open menu data:" + m_menudir.toStdString());
		return false;
	}
	m_guide.clear();//delete!!!!!!!
	uint minNo = UINT_MAX;

	QXmlStreamReader reader;
	reader.setDevice(&file);

	while (!reader.atEnd() && !reader.hasError())
	{
		QXmlStreamReader::TokenType token = reader.readNext();

		if (token == QXmlStreamReader::StartElement) { // 判断是否为xml开始标签，即左边的<
			if (reader.name() == QString("Books")) { // 标签名称

				uint bookNo = reader.attributes().value("No").toInt();
				QString bookName = reader.attributes().value("Name").toString();
				QString bookPath = reader.attributes().value("Path").toString();

				m_guide.insert(std::pair<uint,BookTable*>(bookNo, new BookTable));
				minNo = bookNo < minNo ? bookNo : minNo;
			}
		}
	}

	m_minNo = (minNo == UINT_MAX) ? 0 : minNo;
}

void ComponentXml::SetBookGuidePath(QString dir)
{
	m_menudir = dir;
}

bool ComponentXml::CreatNewBook(QString name, QString bookPath)
{
// 	logicLog::Instance()->showLog(name.toStdString());
// 	logicLog::Instance()->showLog(bookPath.toStdString());
 	
 	QFile file(m_menudir);
 	if (!file.open(QFile::ReadWrite | QFile::Text))
 	{
 		logicLog::Instance()->showLog("Can't open menu data:" + m_menudir.toStdString());
 		return false;
 	}
 	QXmlStreamWriter stream(&file);
 
 	stream.setAutoFormatting(true);
 	stream.writeStartDocument();
 	stream.writeStartElement("Books");
 
 	//stream.writeAttribute("No", QString::number(m_minNo));
 	stream.writeAttribute("Name", name);
 	stream.writeTextElement("Path", bookPath);
 
 	stream.writeEndElement();
 	stream.writeEndDocument();
 
 	file.close();

	ReadBookguide();
 
 	return true;
}

bool ComponentXml::Readbook(uint bookno)
{
	QFile file("./test.xml");
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		return false;
	}
	QXmlStreamReader reader;
	// 设置文件，这时会将流设置为初始状态 
	reader.setDevice(&file);
}

bool ComponentXml::Savebook(uint bookno)
{
	QFile file("./writeFile.xml");
	file.open(QFile::WriteOnly | QFile::Truncate);

	if (!file.exists())
	{
		//qDebug() << "Error: cannot open file";
		return false;
	}

	QXmlStreamWriter stream(&file);

	stream.setAutoFormatting(true);
	stream.writeStartDocument();
	stream.writeStartElement("book");

	//只是举例
	stream.writeStartElement("teacher");
	stream.writeAttribute("id", "01");
	stream.writeAttribute("time", "23:30");
	stream.writeTextElement("name", QString::fromLocal8Bit("ming"));
	stream.writeEndElement();

	stream.writeEndElement();
	stream.writeEndDocument();

	file.close();
	return true;
}

