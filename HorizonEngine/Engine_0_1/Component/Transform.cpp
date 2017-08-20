#include "stdafx.h"
#include "Transform.h"
#include <algorithm> 


Transform::Transform():
	mPosition(0,0,0)
	,mRotation(0,0,0)
	,mScale(1,1,1)
	,mWorldDirty(true)
	,mIsDirty(true)
{

}

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
	markDirty();
}

void Transform::setRotation(const Vector3 & rot)
{
	mRotation = rot;
	markDirty();
}

void Transform::setScale(const Vector3 & scale)
{
	mScale = scale;
	markDirty();
}

const Matrix4x4 Transform::getWorldMatrix() const
{
	if (mWorldDirty) {
		if (auto parent = mParent.lock()) {
			mWorldMatrix = parent->getWorldMatrix() * parent->getLocalMatrix();
			mWorldDirty = false;
		}
	}
	return mWorldMatrix;
}

const Matrix4x4 Transform::getLocalMatrix() const
{
	if (mIsDirty) {
		mLocalMatrix = Transform::Combine(mPosition, mRotation, mScale);
		mIsDirty = false;
	}
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

void Transform::setWorldMatrixDirty()
{
	mWorldDirty = true;
}

void Transform::markDirty()
{
	mIsDirty = true;
	for (auto child : mChildren)
	{
		if (child) {
			child->setWorldMatrixDirty();
		}
	}
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

const Matrix4x4 Transform::Combine(Vector3 pos, Vector3 rot, Vector3 scale)
{
	Matrix4x4 mat;
	mat = glm::scale(mat, scale);
	mat = glm::rotate(mat, glm::radians(rot.x), Vector3(1, 0, 0));
	mat = glm::rotate(mat, glm::radians(rot.y), Vector3(0, 1, 0));
	mat = glm::rotate(mat, glm::radians(rot.z), Vector3(0, 0, 1));
	mat = glm::translate(mat, pos);
	return mat;
}
