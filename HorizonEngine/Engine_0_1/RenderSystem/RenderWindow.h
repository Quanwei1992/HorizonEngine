#pragma once
#include <string>
#include <memory>

#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"

#include "RenderSystem/RenderTarget.h"
namespace HorizonEngine
{
	class RenderWindow : public RenderTarget
	{
	public:
		bool shouldClose();
		void swapBuffers();
		void pollEvents();
		RenderWindow(unsigned int width,unsigned int height,std::string title);
		~RenderWindow();
	private:
		GLFWwindow* mGLWindow;
	};

}

