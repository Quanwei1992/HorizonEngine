#pragma once
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "MaterialProperty.h"
#include "RenderSystem/GLProgram.h"
#include "Math/Math.h"
class Material
{
public:
	Material(GLProgramPtr program);
	~Material() = default;
	
	void setFloat(std::string name,float value);
	void setMatrix4x4(std::string name, Matrix4x4 matrix);

	void apply();
	GLProgramPtr getProgram() const;
private:
	std::map<std::string, MaterialPropertyPtr> mProperties;
	GLProgramPtr mProgram;
};
typedef std::shared_ptr<Material> MaterialPtr;


