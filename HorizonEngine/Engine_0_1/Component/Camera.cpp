#include "stdafx.h"
#include "Camera.h"

Camera::Camera():
	mDepth(0)
{

}

float Camera::getDepth() const
{
	return mDepth;
}

void Camera::setDepth(float depth)
{
	mDepth = depth;
}
