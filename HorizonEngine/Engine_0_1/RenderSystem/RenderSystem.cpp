#include "stdafx.h"
#include "RenderSystem.h"


void RenderSystem::startUp()
{
	auto logsys = Application::getSingleton().getLogSystem();
	logsys->log("RenderSystem.InitGLContext");
	glfwInit();
	this->mRenderWindow = this->createRenderWindow(800,600,"Demo");
	this->setRenderTarget(this->mRenderWindow);

}

void RenderSystem::shutDown()
{
	glfwTerminate();
}

std::shared_ptr<RenderWindow> RenderSystem::getRenderWindow()
{
	return this->mRenderWindow;
}

void RenderSystem::setRenderTarget(const RenderTargetPtr& target)
{
	this->mRenderTarget = target;
}

std::shared_ptr<RenderTarget> RenderSystem::getRenderTarget()
{
	return this->mRenderTarget;
}

void RenderSystem::setViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}

void RenderSystem::setProgram(const GLProgramPtr & program)
{
	mProgram = program;
}

void RenderSystem::setViewMatrix(const Matrix4x4& viewMat)
{
	mViewMatrix = viewMat;
}

void RenderSystem::setProjectionMatrix(const Matrix4x4& projMat)
{
	mProjectionMatrix = projMat;
}

void RenderSystem::setModelMatrix(const Matrix4x4 & modelMat)
{
	mModelMatrix = mModelMatrix;
}

void RenderSystem::render(const RenderOperationPtr& op)
{
	GLenum type = GL_TRIANGLES;
	switch (op->getType())
	{
	case RenderOperation::OperationType::TriangleList:
		type = GL_TRIANGLES;
		break;
	case RenderOperation::OperationType::TriangleStrip:
		type = GL_TRIANGLE_STRIP;
		break;
	case RenderOperation::OperationType::TriangleFan:
		type = GL_TRIANGLE_FAN;
		break;
	case RenderOperation::OperationType::LineList:
		type = GL_LINES;
		break;
	case RenderOperation::OperationType::LineStrip:
		type = GL_LINE_STRIP;
		break;
	case RenderOperation::OperationType::PointList:
		type = GL_POINTS;
		break;
	default:
		break;
	}

	assert(mProgram);

	glUseProgram(mProgram->getID());
	mProgram->setValue(mProgram->getUniformID("MATRIX_VIEW"), mViewMatrix);
	mProgram->setValue(mProgram->getUniformID("MATRIX_PROJ"), mProjectionMatrix);
	mProgram->setValue(mProgram->getUniformID("MATRIX_MODEL"),mModelMatrix);
	glBindVertexArray(op->getData()->getVAO()->getID());
	
	if (op->getData()->UseIndices()) {
		glDrawElements(type, op->getData()->getIndicesCount(), op->getData()->getIndicesType(), nullptr);
	}
	else
	{
		glDrawArrays(type, 0, op->getData()->getVertexCount());
	}
	glBindVertexArray(0);
}


std::shared_ptr<RenderWindow> RenderSystem::createRenderWindow(unsigned int width, unsigned int height, std::string title)
{
	RenderWindow* rw = new RenderWindow(width, height, title);
	return std::shared_ptr<RenderWindow>(rw);
}

