#include "VertexArray.h"



void VertexArray::Bind()
{
	glBindVertexArray(mID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::AttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer)
{
	Bind();
	glVertexAttribPointer(index,size,type,normalized, stride, pointer);
	Unbind();
}

void VertexArray::EnableAttribArray(GLuint index)
{
	Bind();
	glEnableVertexAttribArray(index);
	Unbind();
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &mID);
}


VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &mID);
}
