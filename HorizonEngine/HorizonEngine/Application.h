#pragma once
#include <Scene.h>
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
		Application();
		~Application();
	private:
		void Init();
		void Update();
		void Render();

	private:
		Scene mScene;
		GLFWwindow* mWindow;
		float lastFrame = 0.0f;

	};
}


