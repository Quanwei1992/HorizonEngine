#pragma once
#include "ThirdPart/Includes/GL/glew.h"
class BufferManager;
class VertexArray
{
	friend BufferManager;
public:
	void Bind();
	void Unbind();
private:
	VertexArray();
	~VertexArray();
private:
	GLuint mID;
};

