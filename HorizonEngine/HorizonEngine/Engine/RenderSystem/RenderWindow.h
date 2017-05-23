#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
class RenderWindow
{
public:
	RenderWindow(unsigned int width,unsigned int height,std::string title);
	~RenderWindow();
public:
	bool ShoudClose();
	void SwapBuffers();

private:
	GLFWwindow* glfwWindow = nullptr;
	
};

