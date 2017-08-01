#include "stdafx.h"
#include <typeinfo>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "Application.h"


Application::Application():
	mFPS(60)
{
}

Application::~Application()
{
}

void Application::init()
{
	mTimeSystem = std::make_shared<TimeSystem>();
	mLogSystem = std::make_shared<LogSystem>();
	mRenderSystem = std::make_shared<RenderSystem>();
	mSceneSystem = std::make_shared<SceneSystem>();

	mTimeSystem->startUp();
	mLogSystem->startUp();
	mRenderSystem->startUp();
	mSceneSystem->startUp();
}

void Application::run()
{
	auto renderWindow = mRenderSystem->getRenderWindow();
	double msPerFrame = 1000.0f / mFPS;
	double lastTime = mTimeSystem->getCurrentTime();
	double fps = 60.0f;

	while (!renderWindow->shouldClose())
	{
		double current = mTimeSystem->getCurrentTime();
		double elapsed = current - lastTime;
		lastTime = current;
		renderWindow->pollEvents();
		mSceneSystem->update(elapsed);
		mSceneSystem->render();
		renderWindow->swapBuffers();
	}
}

void Application::shutdown()
{
	if(mRenderSystem)mRenderSystem->shutDown();
	if (mLogSystem)mLogSystem->shutDown();
	if (mSceneSystem)mSceneSystem->shutDown();
	if (mTimeSystem)mTimeSystem->shutDown();
}

std::shared_ptr<LogSystem> Application::getLogSystem()
{
	return mLogSystem;
}

std::shared_ptr<SceneSystem> Application::getSceneSystem()
{
	return mSceneSystem;
}

std::shared_ptr<TimeSystem> Application::getTimeSystem()
{
	return mTimeSystem;
}

