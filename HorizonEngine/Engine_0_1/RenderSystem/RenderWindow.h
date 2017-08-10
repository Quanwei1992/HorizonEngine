#pragma once
#include <string>
#include <memory>

#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"

#include "RenderSystem/RenderTarget.h"

class RenderWindow : public RenderTarget
{
public:
	bool shouldClose();
	void swapBuffers();
	void pollEvents();
	void setTitle(const std::string& title);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	RenderWindow(unsigned int width, unsigned int height, std::string title);
	~RenderWindow();


private:
	GLFWwindow* mGLWindow;
	unsigned int mWidth;
	unsigned int mHeight;
};
typedef std::shared_ptr<RenderWindow> RenderWindowPtr;
