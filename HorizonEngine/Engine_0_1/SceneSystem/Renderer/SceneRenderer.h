#pragma once
#include <memory>
#include "SceneSystem/Scene.h"
#include "SceneSystem/Renderer/ForwardRenderPath.h"
class SceneRenderer
{
public:
	SceneRenderer();
	~SceneRenderer() = default;
	void render(const ScenePtr& scene);

private:
	std::shared_ptr<ForwardRenderPath> mRenderPath;
};
using SceneRendererPtr = std::shared_ptr<SceneRenderer>;
