#pragma once
// std
#include <memory>
#include <string>

#define GLEW_STATIC
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
#include "ThirdPart/Includes/glm/glm.hpp"
// engine
#include "RenderWindow.h"
#include "GLStateCacheManager.h"
#include "RenderOperation.h"
namespace HorizonEngine
{
	class RenderSystem
	{
	public:
		RenderSystem();
		~RenderSystem();
		
		void startUp();
		void shutDown();
		std::shared_ptr<RenderWindow> getRenderWindow();

		void setRenderTarget(std::shared_ptr<RenderTarget> target);
		std::shared_ptr<RenderTarget> getRenderTarget();

		void setViewport(int x,int y,int width,int height);

		// render state
		void setViewMatrix(glm::mat4x4 viewMat);
		void setProjectionMatrix(glm::mat4x4 viewMat);

		void render(const RenderOperation& op);

	protected:
		std::shared_ptr<RenderWindow> createRenderWindow(unsigned int width,unsigned int height,std::string title);

	private:
		std::shared_ptr<RenderWindow> mRenderWindow;
		std::shared_ptr<RenderTarget> mRenderTarget;
	};

}