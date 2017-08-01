#pragma once
#include <memory>
#include <vector>
class GameObject;
class Component
{
public:
	Component() = default;
	virtual ~Component() = default;
	std::weak_ptr<GameObject> getOnwer() const;
private:
	friend GameObject;

	void setOnwer(std::shared_ptr<GameObject> onwer);
	virtual void onAwake();
	virtual void onDestory();
private:
	std::weak_ptr<GameObject> mOnwer;
};
typedef std::shared_ptr<Component> ComponentPtr;