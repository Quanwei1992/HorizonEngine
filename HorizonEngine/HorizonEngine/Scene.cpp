#include "Scene.h"
using namespace HorizonEngine;


GameObject& Scene::CreateGameObject()
{
	GameObject* go = new GameObject();
	mObjects.push_back(go);
	return *go;
}

std::vector<GameObject*>& Scene::GetAllObjects()
{
	return mObjects;
}

void Scene::Start()
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		mObjects[i]->Start();
	}
}

void Scene::Destory()
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		mObjects[i]->Destory();
	}
}

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Update(double deltaTime)
{
	
}
