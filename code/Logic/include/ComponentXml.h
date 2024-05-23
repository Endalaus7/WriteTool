#pragma once

#include "BookTable.h"
#include <map>

#include "IComponent.h"


class ComponentXml :public IComponent
{
public:
	ComponentXml();
	~ComponentXml();
	//ComponentXml(QString dataDir);//data root path

	virtual void Init()override;

	bool ReadBookguide();//get the menu
	void SetBookGuidePath(QString dir);
	
	bool CreatNewBook(QString name, QString bookdir);//create a empty book
	bool Readbook(uint bookno);//get book detail message 
	bool Savebook(uint bookno);//save detail message

protected:	
	int m_minNo;

	QString m_menudir;
	std::map<uint, BookTable*> m_guide;

};