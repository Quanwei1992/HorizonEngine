#include "stdafx.h"
#include <memory>
#include <typeinfo>
#include "SceneSystem.h"
#include "Component/Transform.h"
#include "Component/Renderer.h"
#include "Component/Behaviour.h"
#include "Component/MeshRenderer.h"

SceneSystem::SceneSystem() :
	mRunningScene(std::make_shared<Scene>()),
	mRenderer(std::make_shared<SceneRenderer>())
{

}

void SceneSystem::startUp()
{
	auto cameraGo = mRunningScene->createGameObject().lock();
	auto camera = cameraGo->addComponent<Camera>().lock();
	camera->setDepth(15);
	camera->setClearColor(Color4f(0, 0, 0, 1));

	auto go = mRunningScene->createGameObject().lock();

	auto meshRenderer = go->addComponent<MeshRenderer>().lock();

	MeshPtr mesh = std::make_shared<Mesh>();
	std::vector<Vector3> vertices;
	vertices.emplace_back(Vector3(-0.5f, -0.5f, 0.0f));
	vertices.emplace_back(Vector3(0.5f, -0.5f, 0.0f));
	vertices.emplace_back(Vector3(0.0f, 0.5f, 0.0f));
	std::vector<int> mTriangles;
	mTriangles.emplace_back(0);
	mTriangles.emplace_back(1);
	mTriangles.emplace_back(2);

	mesh->setVertices(vertices);
	mesh->setTriangles(mTriangles);

	// ´´½¨Program
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	GLShaderPtr vsShader = std::make_shared<GLShader>(GL_VERTEX_SHADER);
	vsShader->setSource(vertexShaderSource);
	vsShader->compile();
	GLShaderPtr fsShader = std::make_shared<GLShader>(GL_FRAGMENT_SHADER);
	fsShader->setSource(fragmentShaderSource);
	fsShader->compile();
	GLProgramPtr program = std::make_shared<GLProgram>();
	program->attachShader(vsShader);
	program->attachShader(fsShader);
	program->link();

	MaterialPtr material = std::make_shared<Material>(program);
	meshRenderer->setMesh(mesh);
	meshRenderer->setMaterial(material);
}

void SceneSystem::shutDown()
{
	if (mRunningScene) {
		mRunningScene->leave();
	}
}

void SceneSystem::update(double dt)
{

}

void SceneSystem::render()
{
	assert(mRunningScene);
	mRenderer->render(mRunningScene);
}

void SceneSystem::enterScene(const ScenePtr & scene)
{
	if (scene && mRunningScene != scene) {
		if (mRunningScene) {
			mRunningScene->leave();
		}
		mRunningScene = scene;
		mRunningScene->enter();
	}
}

std::weak_ptr<Scene> SceneSystem::getRunningScene()
{
	return std::weak_ptr<Scene>(mRunningScene);
}
