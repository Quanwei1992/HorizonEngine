#include "ElementArrayBuffer.h"



void ElementArrayBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
}

void ElementArrayBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementArrayBuffer::Write(GLsizeiptr size, const void * data, GLenum usage)
{
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
	Unbind();
}

ElementArrayBuffer::ElementArrayBuffer()
{
	glGenBuffers(1, &mID);
}


ElementArrayBuffer::~ElementArrayBuffer()
{
	glDeleteBuffers(1, &mID);
}
