#pragma once
#include <memory>
#include "Core/System.h"
#include "Scene.h"
class SceneSystem : System
{
public:
	SceneSystem();
	~SceneSystem() override = default;
	void startUp() override;
	void shutDown() override;
	void update(double dt);
	void render();
	void enterScene(const ScenePtr& scene);

	std::weak_ptr<Scene> getRunningScene();
private:
	ScenePtr mRunningScene;
};

