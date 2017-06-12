#include "ResourceManager.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace HorizonEngine;

const Shader& ResourceManager::LoadShader(const std::string& name)
{

	const std::string rootPath = "Assets/Resources/";
	std::string vertexPath = rootPath + name + ".vs";
	std::string fragmentPath = rootPath + name + ".frag";

	// 1.从文件路径中获取顶点/片段着色器
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// 2.保证ifrtream对象可以抛出异常
	vShaderFile.exceptions(std::ifstream::badbit);
	vShaderFile.exceptions(std::ifstream::badbit);
	try
	{
		// 打开文件
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		Shader* shader = new Shader();
		shader->vertexSource(vertexCode);
		shader->fragmentSource(fragmentCode);
		return *shader;
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return *(new Shader());
}

void ResourceManager::UnloadShader(Shader & shader)
{
	delete &shader;
}

ResourceManager::ResourceManager()
{

}


ResourceManager::~ResourceManager()
{

}
