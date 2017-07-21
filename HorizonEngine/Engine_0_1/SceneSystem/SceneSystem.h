#pragma once
#include <memory>
#include "Core/System.h"
#include "Scene.h"
class SceneSystem : System
{
public:
	SceneSystem();
	~SceneSystem() override;
	void startUp() override;
	void shutDown() override;

	std::weak_ptr<Scene> getScene();
private:
	ScenePtr mScene;
};

