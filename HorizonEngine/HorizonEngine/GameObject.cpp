#include "GameObject.h"
using namespace HorizonEngine;



std::vector<Component*>& HorizonEngine::GameObject::GetComponents()
{
	// TODO: �ڴ˴����� return ���
	return mComponents;
}


GameObject::GameObject()
{
	mComponents.push_back(&mTransform);
}


GameObject::~GameObject()
{
}

