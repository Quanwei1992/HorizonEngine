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

	// 1.���ļ�·���л�ȡ����/Ƭ����ɫ��
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// 2.��֤ifrtream��������׳��쳣
	vShaderFile.exceptions(std::ifstream::badbit);
	vShaderFile.exceptions(std::ifstream::badbit);
	try
	{
		// ���ļ�
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
