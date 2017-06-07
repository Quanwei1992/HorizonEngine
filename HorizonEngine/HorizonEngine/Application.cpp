#include "Application.h"

// GLEW
#define GLEW_STATIC
#include <ThirdPart/Includes/GL/glew.h>

// GLFW
#include <ThirdPart/Includes/GLFW/glfw3.h>
using namespace HorizonEngine;

void HorizonEngine::Application::Run(Scene & scene)
{
	// 初始化OPENGL
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(window);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, 800, 600);

	// 开始游戏循环
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		// Set frame time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		scene.Update(deltaTime);
		scene.Render();
		glfwSwapBuffers(window);
	}

	// 清理资源
}

Application::Application()
{
}


Application::~Application()
{
}
