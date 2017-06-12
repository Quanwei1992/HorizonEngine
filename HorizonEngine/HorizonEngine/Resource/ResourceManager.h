#pragma once
#include "Shader.h"
#include <string.h>
using namespace HorizonEngine;
class ResourceManager
{

public:
	const Shader& LoadShader(const std::string& name);
	void UnloadShader(Shader& shader);

public:
	ResourceManager();
	~ResourceManager();
};

