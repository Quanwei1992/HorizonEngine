#pragma once
#include "Component.h"
#include "Material.h"
#include "Mesh.h"
namespace HorizonEngine
{
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();
		void material(Material& material);
		void mesh(Mesh& mesh);
	public:
		virtual void Start() override;
		virtual void OnPostRender() override;
		virtual void OnDestory() override;
	private:
		Material* mMat;
		Mesh*     mMesh;
		Renderable* mRenderable;
	};

}

