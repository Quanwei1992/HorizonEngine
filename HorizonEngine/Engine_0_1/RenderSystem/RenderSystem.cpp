#include "stdafx.h"
#include "RenderSystem.h"

using namespace HorizonEngine;
RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::startUp()
{
	auto logsys = Application::getSingleton().getLogSystem();
	logsys->log("RenderSystem.InitGLContext");
	glfwInit();
	this->mRenderWindow = this->createRenderWindow(800,600,"Demo");
	this->setRenderTarget(this->mRenderWindow);

}

void RenderSystem::shutDown()
{
	glfwTerminate();
}

std::shared_ptr<RenderWindow> RenderSystem::getRenderWindow()
{
	return this->mRenderWindow;
}

void RenderSystem::setRenderTarget(std::shared_ptr<RenderTarget> target)
{
	this->mRenderTarget = target;
}

std::shared_ptr<RenderTarget> RenderSystem::getRenderTarget()
{
	return this->mRenderTarget;
}

void RenderSystem::setViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}

void RenderSystem::setViewMatrix(glm::mat4x4 viewMat)
{

}

void RenderSystem::setProjectionMatrix(glm::mat4x4 viewMat)
{

}

void RenderSystem::render(const RenderOperation & op)
{

}

std::shared_ptr<RenderWindow> HorizonEngine::RenderSystem::createRenderWindow(unsigned int width, unsigned int height, std::string title)
{
	RenderWindow* rw = new RenderWindow(width, height, title);
	return std::shared_ptr<RenderWindow>(rw);
}

