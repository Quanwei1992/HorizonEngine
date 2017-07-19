#include "stdafx.h"
#include "GLProgram.h"



GLProgram::GLProgram()
{
	mID = glCreateProgram();
}


GLProgram::~GLProgram()
{
	glDeleteProgram(mID);
}

void GLProgram::attachShader(const GLShader & shader)
{
	glAttachShader(mID, shader.getID());
}

void GLProgram::link()
{
	glLinkProgram(mID);
}

bool GLProgram::getLinkStatus()
{
	int success = 0;
	glGetProgramiv(mID, GL_LINK_STATUS, &success);
	return success;
}

std::string GLProgram::getProgramInfoLog()
{
	char infolog[1024];
	glGetProgramInfoLog(mID, 1024, nullptr, infolog);
	return std::string(infolog);
}

GLuint GLProgram::getID() const
{
	return mID;
}

void GLProgram::setValue(GLuint uniformID, float value)
{
	glUseProgram(mID);
	glUniform1f(uniformID, value);
}

void GLProgram::setValue(GLuint uniformID, const Matrix4x4 & value)
{
	glUseProgram(mID);
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(value));
}

GLuint GLProgram::getUniformID(const std::string& name)
{
	return glGetUniformLocation(mID, name.c_str());
}