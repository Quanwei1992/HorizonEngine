#pragma once
#include <memory>
#include <vector>

#include "Component.h"
#include "Math/Math.h"
class Transform : public Component,public std::enable_shared_from_this<Transform>
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
	
	void setParent(const std::shared_ptr<Transform>& parent);
	std::weak_ptr<Transform> getParent() const;

private:
	void setWorldMatrixDirty();
	void markDirty();
	void addChild(const std::shared_ptr<Transform>& child);
	void removeChild(const std::shared_ptr<Transform>& child);
	static const Matrix4x4 Combine(Vector3 pos, Vector3 rot, Vector3 scale);
private:
	std::weak_ptr<Transform> mParent;
	std::vector<std::shared_ptr<Transform>> mChildren;
	mutable Matrix4x4 mWorldMatrix;
	mutable Matrix4x4 mLocalMatrix;
	mutable bool mIsDirty;
	mutable bool mWorldDirty;

	Vector3 mPosition;
	Vector3 mRotation;
	Vector3 mScale;
	
};
typedef std::shared_ptr<Transform> TransformPtr;
