#include "stdafx.h"
#include "Application.h"

using namespace HorizonEngine;
Application::Application()
{
}

Application::~Application()
{
}

void HorizonEngine::Application::init()
{
	mLogSystem = std::make_shared<LogSystem>();
	mRenderSystem = std::make_shared<RenderSystem>();

	mLogSystem->startUp();
	mRenderSystem->startUp();
}

void HorizonEngine::Application::run()
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

std::shared_ptr<LogSystem> HorizonEngine::Application::getLogSystem()
{
	return this->mLogSystem;
}

