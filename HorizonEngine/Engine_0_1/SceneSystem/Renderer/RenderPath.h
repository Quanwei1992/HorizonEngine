#pragma once
#include <vector>
#include <memory>
#include "Component/Camera.h"
#include "Component/Light.h"
#include "RenderSystem/Renderable.h"

class RenderPath
{
public:
	RenderPath() = default;
	~RenderPath() = default;
	virtual void render(const CameraPtr& camera, const std::vector<RenderablePtr>& renderabls,const std::vector<LightPtr>& lights) = 0;
};
using RenderPathPtr = std::shared_ptr<RenderPath>;
