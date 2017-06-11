#pragma once
#include <vector>
#include <Component.h>
#include <ThirdPart/Includes/glm/glm.hpp>

using namespace glm;
namespace HorizonEngine
{
	class Transform : public Component
	{

	public:
		vec3	localPosition();
		void	localPosition(vec3 position);

		vec3	localRotation();
		void	localRotation(vec3 rotation);

		vec3	localScale();
		void	localScale(vec3 scale);

		mat4x4 localMatrix();

		vec3 worldPosition();
		mat4x4 worldMatrix();

		void parent(Transform& parent);
		Transform* parent() { return mParent; }

	private:
		// localTransform
		vec3 mLocalPosition;
		vec3 mLocalScale;
		vec3 mLocalRotation;
		mat4x4 mLocalMat;
		Transform* mParent;
		std::vector<Transform> mChidren;
	private:
		mat4x4 Combine(vec3 position,vec3 rotation,vec3 scale);
	public:
		Transform();
		~Transform();

	};


}
