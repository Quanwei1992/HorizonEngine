#include "Application.h"
#include "Camera.h"
#include <vector>


using namespace HorizonEngine;

void HorizonEngine::Application::Run(Scene & scene)
{
	mScene = scene;
	Init();


	while (!glfwWindowShouldClose(this->mWindow))
	{
		Update();
		Render();
	}

	// 清理资源
}

Application::Application()
{
}


Application::~Application()
{
}

void HorizonEngine::Application::Init()
{
	// 初始化OPENGL
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	this->mWindow = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(this->mWindow);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, 800, 600);
}

void HorizonEngine::Application::Update()
{
	glfwPollEvents();

	// Set frame time
	GLfloat currentFrame = glfwGetTime();
	float deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	mScene.Update(deltaTime);
}

void HorizonEngine::Application::Render()
{
	// 获得场景中的相机.
	std::vector<Camera*> cameras;
	auto objects = mScene.GetAllObjects();
	for (int i =0;i<objects.size();i++)
	{
		auto obj = objects[i];
		auto components = obj->GetComponents();
		for (int j =0;j<components.size();j++)
		{
			Camera* camera = dynamic_cast<Camera*>(components[i]);
			if (camera != nullptr)
			{
				cameras.push_back(camera);
			}
		}
	}

	// 每个相机开始渲染
	for (int i = 0;i<cameras.size();i++)
	{
		auto camera = cameras[i];
		
	}

	// 向Shader传相机矩阵.
	// 获得场景中的每一个GameObject.
	// 渲染.
	glfwSwapBuffers(mWindow);
}
