#include "stdafx.h"
#include "GLBuffer.h"
GLBuffer::GLBuffer(GLBufferType type)
{
	glGenBuffers(1, &mID);
	if (type == GLBufferType::ARRAY) {
		mType = GL_ARRAY_BUFFER;
	}
	else if (type == GLBufferType::ELEMENT) {
		mType = GL_ELEMENT_ARRAY_BUFFER;
	}
	
}


GLBuffer::~GLBuffer()
{
	glDeleteBuffers(1, &mID);
}

const GLuint GLBuffer::getID() const
{
	return mID;
}

void GLBuffer::write(GLsizeiptr size, const void * data, GLBufferUsage usage)
{
	glBindBuffer(mType, mID);
	if (usage == GLBufferUsage::StaticDraw) {
		glBufferData(mType, size, data, GL_STATIC_DRAW);
	}
	
}
