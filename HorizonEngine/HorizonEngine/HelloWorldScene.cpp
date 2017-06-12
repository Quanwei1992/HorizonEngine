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
	camera.getOnwer().transform().localPosition(glm::vec3(10, 10, 10));

	const Shader& sampleShader = Application::getSingleton().resourceManager().LoadShader("sample");
	Material* mat = new Material(sampleShader);

	Mesh* mesh = new Mesh();
	std::vector<float> vertices = {
		0.5f, 0.5f, 0.0f,   // ���Ͻ�
		0.5f, -0.5f, 0.0f,  // ���½�
		-0.5f, -0.5f, 0.0f, // ���½�
		-0.5f, 0.5f, 0.0f   // ���Ͻ�
	};
	std::vector<unsigned int>indices = {
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};
	mesh->vertices(vertices);
	mesh->indices(indices);


	MeshRenderer& meshRender = go.AddComponent<MeshRenderer>();
	meshRender.material(*mat);
	meshRender.mesh(*mesh);

	Scene::Start();
}

HelloWorldScene::HelloWorldScene()
= default;


HelloWorldScene::~HelloWorldScene()
= default;
