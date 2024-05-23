#include<iostream>

#include "logicLog.h"

logicLog* logicLog::m_instance = nullptr;

logicLog* logicLog::Instance()
{
	if (nullptr == m_instance) {
		m_instance = new logicLog();
	}
	return m_instance;
}

void logicLog::showLog(std::string log, ShowType type /*= Show_CMD*/)
{
	switch (type)
	{
	case logicLog::SHOW_CMD:
		std::cout << log << std::endl;
		break;
	case logicLog::SHOW_WIDGET:

		break;
	default:
		break;
	}
}
