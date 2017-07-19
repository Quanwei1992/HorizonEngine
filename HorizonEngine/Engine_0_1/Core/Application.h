#pragma once
#include <memory>
#include "Core/LogSystem.h"
#include "RenderSystem/RenderSystem.h"
class Application
{
public:
	Application();
	~Application();
	void init();
	void run();
	void shutdown();

	std::shared_ptr<LogSystem> getLogSystem();

private:
	std::shared_ptr<LogSystem> mLogSystem;
	std::shared_ptr<RenderSystem> mRenderSystem;

public:
	static Application& getSingleton()
	{
		static Application theSingleton;
		return theSingleton;
	}
};
