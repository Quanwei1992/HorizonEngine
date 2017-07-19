#include "stdafx.h"
#include "GLVertexAttrib.h"





GLVertexAttrib::GLVertexAttrib(std::string name, GLBufferPtr buffer,
	GLint size, GLenum type, GLboolean normalized, GLsizei stride,GLvoid * pointer):
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
	mPointer = pointer;
}

GLVertexAttrib::~GLVertexAttrib()
{
}
