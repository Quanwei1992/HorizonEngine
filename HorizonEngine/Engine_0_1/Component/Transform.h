#pragma once
#include <memory>
#include <vector>

#include "Component.h"
#include "Math/Math.h"
class Transform;
typedef std::shared_ptr<Transform> TransformPtr;
class Transform:Component
{
public:
	Transform();
	~Transform() override = default;

	const Vector3 getPosition() const;
	const Vector3 getRotation() const;
	const Vector3 getScale() const;

	void setPosition(const Vector3& pos);
	void setRotation(const Vector3& rot);
	void setScale(const Vector3& scale);

	const Matrix4x4 getWorldMatrix() const;
	const Matrix4x4 getLocalMatrix() const;
	
	void setParent(const TransformPtr& parent);
	TransformPtr getParent() const;

private:
	void addChild(const TransformPtr& child);
	void removeChild(const TransformPtr& child);
private:
	TransformPtr mParent;
	std::vector<TransformPtr> mChildren;
	mutable Matrix4x4 mWorldMatrix;
	mutable Matrix4x4 mLocalMatrix;
	mutable bool mIsDirty;

	Vector3 mPosition;
	Vector3 mRotation;
	Vector3 mScale;
};

