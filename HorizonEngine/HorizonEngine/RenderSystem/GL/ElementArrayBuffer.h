#pragma once
#include "ThirdPart/Includes/GL/glew.h"
class ElementArrayBuffer
{
public:
	void Bind();
	void UnBind();

private:
	ElementArrayBuffer();
	~ElementArrayBuffer();
};

