#include "Application.h"
#include "MeshRenderer.h"
#include <GL/glew.h>
#include <iostream>
// GLFW
#include <GLFW/glfw3.h>
using namespace HorizonEngine;

MeshRenderer::MeshRenderer():
	mMat(nullptr),
	mMesh(nullptr),
	mRenderable(nullptr)
{

}


MeshRenderer::~MeshRenderer()
= default;

void HorizonEngine::MeshRenderer::material(Material & material)
{
	mMat = &material;
}

void HorizonEngine::MeshRenderer::mesh(Mesh & mesh)
{
	mMesh = &mesh;
}

void HorizonEngine::MeshRenderer::Start()
{


	std::vector<float> vertices = {
		0.5f, 0.5f, 0.0f,   // 右上角
		0.5f, -0.5f, 0.0f,  // 右下角
		-0.5f, -0.5f, 0.0f, // 左下角
		-0.5f, 0.5f, 0.0f   // 左上角
	};
	std::vector<unsigned int>indices = {
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	GLchar const* vertexShaderSource = " \
		#version 330 core\n \
		layout (location = 0) in vec3 position;\n \
		void main()\n \
		{\n \
			gl_Position = vec4(position.x,position.y,position.z,1.0);\n \
		}\n";

	GLchar const* fragmentShaderSource = "\
		#version 330 core\n \
		out vec4 color;\n \
		void main()\n \
		{\n \
			color = vec4(1.0f,0.5f,0.2f,1.0f);\n \
		}\n";

}

void HorizonEngine::MeshRenderer::OnPostRender()
{
	if (mRenderable==nullptr)
	{

	}

	Application::getSingleton().PostRenderable(*mRenderable);
	return;
}

void HorizonEngine::MeshRenderer::OnDestory()
{


}
