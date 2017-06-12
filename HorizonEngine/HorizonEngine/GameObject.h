#pragma once
#include <Transform.h>
#include "Component.h"
#include <vector>
#include <string>
#include <type_traits>
namespace HorizonEngine
{
	class GameObject
	{

	public:
		Transform & transform() const;
		template<typename T, typename Requires = std::enable_if_t<std::is_base_of<Component, T>::value>>
		T& AddComponent();
		std::vector<Component*>& GetComponents();
		void Start();
		void Destory();
	public:
		GameObject();
		~GameObject();

	private:
		Transform* mTransform;
		std::vector<Component*> mComponents;
		bool mIsStatred;

	};

	template<typename T, typename Requires>
	inline T & GameObject::AddComponent()
	{
		// TODO: 在此处插入 return 语句
		T* component = new T();
		component->setOnwer(*this);
		mComponents.push_back(component);
		if (mIsStatred)
		{
			component->Start();
		}
		return *component;
	}

}


