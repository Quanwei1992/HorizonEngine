#pragma once
#include "ThirdPart/Includes/GL/glew.h"
class BufferManager;
class ArrayBuffer
{
	friend BufferManager;
public:
	void Bind();
	void Unbind();
	void Write(GLsizeiptr size,const void* data,GLenum usage);

	private:
	ArrayBuffer();
	~ArrayBuffer();

private:
	GLuint mID;
};

