#pragma once

#include "BookGuideTable.h"
#include <map>

#include "IComponent.h"

//interface
class ComponentXml :public IComponent
{
public:
	ComponentXml(){}
	ComponentXml(QString dataDir);//data root path

	virtual void Init();

	bool ReadBookguide();//get the menu
	
	bool CreatNewBook(QString name, QString bookdir);//create a empty book
	bool Readbook(uint bookno);//get book detail message 
	bool Savebook(uint bookno);//save detail message

protected:	
	int m_minNo;

	QString m_menudir;
	std::map<uint, BookGuideTable*> m_guide;

};