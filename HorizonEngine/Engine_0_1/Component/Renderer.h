#pragma once
#include "Component.h"
#include "RenderSystem/Renderable.h"
class Renderer: public Component
{
public:
	Renderer() = default;
	~Renderer() override = default;

	virtual void preRender() {}
	virtual RenderablePtr render() = 0;
	virtual void afterRender() {}
};
using RendererPtr = std::shared_ptr<Renderer>;
