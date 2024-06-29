#pragma once

#include "ComponentManager.h"
#include "MApplication.h"

class MainApplication:public MApplication
{
public:
	MainApplication(int argc, char** argv);
	~MainApplication();

	virtual void ShowWindow();

protected:
	ComponentManager* m_componentManager;
};