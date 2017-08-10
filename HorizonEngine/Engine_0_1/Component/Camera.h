#pragma once
#include <memory>
#include "Component.h"
class Camera : public Component
{
public:
	Camera();
	~Camera() override = default;

	float getDepth() const;
	void  setDepth(float depth);

private:
	float mDepth;
};

using CameraPtr = std::shared_ptr<Camera>;