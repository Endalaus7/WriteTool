#pragma once

#include <QString>

//instance in project WriteTool

class logicLog {
private:
	

	logicLog() { m_instance = nullptr; }    // 私有化构造函数
	logicLog(logicLog&) = delete;				     // 禁止拷贝构造函数
	logicLog& operator=(const logicLog&) = delete; // 禁止赋值运算符

	static logicLog* m_instance;
public:
	static logicLog* Instance();
	enum ShowType {
		SHOW_CMD,
		SHOW_WIDGET
	};
	virtual void showLog(std::string log, ShowType type = SHOW_CMD);

};