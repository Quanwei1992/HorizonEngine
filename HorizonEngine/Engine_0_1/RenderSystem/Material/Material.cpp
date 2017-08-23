#include "stdafx.h"
#include "Material.h"

Material::Material(GLProgramPtr program):
	mProgram(program)
{
}

void Material::setFloat(std::string name, float value)
{
	if (mProperties.count(name) == 0) {
		MaterialPropertyFloat* pFloat = new MaterialPropertyFloat(mProgram, name);
		pFloat->setValue(value);
		mProperties[name] = MaterialPropertyPtr(static_cast<MaterialProperty*>(pFloat));
		return;
	}
	auto p = mProperties[name];
	MaterialPropertyFloat* pFloat = static_cast<MaterialPropertyFloat*>(p.get());
	pFloat->setValue(value);
}

void Material::setMatrix4x4(std::string name, Matrix4x4 value)
{
	if (mProperties.count(name) == 0) {
		auto* pFloat = new MaterialPropertyMatrix4x4(mProgram, name);
		pFloat->setValue(value);
		mProperties[name] = MaterialPropertyPtr(static_cast<MaterialProperty*>(pFloat));
		return;
	}
	auto p = mProperties[name];
	auto* pFloat = static_cast<MaterialPropertyMatrix4x4*>(p.get());
	pFloat->setValue(value);
}

void Material::apply()
{
	for (auto kv:mProperties)
	{
		kv.second->apply();
	}
}

GLProgramPtr Material::getProgram() const
{
	return mProgram;
}
