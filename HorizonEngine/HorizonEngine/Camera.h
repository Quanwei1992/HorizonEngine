#pragma once
#include "Component.h"
#include "ThirdPart/Includes/glm/glm.hpp"
namespace HorizonEngine
{
	class Camera : public Component
	{
	public:
		float fov;
		float aspect;
		float near;
		float far;
	public:
		glm::mat4 projectionMatrix() const;
		glm::mat4 viewMatrix() const;

	public:
		Camera();
		~Camera();
	};

}

