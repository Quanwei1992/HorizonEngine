#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
using namespace HorizonEngine;

const vec3 & HorizonEngine::Transform::GetPosition()
{
	// 获得世界坐标,需要应用父节点的变换.
	return mLocalPosition;
}

void HorizonEngine::Transform::parent(Transform & parent)
{
	mParent = &parent;

}

const glm::mat4x4 & Transform::Combine()
{
	glm::mat4x4 temp;
	temp = glm::scale(temp, mLocalScale);
	temp = glm::rotate(temp,mLocalRotation.x,glm::vec3(1,0,0));
	temp = glm::rotate(temp, mLocalRotation.y, glm::vec3(0, 1, 0));
	temp = glm::rotate(temp, mLocalRotation.z, glm::vec3(0, 0, 1));
	temp = glm::translate(temp, mLocalPosition);
	mLocalMat = temp;
	return mLocalMat;
}

HorizonEngine::Transform::Transform()
{
}

HorizonEngine::Transform::~Transform()
{
}


