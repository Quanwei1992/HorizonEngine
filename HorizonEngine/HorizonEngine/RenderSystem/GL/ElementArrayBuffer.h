#pragma once
#include "ThirdPart/Includes/GL/glew.h"
class BufferManager;
class ElementArrayBuffer
{
	friend BufferManager;
public:
	void Bind();
	void Unbind();
	void Write(GLsizeiptr size, const void* data, GLenum usage);

private:
	ElementArrayBuffer();
	~ElementArrayBuffer();
private:
	GLuint mID;
};

