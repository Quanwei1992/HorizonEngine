#pragma once
#include <memory>
#include "Core/LogSystem.h"
#include "Core/TimeSystem.h"
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
	std::shared_ptr<TimeSystem> getTimeSystem();
	std::shared_ptr<RenderSystem> getRenderSystem();

private:
	std::shared_ptr<LogSystem> mLogSystem;
	std::shared_ptr<RenderSystem> mRenderSystem;
	std::shared_ptr<SceneSystem> mSceneSystem;
	std::shared_ptr<TimeSystem> mTimeSystem;

	float mFPS;

public:
	static Application& getSingleton()
	{
		static Application theSingleton;
		return theSingleton;
	}
};
