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
	auto go1 =  mRunningScene->createGameObject().lock();
	auto camera1 = go1->addComponent<Camera>().lock();
	camera1->setDepth(15);
	camera1->setClearColor(Color4f(1, 0, 0, 1));
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
