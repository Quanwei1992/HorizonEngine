#pragma once
#include <Scene.h>
#include "RenderSystem/Renderable.h"
#include "Camera.h"
#include "RenderSystem/GL/BufferManager.h"
#include "RenderSystem/GL/GPUProgramManager.h"
// GLEW
#define GLEW_STATIC
#include <ThirdPart/Includes/GL/glew.h>

// GLFW
#include <ThirdPart/Includes/GLFW/glfw3.h>
namespace HorizonEngine
{
	class Application
	{
	public:
		void Run(Scene& scene);
		void PostRenderable(Renderable& renderable);

		BufferManager& bufferManager();
		//GPUProgramManager& GPUProgramManager();

	public:
		static Application& getSingleton()
		{
			static Application theSingleton;
			return theSingleton;
		}

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
	private:
		BufferManager* mBufferManager;
		//GPUProgramManager* mGPUPragramManager;
		
	};
	
}


