#include "Shader.h"
#include <GL/glew.h>
#include <iostream>
// GLFW
#include <GLFW/glfw3.h>

using namespace HorizonEngine;


void HorizonEngine::Shader::vertexSource(const std::string & source)
{
	mVertexShaderSource = source;
}

const std::string & HorizonEngine::Shader::vertexSource()
{
	// TODO: �ڴ˴����� return ���
	return mVertexShaderSource;
}

void HorizonEngine::Shader::fragmentSource(const std::string & source)
{
	mFragmentShaderSource = source;
}

const std::string & HorizonEngine::Shader::fragmentSource()
{
	// TODO: �ڴ˴����� return ���
	return mFragmentShaderSource;
}

Shader::Shader()
{

}


Shader::~Shader()
{

}
