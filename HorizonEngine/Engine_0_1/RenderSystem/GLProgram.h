#pragma once
#include <string>
#include <memory>
#include "GLShader.h"
#include "Math/Math.h"
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
class GLProgram
{
public:
	GLProgram();
	~GLProgram();
	void attachShader(const GLShaderPtr& shader);
	void link();
	bool getLinkStatus();
	std::string getProgramInfoLog();
	GLuint getID() const;
	GLint getUniformID(const std::string& name);
	void setValue(GLint uniformID,float value);
	void setValue(GLint uniformID,const Matrix4x4& value);
private:
	GLuint mID;
};
typedef std::shared_ptr<GLProgram> GLProgramPtr;
