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
	glGetProgramInfoLog(mID, 1024, NULL, infolog);
	return std::string(infolog);
}

GLuint GLProgram::getID() const
{
	return mID;
}
