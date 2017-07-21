#include "stdafx.h"
#include "Transform.h"
#include <algorithm> 
Transform::Transform()
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

void Transform::setParent(const TransformPtr & parent)
{
	//// 从原来的Parent移除
	//if (mParent){
	//	mParent->removeChild(getOnwer()->getTransform());
	//}
	//mParent = parent;
	//if (mParent)
	//{
	//	mParent->addChild(getOnwer()->getTransform());
	//}
}

TransformPtr Transform::getParent() const
{
	return mParent;
}

void Transform::addChild(const TransformPtr & child)
{
	assert(child);
	mChildren.push_back(child);
}

void Transform::removeChild(const TransformPtr & child)
{
	assert(child);
	auto iter = std::find(mChildren.begin(), mChildren.end(), child);
	if (iter != mChildren.end()) {
		mChildren.erase(iter);
	}
}

