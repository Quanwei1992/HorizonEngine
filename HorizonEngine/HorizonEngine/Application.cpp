#include "Application.h"
#include "Camera.h"
#include <vector>


using namespace HorizonEngine;

void Application::Run(Scene & scene)
{
	mScene = &scene;
	Init();
	mScene->Start();

	while (!glfwWindowShouldClose(this->mWindow))
	{
		Update();
		RenderOneFrame();
	}

	// 清理资源
}

void HorizonEngine::Application::PostRenderable(Renderable & renderable)
{
}

Application::Application()
{
}


Application::~Application()
{
}

void Application::Init()
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

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Application::Update()
{
	glfwPollEvents();

	// Set frame time
	double currentFrame = glfwGetTime();
	double deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	mScene->Update(deltaTime);
}

void Application::Render(const Camera & camera)
{
	//清理framebuffer.
	//设置view矩阵
	//设置projection矩阵。

	//对于每一个RenderAble.
	//设置RenderSystem的状态。
		//绑定Shader。
		//绑定材质。
	//使用RenderSystem执行RenderOp;
	//完成。
}



void Application::RenderOneFrame()
{
	auto& objects = mScene->GetAllObjects();
	// 获得场景中的相机.
	std::vector<Camera*> cameras;
	for (auto& obj : objects)
	{
		auto& components = obj->GetComponents();
		for (auto component : components)
		{
			component->OnPostRender();
			auto* camera = dynamic_cast<Camera*>(component);
			if (camera != nullptr)
			{
				cameras.push_back(camera);
			}
		}
	}
	for (auto* camera : cameras)
	{
		Render(*camera);
	}
	// clear render queue.
	mRenderQueue.clear();
}


