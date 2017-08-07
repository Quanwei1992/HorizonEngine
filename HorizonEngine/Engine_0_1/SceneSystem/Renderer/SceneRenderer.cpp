#include "stdafx.h"
#include "SceneRenderer.h"
#include "Component/Transform.h"
#include "Component/Renderer.h"
#include "Component/Behaviour.h"

SceneRenderer::SceneRenderer()
{
	mRenderPath = std::make_shared<ForwardRenderPath>();
}

void SceneRenderer::render(const ScenePtr & scene)
{
	assert(scene);
	assert(mRenderPath);
	auto objs = scene->getAllGameObjects();
	std::vector<std::shared_ptr<Camera>> cameras;
	std::vector<std::shared_ptr<Renderer>> renderers;

	// find all camera and renderer
	for (auto weak_obj : objs)
	{
		auto obj = weak_obj.lock();
		if (!obj)continue;
		auto components = obj->getAllCompoents();
		for (auto weak_component : components) {
			auto component = weak_component.lock();
			if (component) {
				if (CameraPtr pCamera = std::dynamic_pointer_cast<Camera>(component)) {
					cameras.push_back(pCamera);
				}
				else if (RendererPtr pRenderer = std::dynamic_pointer_cast<Renderer>(component))
				{
					renderers.push_back(pRenderer);
				}
			}
		}
	}

	std::vector<RenderablePtr> renderables;
	// generate renderables.
	for (auto renderer:renderers)
	{
		renderer->preRender();
	}
	for (auto renderer : renderers)
	{
		auto renderable = renderer->render();
		if (renderable) {
			renderables.push_back(renderable);
		}
	}
	for (auto renderer : renderers)
	{
		renderer->afterRender();
	}

	// render
	for (auto camera : cameras)
	{

	}
}
