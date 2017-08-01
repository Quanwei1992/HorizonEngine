#pragma once
#include "Component.h"
class Behaviour : public Component
{
public:
	Behaviour(std::weak_ptr<GameObject> onwer);
	~Behaviour() = default;
private:
	void update(float dt);

};

