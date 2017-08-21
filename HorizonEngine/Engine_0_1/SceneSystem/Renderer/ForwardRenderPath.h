#pragma once
#include <vector>
#include <memory>
#include "RenderPath.h"
//////////////////////////////////////////////////////////////////////////
// ǰ����Ⱦ����
//////////////////////////////////////////////////////////////////////////
class ForwardRenderPath : RenderPath
{
public:
	ForwardRenderPath() = default;
	~ForwardRenderPath() = default;
	void render(const CameraPtr& camera, const std::vector<RenderablePtr>& renderabls, const std::vector<LightPtr>& lights) override;
};
using ForwardRenderPathPtr = std::shared_ptr<ForwardRenderPath>;
