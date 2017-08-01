#pragma once
#include <memory>
#include "Material/Material.h"
#include "RenderOperation.h"
#include "Math/Math.h"
class Renderable
{
public:
	Renderable(const MaterialPtr& material,const Matrix4x4& modelMatrix,const RenderOperationPtr& renderOp);
	~Renderable() = default;

	MaterialPtr getMaterial() const;
	Matrix4x4 getModelMatrix() const;
	RenderOperationPtr getRenderOperation() const;

private:
	MaterialPtr mMaterial;
	Matrix4x4 mModelMatrix;
	RenderOperationPtr mRenderOp;
};
using RenderablePtr = std::shared_ptr<Renderable>;
