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
