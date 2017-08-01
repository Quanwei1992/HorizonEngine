#pragma once
#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include <memory>
#include <vector>
#include <typeinfo>
#include <algorithm> 
#include "Component/Component.h"
#include "Component/Behaviour.h"
#include "Component/Camera.h"
#include "Component/Transform.h"

class Scene;
class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	GameObject() = default;
	~GameObject() = default;
	template<typename T>
	std::weak_ptr<T> addComponent();
	template<typename T>
	std::weak_ptr<T> getComponent();

	void destoryComponent(const std::shared_ptr<Component>& component);

	std::vector<std::weak_ptr<Component>> getAllCompoents();
private:
	friend Scene;
	void onAwake();
	void onDestory();
private:
	std::vector<ComponentPtr> mComponents;
};
typedef std::shared_ptr<GameObject> GameObjectPtr;





#endif

template<typename T>
inline std::weak_ptr<T> GameObject::addComponent()
{
	// 每个类型的Component只能同时有一个.
	auto old = getComponent<T>().lock();
	if (old)destoryComponent(old);

	auto self_weak = std::weak_ptr<GameObject>(shared_from_this());
	std::shared_ptr<Component> component_base = std::make_shared<T>(self_weak);
	mComponents.push_back(component_base);
	auto component_derived = std::static_pointer_cast<T>(component_base);
	auto derived_weak = std::weak_ptr<T>(component_derived);
	return derived_weak;
}

template<typename T>
inline std::weak_ptr<T> GameObject::getComponent()
{
	for (auto component_base : mComponents)
	{
		std::shared_ptr<T> derived_ptr = std::dynamic_pointer_cast<T>(component_base);
		if (derived_ptr) {
			return std::weak_ptr<T>(derived_ptr);
		}
	}
	return std::weak_ptr<T>();
}
