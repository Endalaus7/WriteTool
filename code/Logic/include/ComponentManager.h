#pragma once

#include <QString>
#include <unordered_map>
#include "IComponent.h"
#include "LogicWrapper.h"

//#define ADD_TEMPLATE_CLASS()

//���������������
class ComponentManager
{
public:
	static ComponentManager* GetInstance();
	
	template<typename T>
	bool AddComponent();

	template<typename T>
	IComponent* GetComponent();

	template<typename T>
	void DeleteComponent();
	

	int GetComponentsNum();
private:
	ComponentManager();
	~ComponentManager();
	ComponentManager(ComponentManager&) = delete;				     // ��ֹ�������캯��
	ComponentManager& operator=(const ComponentManager&) = delete; // ��ֹ��ֵ�����

	static ComponentManager* m_instance;

	std::unordered_map<std::string, IComponent*> m_commponents;
};

template<typename T>
bool ComponentManager::AddComponent()
{
	std::string typestring = typeid(T).name();
	if (m_commponents.find(typestring) != m_commponents.end())//�Ƿ��ظ�
	{
		return false;
	}
	if (!std::is_base_of<IComponent, T>::value)//�Ƿ�̳���IComponent
	{
		return false;
	}
	T* newcomponent = new T;
	m_commponents.insert(std::pair<std::string, T*>(typestring, newcomponent));
	m_commponents.at(typestring)->Init();
	return true;
}

template<typename T>
IComponent* ComponentManager::GetComponent()
{
	std::string typestring = typeid(T).name();
	auto ret = m_commponents.find(typestring);
	
	if (ret == m_commponents.end())
	{
		bool addresult = AddComponent<T>();
		if(!addresult)
			return nullptr;
	}
	return m_commponents.at(typestring);
}

template<typename T>
void ComponentManager::DeleteComponent()
{
	std::string typestring = typeid(T).name();
	auto ret = m_commponents.find(typestring);
	if (ret != m_commponents.end())
	{
		SAFE_DELETE(*ret);
		m_commponents.erase(typestring);
	}
}