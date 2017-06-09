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
		const Transform & transform() { return mTransform; }
		template<typename T, typename Requires = std::enable_if_t<std::is_base_of<Component, T>::value>>
		T& AddComponent();
		std::vector<Component*>& GetComponents();
	public:
		GameObject();
		~GameObject();

	private:
		Transform mTransform;
		std::vector<Component*> mComponents;

	};

	template<typename T, typename Requires>
	inline T & GameObject::AddComponent()
	{
		// TODO: �ڴ˴����� return ���
		T* component = new T();
		mComponents.push_back(component);
		return *component;
	}

}

