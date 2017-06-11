#pragma once
#include "RenderSystem/RenderOperation.h"
class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();
public:
	void Render(const RenderOperation& op);

private:

};

RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

inline void RenderSystem::Render(const RenderOperation & op)
{
}
