#include "ArrayBuffer.h"



void ArrayBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, mID);
}

void ArrayBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ArrayBuffer::Write(GLsizeiptr size, const void * data, GLenum usage)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

ArrayBuffer::ArrayBuffer()
{
	glGenBuffers(1, &mID);
}


ArrayBuffer::~ArrayBuffer()
{
	glDeleteBuffers(1, &mID);
}
