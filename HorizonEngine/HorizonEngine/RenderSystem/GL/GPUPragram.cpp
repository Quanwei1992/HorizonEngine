#include "GPUPragram.h"



void GPUPragram::Attach(GLenum type,const GLchar* const* source)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, source, NULL);
	glAttachShader(mID, shader);
	mShaderSources.push_back(shader);
}

void GPUPragram::Link()
{
	glLinkProgram(mID);
	for (auto shader:mShaderSources)
	{
		glDeleteShader(shader);
	}
	mShaderSources.clear();
}

void GPUPragram::Bind()
{
	glUseProgram(mID);
}

void GPUPragram::Unbind()
{
	glUseProgram(0);
}

GPUPragram::GPUPragram()
{
	mID = glCreateProgram();
}


GPUPragram::~GPUPragram()
{
	glDeleteProgram(mID);
}
