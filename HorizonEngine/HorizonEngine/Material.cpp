#include "Material.h"

using namespace HorizonEngine;

Shader & Material::shader()
{
	return *mShader;
}

void Material::shader(Shader & shader)
{
	mShader = &shader;
}

HorizonEngine::Material::Material(Shader & shader)
{
	mShader = &shader;
}

Material::~Material()
{
}
