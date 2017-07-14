#include "stdafx.h"
#include "GLVertexAttrib.h"





GLVertexAttrib::GLVertexAttrib(std::string name, std::shared_ptr<GLBuffer> buffer,
	GLint size, GLenum type, GLboolean normalized, GLsizei stride,GLvoid * mPointer):
	mName()
	,mBuffer()
	,mSize(0)
	,mType(GL_FLOAT)
	,mNormalized(GL_FALSE)
	,mStride(0)
	,mPointer(0)

{
	mName = name;
	mBuffer = buffer;
	mSize = size;
	mType = type;
	mNormalized = normalized;
	mStride = stride;
	mPointer = mPointer;
}

GLVertexAttrib::~GLVertexAttrib()
{
}
