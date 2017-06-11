#pragma once
#include "Scene.h"
class HelloWorldScene : public HorizonEngine::Scene
{
public:
	virtual void Start() override;
	HelloWorldScene();
	~HelloWorldScene();
};

