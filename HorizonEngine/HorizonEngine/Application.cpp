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

	// ������Դ
}

Application::Application()
{
}


Application::~Application()
{
}

void HorizonEngine::Application::Init()
{
	// ��ʼ��OPENGL
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
	// ��ó����е����.
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

	// ÿ�������ʼ��Ⱦ
	for (int i = 0;i<cameras.size();i++)
	{
		auto camera = cameras[i];
		
	}

	// ��Shader���������.
	// ��ó����е�ÿһ��GameObject.
	// ��Ⱦ.
	glfwSwapBuffers(mWindow);
}
