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
#include "RenderOperation.h"
#include "GLProgram.h"
#include "Math/Math.h"

class RenderSystem
{
public:
	RenderSystem() = default;
	~RenderSystem() = default;

	void startUp();
	void shutDown();
	std::shared_ptr<RenderWindow> getRenderWindow();

	void setRenderTarget(const RenderTargetPtr& target);
	std::shared_ptr<RenderTarget> getRenderTarget();

	void setViewport(int x, int y, int width, int height);

	// render state
	void setProgram(const GLProgramPtr& program);
	void setViewMatrix(const Matrix4x4& viewMat);
	void setProjectionMatrix(const Matrix4x4& projMat);

	void render(const RenderOperationPtr& op);

protected:
	RenderWindowPtr createRenderWindow(unsigned int width, unsigned int height, std::string title);

private:
	RenderWindowPtr mRenderWindow;
	RenderTargetPtr mRenderTarget;
	GLProgramPtr mProgram;
	Matrix4x4 mViewMatrix;
	Matrix4x4 mProjectionMatrix;
};
