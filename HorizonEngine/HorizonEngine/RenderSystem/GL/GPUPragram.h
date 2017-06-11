#pragma once
#include <string.h>
#include <vector>
#include "ThirdPart/Includes/GL/glew.h"
class GPUProgramManager;
class GPUPragram
{
friend GPUProgramManager;
public:
	void Attach(GLenum type,const GLchar* const* source);
	void Link();
	void Bind();
	void Unbind();
private:
	GPUPragram();
	~GPUPragram();
private:
	std::vector<GLuint> mShaderSources;
	GLuint mID;
};

