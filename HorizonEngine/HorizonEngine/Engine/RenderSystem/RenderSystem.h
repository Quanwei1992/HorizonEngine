#pragma once
#include <Engine/Scene/Scene.h>
class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();
public:
	void Render(Scene& scene);
};

