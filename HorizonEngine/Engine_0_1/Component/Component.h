#pragma once
#include <memory>
#include <vector>
#include "SceneSystem/GameObject.h"
class Component
{
public:
	Component();
	virtual ~Component() = default;
};
typedef std::shared_ptr<Component> ComponentPtr;