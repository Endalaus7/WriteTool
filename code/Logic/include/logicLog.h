#pragma once

#include <QString>

//instance in project WriteTool

class logicLog {
private:
	

	logicLog() { m_instance = nullptr; }    // ˽�л����캯��
	logicLog(logicLog&) = delete;				     // ��ֹ�������캯��
	logicLog& operator=(const logicLog&) = delete; // ��ֹ��ֵ�����

	static logicLog* m_instance;
public:
	static logicLog* Instance();
	enum ShowType {
		SHOW_CMD,
		SHOW_WIDGET
	};
	virtual void showLog(std::string log, ShowType type = SHOW_CMD);

};