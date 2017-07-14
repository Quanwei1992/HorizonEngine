#pragma once
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
#include "GLVertexAttrib.h"
class GLVertexArrayObject
{
public:
	GLVertexArrayObject();
	~GLVertexArrayObject();
	void AddVertexAttrib(GLuint slot,const GLVertexAttrib& attr);
private:
	GLuint mID;
};

