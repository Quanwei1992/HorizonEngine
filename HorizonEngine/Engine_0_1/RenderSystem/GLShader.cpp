#include "GLShader.h"



GLShader::GLShader(GLenum type)
{
	mType = mType;
	mID = glCreateShader(type);
}


GLShader::~GLShader()
{
	glDeleteShader(mID);
}

const GLuint GLShader::getID() const
{
	return mID;
}

void GLShader::setSource(std::string source)
{
	const char* s = source.c_str();
	glShaderSource(mID, 1,&s, nullptr);
}

void GLShader::compile()
{
	glCompileShader(mID);
}

bool GLShader::getCompileStatus()
{
	int sucess = 0;
	glGetShaderiv(mID, GL_COMPILE_STATUS, &sucess);
	return sucess;
}

std::string GLShader::getShaderInfoLog()
{
	char infoLog[1024];
	glGetShaderInfoLog(mID, 1024, NULL, infoLog);
	return infoLog;
}
