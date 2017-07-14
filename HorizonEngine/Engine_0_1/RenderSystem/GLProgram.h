#pragma once
#include <string>
#include "GLShader.h"
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
private:
	GLuint mID;
};

