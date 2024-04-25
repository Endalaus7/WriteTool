#include<iostream>

#include "logicLog.h"


logicLog* logicLog::Instance()
{
	if (nullptr == m_instance) {
		m_instance = new logicLog();
	}
	return m_instance;
}

void logicLog::showLog(std::string log, ShowType type /*= Show_CMD*/)
{
	if (type == Show_CMD)
	{
		std::cout << log << std::endl;
	}
}
