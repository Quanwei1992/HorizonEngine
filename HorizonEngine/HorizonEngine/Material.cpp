#include "Material.h"

using namespace HorizonEngine;

const Shader & Material::shader() const
{
	return *mShader;
}

void Material::shader(const Shader & shader)
{
	mShader = &shader;
}

Material::Material(const Shader & shader)
{
	mShader = &shader;
}

Material::~Material()
{
}
