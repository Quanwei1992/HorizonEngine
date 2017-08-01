#include "stdafx.h"
#include "GameObject.h"



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

std::vector<std::weak_ptr<Component>> GameObject::getAllCompoents()
{
	std::vector<std::weak_ptr<Component>> temp;
	for (auto co : mComponents)
	{
		temp.push_back(co);
	}
	return temp;
}


void GameObject::destoryComponent(const std::shared_ptr<Component>& component)
{
	if (!component)return;
	auto result = std::find(mComponents.begin(), mComponents.end(), component);
	if (result != mComponents.end())
	{
		component->onDestory();
		mComponents.erase(result);
	}
}