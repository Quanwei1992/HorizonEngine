#include "stdafx.h"
#include "SceneSystem.h"
#include "Component/Transform.h"
#include <memory>
SceneSystem::SceneSystem():
	mRunningScene(std::make_shared<Scene>())
{

}

SceneSystem::~SceneSystem()
{
}

void SceneSystem::startUp()
{

	//std::shared_ptr<Transform> transform = std::make_shared<Transform>();
	//std::shared_ptr<Component> component = std::make_shared<Component>(transform);

	//Scene* scene = new Scene();
	//auto go = new GameObject();
	//scene->addComponent<Transform>(*go);
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
