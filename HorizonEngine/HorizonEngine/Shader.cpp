#include "Shader.h"
#include <GL/glew.h>
#include <iostream>
// GLFW
#include <GLFW/glfw3.h>

using namespace HorizonEngine;

bool Shader::Compile()
{
	GLchar const* vertexShaderSource = mVertexShaderSource.c_str();
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	GLint sucess;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &sucess);

	if (!sucess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		glDeleteShader(vertexShader);
		mCompileError = infoLog;
		return false;
	}

	GLchar const* fragmentShaderSource = mFragmentShaderSource.c_str();
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &sucess);
	if (!sucess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		mCompileError = infoLog;
		return false;
	}

	GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &sucess);
	if (!sucess) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		mCompileError = infoLog;
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		return false;
	}


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	mShaderProgram = shaderProgram;
	mCompiled = true;
	return true;
}

std::string Shader::GetCompileError()
{
	return std::string();
}

void Shader::Use()
{
	if (!mCompiled)return;
	glUseProgram(mShaderProgram);
}

void Shader::SetSource(std::string vertex, std::string fragment)
{
	mVertexShaderSource = vertex;
	mFragmentShaderSource = fragment;
}

bool Shader::IsCompiled()
{
	return mCompiled;
}

Shader::Shader():
	mCompiled(false)
{

}


Shader::~Shader()
{

}
