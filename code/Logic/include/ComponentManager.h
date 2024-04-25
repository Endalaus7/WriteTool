#pragma once

#include <QString>
#include <unordered_map>
#include "IComponent.h"


//interface
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	
	template<typename T>
	bool AddComponent();

	template<typename T>
	T* GetComponent();
private:

	int m_Num;//commponents num
	std::unordered_map<std::string, IComponent*> m_commponents;
};


template<typename T>
bool ComponentManager::AddComponent()
{ 
	std::string typestring = typeid(T).name();
	if (m_commponents.find(typestring) != m_commponents.end())//²»ÖØ¸´
	{
		return false;
	}
	if(!std::is_base_of<IComponent, T>::value)//¼Ì³Ð×ÔIComponent
	{
		return false;
	}
	m_commponents.insert(std::pair<std::string, T*>(typestring, new T()));
	m_Num++;
	return true;
}

template<typename T>
T* ComponentManager::GetComponent()
{
	std::string typestring = typeid(T).name();
	auto ret = m_commponents.find(typestring);
	if (ret != m_commponents.end())
		return *ret;
	return nullptr;
}
