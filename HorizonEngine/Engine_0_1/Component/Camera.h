#pragma once
#include "Component.h"
class Camera : public Component
{
public:
	Camera(std::weak_ptr<GameObject> onwer);
	~Camera() override = default;
};

