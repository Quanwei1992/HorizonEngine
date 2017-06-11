#pragma once
#include "ThirdPart/Includes/GL/glew.h"
class BufferManager;
class VertexArray
{
	friend BufferManager;
public:
	void Bind();
	void Unbind();
	void AttribPointer(GLuint index,GLint size,GLenum type,GLboolean normalized,GLsizei stride,const void* pointer);
	void EnableAttribArray(GLuint index);
private:
	VertexArray();
	~VertexArray();
private:
	GLuint mID;
};

