#include "stdafx.h"
#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::init()
{
	mLogSystem = std::make_shared<LogSystem>();
	mRenderSystem = std::make_shared<RenderSystem>();

	mLogSystem->startUp();
	mRenderSystem->startUp();
}

void Application::run()
{

	auto renderWindow = mRenderSystem->getRenderWindow();
	while (!renderWindow->shouldClose())
	{
		renderWindow->pollEvents();
		renderWindow->swapBuffers();
	}
}

void Application::shutdown()
{
	if(mRenderSystem)mRenderSystem->shutDown();
	if (mLogSystem)mLogSystem->shutDown();
}

std::shared_ptr<LogSystem> Application::getLogSystem()
{
	return mLogSystem;
}

