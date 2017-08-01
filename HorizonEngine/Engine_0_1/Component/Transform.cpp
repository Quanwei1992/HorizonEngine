#include "stdafx.h"
#include "Transform.h"
#include <algorithm> 


const Vector3 Transform::getPosition() const
{
	return mPosition;
}

const Vector3 Transform::getRotation() const
{

	return mRotation;
}

const Vector3 Transform::getScale() const
{
	return mScale;
}

void Transform::setPosition(const Vector3 & pos)
{
	mPosition = pos;
	mIsDirty = true;
}

void Transform::setRotation(const Vector3 & rot)
{
	mRotation = rot;
	mIsDirty = true;
}

void Transform::setScale(const Vector3 & scale)
{
	mScale = scale;
	mIsDirty = true;
}

const Matrix4x4 Transform::getWorldMatrix() const
{
	return Matrix4x4();
}

const Matrix4x4 Transform::getLocalMatrix() const
{
	return mLocalMatrix;
}

void Transform::setParent(const std::shared_ptr<Transform>& parent)
{
	// remove form old parent
	if (auto pOldParent = mParent.lock()) {
		pOldParent->removeChild(shared_from_this());
	}
	if (parent) {
		parent->addChild(shared_from_this());
	}
	else
	{
		mParent = parent;
	}
}

std::weak_ptr<Transform> Transform::getParent() const
{
	return mParent;
}

void Transform::addChild(const std::shared_ptr<Transform>& child)
{
	auto pChild = child;
	if (!pChild)return;
	// 先查找是否重复添加.
	auto result = std::find(mChildren.begin(), mChildren.end(), child);
	if (result != mChildren.end())return;
	mChildren.push_back(child);
}

void Transform::removeChild(const std::shared_ptr<Transform>& child)
{
	auto result = std::find(mChildren.begin(), mChildren.end(), child);
	if (result != mChildren.end()) {
		mChildren.erase(result);
		auto pChild = child;
		if (pChild) {
			pChild->setParent(std::shared_ptr<Transform>());
		}
	}
}
