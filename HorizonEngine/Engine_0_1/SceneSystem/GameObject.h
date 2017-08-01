#pragma once
#include <memory>
#include <vector>
#include "Component/Component.h"

class Scene;
class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	GameObject() = default;
	~GameObject() = default;
	std::weak_ptr<Component> addComponent();
private:
	friend Scene;
	void onAwake();
	void onDestory();
private:
	std::vector<ComponentPtr> mComponents;
};
typedef std::shared_ptr<GameObject> GameObjectPtr;