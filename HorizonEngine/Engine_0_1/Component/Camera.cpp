#include "stdafx.h"
#include "Camera.h"

Camera::Camera():
	mDepth(0)
{

}

const float Camera::getDepth() const
{
	return mDepth;
}

void Camera::setDepth(float depth)
{
	mDepth = depth;
}

const Vector4 Camera::getViewport() const
{
	return mViewport;
}

void Camera::setViewport(const Vector4 & rect)
{
	mViewport = rect;
}
