#include "stdafx.h"
#include "Component.h"


Component::Component(std::weak_ptr<GameObject> onwer)
{
	mOnwer = onwer;
}

std::weak_ptr<GameObject> Component::getOnwer() const
{
	return mOnwer;
}

void Component::onAwake()
{
}

void Component::onDestory()
{
}
