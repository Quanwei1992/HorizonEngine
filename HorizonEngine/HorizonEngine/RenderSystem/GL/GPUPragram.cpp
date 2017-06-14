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

void GPUPragram::Bind() const
{
	glUseProgram(mID);
}

void GPUPragram::Unbind() const
{
	glUseProgram(0);
}

void GPUPragram::Uniform(const std::string name, const glm::mat4x4 & mat) const
{
	GLint loc = glGetUniformLocation(mID, name.c_str());
	// Pass the matrices to the shader
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
}

GPUPragram::GPUPragram()
{
	mID = glCreateProgram();
}


GPUPragram::~GPUPragram()
{
	glDeleteProgram(mID);
}
