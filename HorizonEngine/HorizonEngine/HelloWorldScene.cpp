#include "HelloWorldScene.h"
#include "GameObject.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "Transform.h"
using namespace HorizonEngine;
void HelloWorldScene::Start()
{
	GameObject & go = this->CreateGameObject();
	auto camera = go.AddComponent<Camera>();
	auto meshRender = go.AddComponent<MeshRenderer>();

	Transform a;
	a.localPosition(glm::vec3(0, 0, 0));
	a.localRotation(glm::vec3(0,180.0f,0));
	Transform b;
	b.parent(a);
	b.localPosition(glm::vec3(10,5,1));

	auto world = b.worldPosition();

	Scene::Start();
}

HelloWorldScene::HelloWorldScene()
= default;


HelloWorldScene::~HelloWorldScene()
= default;
