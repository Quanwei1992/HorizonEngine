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
		const vec3& GetLocalPosition() { return mLocalPosition; }
		void		SetLocalPosition(const vec3& position) { mLocalPosition = position; }

		const vec3& GetPosition();

		void parent(Transform& parent);
		Transform* parent() { return mParent; }

	private:
		// localTransform
		vec3 mLocalPosition;
		vec3 mLocalScale;
		vec3 mLocalRotation;
		mat4 mLocalMat;
		mat4 mWorldMat;

		Transform* mParent;
		std::vector<Transform> mChidren;
	private:
		const glm::mat4x4& Combine();

	public:
		Transform();
		~Transform();

	};


}
