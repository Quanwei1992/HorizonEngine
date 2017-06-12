#include "Component.h"
using namespace HorizonEngine;


Component::Component():
	mOnwer(nullptr)
{
}
Component::~Component()
{
}



const GameObject & HorizonEngine::Component::getOnwer() const
{
	return *mOnwer;
}

void HorizonEngine::Component::setOnwer(const GameObject & onwer)
{
	mOnwer = &onwer;
}
