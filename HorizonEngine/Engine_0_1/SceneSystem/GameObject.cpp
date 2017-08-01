#include "stdafx.h"
#include "GameObject.h"

std::weak_ptr<Component> GameObject::addComponent()
{
	auto ptr = shared_from_this();
	auto compoent = std::make_shared<Component>(std::weak_ptr<GameObject>(ptr));
	mComponents.push_back(compoent);
	return std::weak_ptr<Component>(compoent);
}

void GameObject::onAwake()
{
	for (auto component:mComponents)
	{
		component->onAwake();
	}
}

void GameObject::onDestory()
{
	for (auto component:mComponents)
	{
		component->onDestory();
	}
	mComponents.clear();
}
