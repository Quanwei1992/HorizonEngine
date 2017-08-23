#include "MeshRenderer.h"
#include "stdafx.h"


MeshRenderer::MeshRenderer():
	mDirty(true)
{
}

void MeshRenderer::setMesh(const MeshPtr & mesh)
{
	if (mesh != mMesh) {
		mMesh = mesh;
		mDirty = true;
	}
}

void MeshRenderer::setMaterial(const MaterialPtr & material)
{
	if (mMaterial != material) {
		mMaterial = material;
		mDirty = true;
	}
}

MeshPtr MeshRenderer::getMesh() const
{
	return mMesh;
}

MaterialPtr MeshRenderer::getMaterial() const
{
	return mMaterial;
}


void MeshRenderer::preRender()
{
	if (!mMaterial || !mMesh || !mDirty) {
		return;
	}

	RenderOperationPtr op = std::make_shared<RenderOperation>(RenderOperation::OperationType::TriangleList, mMesh->getVertexData());
	
	auto modelMatrix = getOnwer().lock()->getComponent<Transform>().lock()->getWorldMatrix();
	mRenderable = std::make_shared<Renderable>(mMaterial,modelMatrix,op);
	mDirty = false;
}

RenderablePtr MeshRenderer::render()
{
	return mRenderable;
}
