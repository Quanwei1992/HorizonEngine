#include "stdafx.h"
#include "SceneSystem.h"
#include "Component/Transform.h"
#include <memory>
SceneSystem::SceneSystem()
{

}

SceneSystem::~SceneSystem()
{
}

void SceneSystem::startUp()
{

	std::shared_ptr<Transform> transform = std::make_shared<Transform>();
	std::shared_ptr<Component> component = transform;

	Scene* scene = new Scene();
	auto go = new GameObject();
	scene->addComponent<Transform>(*go);
}

void SceneSystem::shutDown()
{

}

std::weak_ptr<Scene> SceneSystem::getScene()
{
	return std::weak_ptr<Scene>(mScene);
}
