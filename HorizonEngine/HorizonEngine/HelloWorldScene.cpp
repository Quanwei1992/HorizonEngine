#include "HelloWorldScene.h"
#include "GameObject.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "Application.h"
#include "Material.h"
using namespace HorizonEngine;
void HelloWorldScene::Start()
{
	GameObject & go = this->CreateGameObject();
	auto camera = go.AddComponent<Camera>();
	auto& cam_trans = camera.getOnwer().transform();
	cam_trans.localPosition(glm::vec3(0, 0, 10));
	cam_trans.localRotation(glm::vec3(0, 0, 30));
	const Shader& sampleShader = Application::getSingleton().resourceManager().LoadShader("sample");
	Material* mat = new Material(sampleShader);

	Mesh* mesh = new Mesh();
	std::vector<float> vertices = {
		-0.5f, -0.5f, 0.0f,   // 右上角
		0.5f, 0.5f, 0.0f,  // 右下角
		0.5f, -0.5f, 0.0f, // 左下角
		-0.5f, 0.5f, 0.0f   // 左上角
	};
	std::vector<unsigned int>indices = {
		0, 1,2, // 第一个三角形
		1, 0,3  // 第二个三角形
	};
	mesh->vertices(vertices);
	mesh->indices(indices);


	auto& quad = this->CreateGameObject();
	MeshRenderer& meshRender = quad.AddComponent<MeshRenderer>();
	meshRender.material(*mat);
	meshRender.mesh(*mesh);
	quad.transform().localRotation(glm::vec3(0,0,30));


	Scene::Start();
}

HelloWorldScene::HelloWorldScene()
= default;


HelloWorldScene::~HelloWorldScene()
= default;
