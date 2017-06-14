#pragma once
#include <string.h>
#include <vector>
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/glm/glm.hpp"
#include "ThirdPart/Includes/glm/gtc/type_ptr.hpp"
class GPUProgramManager;
class GPUPragram
{
friend GPUProgramManager;
public:
	void Attach(GLenum type,const GLchar* const* source);
	void Link();
	void Bind() const;
	void Unbind() const;
	void Uniform(const std::string name,const glm::mat4x4& mat) const;
private:
	GPUPragram();
	~GPUPragram();
private:
	std::vector<GLuint> mShaderSources;
	GLuint mID;
};

