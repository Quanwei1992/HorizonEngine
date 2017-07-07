#include "Application.h"
#include "Camera.h"
#include <vector>
#include "ThirdPart/Includes/glm/glm.hpp"
#include "ThirdPart/Includes/glm/gtc/matrix_transform.hpp"

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
	mRenderQueue.push_back(&renderable);
}

BufferManager & HorizonEngine::Application::bufferManager()
{
	return *mBufferManager;
}

GPUProgramManager & HorizonEngine::Application::gpuProgramManager()
{
	return *mGPUPragramManager;
}

ResourceManager & HorizonEngine::Application::resourceManager()
{
	return *mResourceManager;
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

	mGPUPragramManager = new GPUProgramManager();
	mBufferManager = new BufferManager();
	mResourceManager = new ResourceManager();
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
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto view = camera.viewMatrix();


	auto projection = camera.projectionMatrix();
	//projection = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	// 注意，我们将矩阵向我们要进行移动场景的反方向移动。
	//view = glm::mat4x4();
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
	glm::vec4 pos(0,0,11,1.0f);
	glm::vec4 viewPos = view * pos;
	glm::vec4 projPos = projection*view*pos;

	for (auto renderable : mRenderQueue)
	{
		renderable->op->vertexArray->Bind();
		renderable->program->Bind();
		renderable->program->Uniform("view",view);
		renderable->program->Uniform("projection", projection);
		renderable->program->Uniform("model", renderable->model2world);
		if (renderable->op->UseIndices)
		{
			glDrawElements(renderable->op->mode, renderable->op->count, GL_UNSIGNED_INT, 0);
		}
		else
		{
			glDrawArrays(renderable->op->mode, 0, renderable->op->count);
		}


		renderable->op->vertexArray->Unbind();

	}

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
	glfwSwapBuffers(mWindow);
	// clear render queue.
	mRenderQueue.clear();
}


