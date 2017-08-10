#include "stdafx.h"
#include "RenderWindow.h"


RenderWindow::RenderWindow(unsigned int width, unsigned int height, std::string title):
	mGLWindow(nullptr),
	mWidth(width),
	mHeight(height)
{
	auto logsys = Application::getSingleton().getLogSystem();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	mGLWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(mGLWindow);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		logsys->log("init glew failed!");
		return;
	}
}


RenderWindow::~RenderWindow()
{
	if (mGLWindow)
	{
		glfwDestroyWindow(mGLWindow);
		mGLWindow = nullptr;
	}
}

bool RenderWindow::shouldClose()
{
	if (this->mGLWindow)
	{
		return glfwWindowShouldClose(this->mGLWindow);
	}
	return false;
}

void RenderWindow::swapBuffers()
{
	if (mGLWindow)
	{
		glfwSwapBuffers(mGLWindow);
	}
}

void RenderWindow::pollEvents()
{
	glfwPollEvents();
}

void RenderWindow::setTitle(const std::string & title)
{
	glfwSetWindowTitle(mGLWindow, title.c_str());
}

unsigned int RenderWindow::getWidth() const
{
	return mWidth;
}

unsigned int RenderWindow::getHeight() const
{
	return mHeight;
}
