#pragma once
#include <ThirdPart/Includes/GL/glew.h>
#include <ThirdPart/Includes/GLFW/glfw3.h>
#include <Scene.h>
#include "Camera.h"
#include "RenderSystem/Renderable.h"
#include "RenderSystem/GL/BufferManager.h"
#include "RenderSystem/GL/GPUProgramManager.h"
#include "Resource/ResourceManager.h"

namespace HorizonEngine
{
	class Application
	{
	public:
		void Run(Scene& scene);
		void PostRenderable(Renderable& renderable);

		BufferManager& bufferManager();
		GPUProgramManager& gpuProgramManager();
		ResourceManager& resourceManager();

	private:
		BufferManager* mBufferManager;
		GPUProgramManager* mGPUPragramManager;
		ResourceManager* mResourceManager;
	private:
		void Init();
		void Update();
		void Render(const Camera & camera);
		void RenderOneFrame();
		Application();
		~Application();
	private:
		Scene* mScene;
		GLFWwindow* mWindow;
		double lastFrame = 0.0f;
		std::vector<Renderable*> mRenderQueue;
	public:
		static Application& getSingleton()
		{
			static Application theSingleton;
			return theSingleton;
		}
		
	};
	
}


