#pragma once
#include "Component.h"
class Behaviour : public Component
{
public:
	Behaviour() = default;
	~Behaviour() override = default;
private:
	void update(float dt);

};

