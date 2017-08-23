#include "stdafx.h"
#include "GLProgram.h"



GLProgram::GLProgram():
	mIsInvalid(true)
{
	mID = glCreateProgram();
}


GLProgram::~GLProgram()
{
	glDeleteProgram(mID);
}

void GLProgram::attachShader(const GLShaderPtr & shader)
{
	glAttachShader(mID, shader->getID());
}

void GLProgram::link()
{
	glLinkProgram(mID);
	mIsInvalid = !getLinkStatus();
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

void GLProgram::setValue(GLint uniformID, float value)
{
	if (uniformID == -1)return;
	glUseProgram(mID);
	glUniform1f(uniformID, value);
}

void GLProgram::setValue(GLint uniformID, const Matrix4x4 & value)
{
	if (uniformID == -1)return;
	glUseProgram(mID);	
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(value));
}

bool GLProgram::isInvalid() const
{
	return mIsInvalid;
}

GLint GLProgram::getUniformID(const std::string& name)
{
	return glGetUniformLocation(mID, name.c_str());
}