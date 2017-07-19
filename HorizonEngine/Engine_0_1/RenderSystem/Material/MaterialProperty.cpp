#include "stdafx.h"
#include "MaterialProperty.h"

MaterialProperty::MaterialProperty(GLProgramPtr program, std::string name):
	mName(name),
	mProgram(program),
	mNameID(-1)
{
}

std::string MaterialProperty::getName()
{
	return mName;
}

GLProgramPtr MaterialProperty::getProgram()
{
	return mProgram;
}

GLint MaterialProperty::getNameID()
{
	if (mNameID != -1)return mNameID;
	mNameID = mProgram->getUniformID(mName);
	return mNameID;
}



MaterialPropertyFloat::MaterialPropertyFloat(GLProgramPtr program, std::string name):MaterialProperty(program,name),
	mValue(0)
{
}

void MaterialPropertyFloat::apply()
{
	GLint nameID = getNameID();
	if (nameID != -1) {
		getProgram()->setValue(nameID, getValue());
	}
}

void MaterialPropertyFloat::setValue(GLfloat v)
{
	mValue = v;
}

GLfloat MaterialPropertyFloat::getValue()
{
	return mValue;
}




MaterialPropertyMatrix4x4::MaterialPropertyMatrix4x4(GLProgramPtr program, std::string name) :MaterialProperty(program, name),
mValue()
{

}

void MaterialPropertyMatrix4x4::apply()
{
	GLint nameID = getNameID();
	if (nameID != -1) {
		getProgram()->setValue(nameID, getValue());
	}
}

void MaterialPropertyMatrix4x4::setValue(Matrix4x4 v)
{
	mValue = v;
}

Matrix4x4 MaterialPropertyMatrix4x4::getValue()
{
	return mValue;
}
