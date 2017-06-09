#include "Component.h"
using namespace HorizonEngine;


Component::Component()
{
}

Component::Component(GameObject& onwer)
{
	this->mOnwer = &onwer;
}

Component::~Component()
{
}
