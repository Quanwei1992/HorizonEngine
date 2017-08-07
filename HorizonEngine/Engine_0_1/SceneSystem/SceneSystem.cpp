#include "stdafx.h"
#include <memory>
#include <typeinfo>
#include "SceneSystem.h"
#include "Component/Transform.h"
#include "Component/Renderer.h"
#include "Component/Behaviour.h"

SceneSystem::SceneSystem():
	mRunningScene(std::make_shared<Scene>()),
	mRenderer(std::make_shared<SceneRenderer>())
{

}

void SceneSystem::startUp()
{
	auto go =  mRunningScene->createGameObject().lock();
	go->addComponent<Camera>();
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
