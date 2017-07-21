#pragma once
#include <memory>
#include <vector>
#include "Component/Component.h"
#include "SceneSystem/Scene.h"
class GameObject
{
public:

	GameObject();
	~GameObject() = default;

	bool isValid() const;
private:

};
typedef std::shared_ptr<GameObject> GameObjectPtr;