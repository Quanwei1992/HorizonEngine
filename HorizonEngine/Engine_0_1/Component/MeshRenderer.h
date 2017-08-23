#pragma once
#include "Renderer.h"
#include "Resouce/Mesh.h"
#include "RenderSystem/Material/Material.h"
class MeshRenderer : public Renderer
{
public:
	MeshRenderer();
	~MeshRenderer() override = default;

	void setMesh(const MeshPtr& mesh);
	void setMaterial(const MaterialPtr& material);

	MeshPtr getMesh() const;
	MaterialPtr getMaterial() const;

	virtual void preRender() override;
	virtual RenderablePtr render() override;

private:
	MeshPtr mMesh;
	MaterialPtr mMaterial;
	RenderablePtr mRenderable;
	bool mDirty;
};

