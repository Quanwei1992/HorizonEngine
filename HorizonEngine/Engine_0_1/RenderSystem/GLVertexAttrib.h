#pragma once
#include <string>
#include <memory>
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
#include "GLBuffer.h"
class GLVertexAttrib
{

public:
	GLVertexAttrib(std::string name,std::shared_ptr<GLBuffer> buffer,
		GLint size,GLenum type,GLboolean normalized,GLsizei stride,GLvoid* mPointer);
	~GLVertexAttrib();

	const std::string getName()const { return mName;}
	const std::shared_ptr<GLBuffer> getBuffer() const { return mBuffer; }
	const GLint getSize()const { return mSize; }
	const GLenum getType()const {return mType;}
	const GLboolean getNormalized()const { return mNormalized; }
	const GLsizei getStride() const { return mNormalized; }
	const GLvoid* getPointer() const { return mPointer; }

private:
	std::string mName;
	std::shared_ptr<GLBuffer> mBuffer;
	GLint mSize;
	GLenum mType;
	GLboolean mNormalized;
	GLsizei mStride;
	GLvoid* mPointer;
	
};

