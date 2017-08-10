#pragma once
#include <memory>
#include "Component.h"
#include "Math/Math.h"
class Camera : public Component
{
public:
	Camera();
	~Camera() override = default;

	const float getDepth() const;
	void  setDepth(float depth);
	const Vector4 getViewport() const;
	void setViewport(const Vector4& rect);


private:
	float mDepth;
	Vector4 mViewport;
};

using CameraPtr = std::shared_ptr<Camera>;