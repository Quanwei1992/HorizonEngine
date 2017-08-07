#pragma once
#include <vector>
#include <memory>
#include "RenderPath.h"
class ForwardRenderPath : RenderPath
{
public:
	ForwardRenderPath() = default;
	~ForwardRenderPath() = default;
	void render(const CameraPtr& camera, const std::vector<RenderablePtr>& renderabls) override;
};
using ForwardRenderPathPtr = std::shared_ptr<ForwardRenderPath>;
