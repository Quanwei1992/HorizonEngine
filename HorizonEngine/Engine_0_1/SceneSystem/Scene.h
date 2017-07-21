#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "Component/Component.h"
class Scene
{
public:
	Scene() = default;
	~Scene() = default;
	template<typename T> std::weak_ptr<T> addComponent(const GameObject& go);
	template<typename T> std::weak_ptr<T> getComponent(const GameObject& go);
private:
	// <type_hash_code,component>
	std::vector<std::pair<size_t,std::shared_ptr<Component>>> mAllComponents;
};
typedef std::shared_ptr<Scene> ScenePtr;

template<typename T>
inline std::weak_ptr<T> Scene::addComponent(const GameObject & go)
{




	//if (go.isValid()) {
	//	std::shared_ptr<Transform> component = std::make_shared<Transform>();
	//	auto typeInfo = typeid(Transform);
	//	auto p = std::make_pair<size_t, std::shared_ptr<Component>>(typeInfo.hash_code(), component);
	//	mAllComponents.push_back(p);
	//	return std::weak_ptr<Transform>(component);
	//}
	return std::weak_ptr<T>();
}

template<typename T> std::weak_ptr<T>
Scene::getComponent(const GameObject& go)
{

}
