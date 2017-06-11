#pragma once
#include "ThirdPart/Includes/GL/glew.h"
class BufferManager;
class ArrayBuffer
{
	friend BufferManager;
public:
	void Bind();
	void Unbind();


	private:
	ArrayBuffer();
	~ArrayBuffer();

private:
	GLuint mID;
};

