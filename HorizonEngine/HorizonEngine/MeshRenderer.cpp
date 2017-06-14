#include "Application.h"
#include "MeshRenderer.h"
#include <GL/glew.h>
#include <iostream>
#include "RenderSystem/GL/VertexArray.h"
#include "RenderSystem/GL/ArrayBuffer.h"
#include "RenderSystem/GL/ElementArrayBuffer.h"
#include "RenderSystem/GL/GPUPragram.h"
#include "RenderSystem/GL/GPUProgramManager.h"

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

}

void HorizonEngine::MeshRenderer::OnPostRender()
{
	if (mMesh == nullptr || mMat == nullptr)return;

	if (mRenderable==nullptr)
	{
		// post mesh
		 BufferManager& buffermanager = Application::getSingleton().bufferManager();
		 GPUProgramManager& gpuProgramManager = Application::getSingleton().gpuProgramManager();
		 VertexArray& vao = buffermanager.GenVertexArray();
		 vao.Bind();
		 ArrayBuffer& vbo = buffermanager.GenArrayBuffer();
		 ElementArrayBuffer& ebo = buffermanager.GenElementArrayBuffer();
		 vbo.Write(mMesh->vertices().size() * sizeof(float), &mMesh->vertices()[0], GL_STATIC_DRAW);;
		 ebo.Write(mMesh->indices().size() * sizeof(unsigned int), &mMesh->indices()[0], GL_STATIC_DRAW);
		 vao.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
		 vao.EnableAttribArray(0);





		 vao.Unbind();
		 RenderOperation* op = new RenderOperation();
		 op->vertexArray = &vao;
		 op->UseIndices = true;
		 op->count = mMesh->indices().size();
		 op->mode = GL_TRIANGLES;


		 GPUPragram& program = gpuProgramManager.CreateProgram();
		 GLchar const* vertx_source = mMat->shader().vertexSource().c_str();
		 GLchar const* frament_source = mMat->shader().fragmentSource().c_str();
		 program.Attach(GL_VERTEX_SHADER,&vertx_source);
		 program.Attach(GL_FRAGMENT_SHADER, &frament_source);
		 program.Link();
		 
		 glm::mat4x4 mat = this->getOnwer().transform().worldMatrix() *  this->getOnwer().transform().localMatrix();
		 mRenderable = new Renderable(*op,program,mat);
	}

	Application::getSingleton().PostRenderable(*mRenderable);
	return;
}

void HorizonEngine::MeshRenderer::OnDestory()
{


}
