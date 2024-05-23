#include<iostream>

#include "ComponentManager.h"

ComponentManager* ComponentManager::m_instance = nullptr;

ComponentManager::ComponentManager()
{

}

ComponentManager::~ComponentManager()
{
	for (auto itr : m_commponents)
	{
		SAFE_DELETE(itr.second);
	}
	m_commponents.clear();
}

ComponentManager* ComponentManager::GetInstance()
{
	if (nullptr == m_instance) {
		m_instance = new ComponentManager;
	}
	return m_instance;
}

int ComponentManager::GetComponentsNum()
{
	return m_commponents.size();
}
