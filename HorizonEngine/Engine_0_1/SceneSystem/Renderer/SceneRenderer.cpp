#include "stdafx.h"
#include <algorithm>
#include "SceneRenderer.h"
#include "Component/Transform.h"
#include "Component/Renderer.h"
#include "Component/Behaviour.h"
#include "Component/Light.h"

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
	std::vector<std::shared_ptr<Light>> lightes;

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
				else if (LightPtr pLight = std::dynamic_pointer_cast<Light>(component)) {
					lightes.push_back(pLight);
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

	// 根据相机Depth进行排序. Depth值越小,越先绘制
	std::sort(cameras.begin(), cameras.end(), [](const CameraPtr& cameraA, const CameraPtr& cameraB) {
		if (cameraA->getDepth() < cameraB->getDepth()) {
			return true;
		}
		return false;
	});

	auto renderSys = Application::getSingleton().getRenderSystem();
	auto renderWindow = renderSys->getRenderWindow();
	unsigned int window_width = renderWindow->getWidth();
	unsigned int window_height = renderWindow->getHeight();
	// render
	for (auto camera : cameras)
	{
		// 设置viewport
		auto viewPort = camera->getViewport();

		int vx = (int)(viewPort.x * window_width);
		int vy = (int)(viewPort.y * window_height);
		int vw = (int)(viewPort.z * window_width);
		int vh = (int)(viewPort.w * window_height);
		renderSys->setViewport(vx,vy,vw,vh);
		// 设置view矩阵
		renderSys->setViewMatrix(camera->getViewMatrix());
		// 设置投影矩阵
		renderSys->setProjectionMatrix(camera->getProjectionMatrix());
		// clear
		auto clearFlag = camera->getClearFlag();
		if (clearFlag == Camera::ClearFlags::SolidColor) {
			renderSys->setClearColor(camera->getClearColor());
			renderSys->Clear(true, false, false);
		}else if (clearFlag == Camera::ClearFlags::Depth)
		{
			renderSys->Clear(false,true, false);
		}else if (clearFlag == Camera::ClearFlags::ColorAndDepth)
		{
			renderSys->setClearColor(camera->getClearColor());
			renderSys->Clear(true, true, false);
		}
		// 用RenderPath处理Lights和Renderables.
	}
}
