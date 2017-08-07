#pragma once
#include <memory>
#include "Component.h"
class Camera : public Component
{
public:
	Camera() = default;
	~Camera() override = default;
};

using CameraPtr = std::shared_ptr<Camera>;