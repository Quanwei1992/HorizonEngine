#pragma once
#include <memory>
#include "Core/LogSystem.h"
#include "RenderSystem/RenderSystem.h"
#include "SceneSystem/SceneSystem.h"
class Application
{
public:
	Application();
	~Application();
	void init();
	void run();
	void shutdown();

	std::shared_ptr<LogSystem> getLogSystem();
	std::shared_ptr<SceneSystem> getSceneSystem();

private:
	std::shared_ptr<LogSystem> mLogSystem;
	std::shared_ptr<RenderSystem> mRenderSystem;
	std::shared_ptr<SceneSystem> mSceneSystem;

public:
	static Application& getSingleton()
	{
		static Application theSingleton;
		return theSingleton;
	}
};
