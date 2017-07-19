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
	void attachShader(const GLShader& shader);
	void link();
	bool getLinkStatus();
	std::string getProgramInfoLog();
	GLuint getID() const;
	GLuint getUniformID(const std::string& name);
	void setValue(GLuint uniformID,float value);
	void setValue(GLuint uniformID,const Matrix4x4& value);
private:
	GLuint mID;
};
typedef std::shared_ptr<GLProgram> GLProgramPtr;
