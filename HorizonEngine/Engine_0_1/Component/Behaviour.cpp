#include "Behaviour.h"
#include "stdafx.h"


Behaviour::Behaviour(std::weak_ptr<GameObject> onwer):Component(onwer)
{

}

void Behaviour::update(float dt)
{

}
