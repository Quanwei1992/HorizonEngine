#include "Camera.h"
#include "ThirdPart/Includes/glm/gtc/matrix_transform.hpp"
#include "ThirdPart/Includes/glm/gtc/type_ptr.hpp"
#include "Transform.h"
#include "GameObject.h"
using namespace HorizonEngine;

glm::mat4 HorizonEngine::Camera::projectionMatrix() const
{
	glm::mat4x4 proj;
	proj = glm::perspective(fov, aspect,near,far);
	return proj;
}

glm::mat4 HorizonEngine::Camera::viewMatrix() const
{
	const GameObject& go =  this->getOnwer();
	const Transform& trans = go.transform();
	auto local2world = trans.worldMatrix() * trans.localMatrix();
	auto world2camera = glm::inverse(local2world);
	return world2camera;
}



HorizonEngine::Camera::Camera()
{
	fov = 45.0f;
	aspect = 1.7f;
	near = 0.1f;
	far = 1000.0f;
}

Camera::~Camera()
{
}
