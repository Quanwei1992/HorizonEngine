#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
using namespace HorizonEngine;



vec3 HorizonEngine::Transform::localPosition() const
{
	return mLocalPosition;
}

void HorizonEngine::Transform::localPosition(vec3 position)
{
	mLocalPosition = position;
	mLocalMat = Combine(mLocalPosition, mLocalRotation, mLocalScale);
}

vec3 HorizonEngine::Transform::localRotation() const
{
	return mLocalRotation;
}

void HorizonEngine::Transform::localRotation(vec3 rotation)
{
	mLocalRotation = rotation;
	mLocalMat = Combine(mLocalPosition, mLocalRotation, mLocalScale);
}

vec3 HorizonEngine::Transform::localScale() const
{
	return mLocalScale;
}

void HorizonEngine::Transform::localScale(vec3 scale)
{
	mLocalScale = scale;
	mLocalMat = Combine(mLocalPosition, mLocalRotation, mLocalScale);
}

mat4x4 HorizonEngine::Transform::localMatrix() const
{
	return mLocalMat;
}

vec3 Transform::worldPosition()
{
	vec4 pos(mLocalPosition,1);
	auto world = worldMatrix() * pos;
	return vec3(world.x,world.y,world.z);
}

mat4x4 HorizonEngine::Transform::worldMatrix() const
{
	if (mParent != nullptr)
	{
		return mParent->worldMatrix() * mParent->localMatrix();
	}
	else
	{
		return mat4x4();
	}
}

void Transform::parent(Transform & parent)
{
	mParent = &parent;

}

mat4x4 HorizonEngine::Transform::Combine(vec3 position, vec3 rotation, vec3 scale)
{
	mat4x4 mat;
	mat = glm::scale(mat, scale);
	mat = glm::rotate(mat, glm::radians(rotation.x), vec3(1, 0, 0));
	mat = glm::rotate(mat, glm::radians(rotation.y), vec3(0, 1, 0));
	mat = glm::rotate(mat, glm::radians(rotation.z), vec3(0, 0, 1));
	mat = glm::translate(mat, position);
	return mat;
}

HorizonEngine::Transform::Transform():
	mLocalPosition(0,0,0),
	mLocalScale(1,1,1),
	mLocalRotation(0,0,0)
{
}

HorizonEngine::Transform::~Transform()
{

}


