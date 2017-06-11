#pragma once
#include "Component.h"
#include "Shader.h"
#include "Mesh.h"
namespace HorizonEngine
{
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();
	public:
		virtual void Start() override;
		virtual void OnPostRender() override;
		virtual void OnDestory() override;
	private:
		Mesh* mMesh;
		Shader* mShader;
	};

}

