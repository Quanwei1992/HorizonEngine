#include "stdafx.h"
#include "Component.h"

std::weak_ptr<GameObject> Component::getOnwer() const
{
	return mOnwer;
}

void Component::setOnwer(std::shared_ptr<GameObject> onwer)
{
	mOnwer = std::weak_ptr<GameObject>(onwer);
}

void Component::onAwake()
{
}

void Component::onDestory()
{
}
