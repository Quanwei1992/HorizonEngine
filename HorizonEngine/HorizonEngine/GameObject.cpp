#include "GameObject.h"
using namespace HorizonEngine;



std::vector<Component*>& HorizonEngine::GameObject::GetComponents()
{
	// TODO: 在此处插入 return 语句
	return mComponents;
}


GameObject::GameObject()
{
	mComponents.push_back(&mTransform);
}


GameObject::~GameObject()
{
}

