#include "RenderWindow.h"


RenderWindow::RenderWindow(unsigned int width, unsigned int height, std::string title)
{
	this->glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(this->glfwWindow);

}

RenderWindow::~RenderWindow()
{
	
}

bool RenderWindow::ShoudClose()
{
	return glfwWindowShouldClose(this->glfwWindow);
}

void RenderWindow::SwapBuffers()
{
	glfwSwapBuffers(this->glfwWindow);
}
