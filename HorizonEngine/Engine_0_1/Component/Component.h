#pragma once
#include <memory>
#include <vector>
class GameObject;
class Component
{
public:
	Component(std::weak_ptr<GameObject> onwer);
	virtual ~Component() = default;
	
	std::weak_ptr<GameObject> getOnwer() const;
private:
	friend GameObject;
	virtual void onAwake();
	virtual void onDestory();
private:
	std::weak_ptr<GameObject> mOnwer;
};
typedef std::shared_ptr<Component> ComponentPtr;