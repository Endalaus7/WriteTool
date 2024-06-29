#pragma once
#include "ComponentManager.h"

#define SAFE_DELETE(ptr)  if (ptr != nullptr) {delete ptr; ptr = nullptr; } 

#define GET_COMPONENT(T) (T*)ComponentManager::GetInstance()->GetComponent<T>()