#pragma once
#include <string>
#include <memory>

#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
#include "RenderSystem/GLProgram.h"
#include "Math/Math.h"


class MaterialProperty
{
public:
	MaterialProperty(GLProgramPtr program,std::string name);
	~MaterialProperty() = default;
	std::string getName();
	GLProgramPtr getProgram();
	virtual void apply() = 0;


protected:
	int getNameID();

private:
	std::string mName;
	GLProgramPtr mProgram;
	GLint mNameID;
};
typedef std::shared_ptr<MaterialProperty> MaterialPropertyPtr;


class MaterialPropertyFloat: public MaterialProperty
{
public:
	MaterialPropertyFloat(GLProgramPtr program, std::string name);
	~MaterialPropertyFloat() = default;
	void apply() override;
	void setValue(GLfloat v);
	float getValue();

private:
	GLfloat mValue;
};


class MaterialPropertyMatrix4x4 : public MaterialProperty
{
public:
	MaterialPropertyMatrix4x4(GLProgramPtr program, std::string name);
	~MaterialPropertyMatrix4x4() = default;
	void apply() override;
	void setValue(Matrix4x4 v);
	Matrix4x4 getValue();

private:
	Matrix4x4 mValue;
};
