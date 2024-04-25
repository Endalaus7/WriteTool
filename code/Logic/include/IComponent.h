#pragma once

#include <QString>
#include <winerror.h>
#include <typeinfo>

#include "logicLog.h"

//interface
class IComponent
{
public:
	IComponent();

	virtual void Init() { };

protected:
};