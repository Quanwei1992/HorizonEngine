#include "stdafx.h"
#include "GLBuffer.h"
GLBuffer::GLBuffer(GLenum type)
{
	glGenBuffers(1, &mID);
	mType = type;
}


GLBuffer::~GLBuffer()
{
	glDeleteBuffers(1, &mID);
}

const GLuint GLBuffer::getID() const
{
	return mID;
}

void GLBuffer::write(GLsizeiptr size, const void * data, GLenum usage)
{
	glBindBuffer(mType, mID);
	glBufferData(mType, size, data, usage);
}
