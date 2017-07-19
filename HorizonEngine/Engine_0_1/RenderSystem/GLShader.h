#pragma once
#include <string>
#include <memory>
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
class GLShader
{
public:
	GLShader(GLenum type);
	~GLShader();
	const GLuint getID() const;
	void setSource(std::string source);
	void compile();
	bool getCompileStatus();
	std::string getShaderInfoLog();
private:
	GLuint mID;
	GLenum mType;
	std::string mCompileStatus;
};
typedef std::shared_ptr<GLShader> GLShaderPtr;

