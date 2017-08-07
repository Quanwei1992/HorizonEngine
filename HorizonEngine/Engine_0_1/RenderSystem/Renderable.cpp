#include "stdafx.h"
#include "Renderable.h"

Renderable::Renderable(const MaterialPtr & material, const Matrix4x4 & modelMatrix, const RenderOperationPtr & renderOp)
{
	mMaterial = material;
	mModelMatrix = modelMatrix;
	mRenderOp = renderOp;
}

MaterialPtr Renderable::getMaterial() const
{
	return mMaterial;
}

Matrix4x4 Renderable::getModelMatrix() const
{
	return mModelMatrix;
}

RenderOperationPtr Renderable::getRenderOperation() const
{
	return mRenderOp;
}
