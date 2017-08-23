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
#include "Material/Material.h"
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
	void setMaterial(const MaterialPtr& material);
	void setViewMatrix(const Matrix4x4& viewMat);
	void setProjectionMatrix(const Matrix4x4& projMat);
	void setModelMatrix(const Matrix4x4& modelMat);
	void Clear(bool color,bool depth,bool stencil);
	void setClearColor(const Color4f& color);
	void render(const RenderOperationPtr& op);

protected:
	RenderWindowPtr createRenderWindow(unsigned int width, unsigned int height, std::string title);

private:
	RenderWindowPtr mRenderWindow;
	RenderTargetPtr mRenderTarget;
	MaterialPtr mMaterial;
	Matrix4x4 mViewMatrix;
	Matrix4x4 mProjectionMatrix;
	Matrix4x4 mModelMatrix;
};
