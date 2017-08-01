#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "GameObject.h"
class SceneSystem;
class Scene
{
public:
	Scene() = default;
	~Scene() = default;
	
	std::weak_ptr<GameObject> createGameObject();
	void destoryGameObject(const std::weak_ptr<GameObject>& go);
	std::vector <std::weak_ptr<GameObject>> getAllGameObjects();
private:
	friend SceneSystem;
	void enter();
	void leave();
private:
	std::vector<GameObjectPtr> mGameObjects;

	
};
typedef std::shared_ptr<Scene> ScenePtr;




