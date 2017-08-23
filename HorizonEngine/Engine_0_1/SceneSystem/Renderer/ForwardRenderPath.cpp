#include "stdafx.h"
#include "ForwardRenderPath.h"

void ForwardRenderPath::render(const CameraPtr& camera, const std::vector<RenderablePtr>& renderabls, const std::vector<LightPtr>& lights)
{
	auto renderSystem = Application::getSingleton().getRenderSystem();
	for (auto renderable : renderabls)
	{
		auto model = renderable->getModelMatrix();
		renderSystem->setModelMatrix(model);
		renderSystem->setMaterial(renderable->getMaterial());
		renderSystem->render(renderable->getRenderOperation());
	}
}
