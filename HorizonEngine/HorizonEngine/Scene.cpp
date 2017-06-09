#include "Scene.h"
using namespace HorizonEngine;


GameObject HorizonEngine::Scene::CreateGameObject()
{
	GameObject* go = new GameObject();
	mObjects.push_back(go);
	return *go;
}

std::vector<GameObject*>& HorizonEngine::Scene::GetAllObjects()
{
	return mObjects;
}

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Update(float deltaTime)
{
	
}
