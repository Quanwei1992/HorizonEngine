#pragma once
#include <memory>
#include <vector>
#include <map>
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"
#include "GLVertexAttrib.h"
class GLVertexArrayObject
{
public:
	GLVertexArrayObject();
	~GLVertexArrayObject();
	void addVertexAttrib(GLuint slot, std::string name, GLBufferPtr buffer,
		GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid * pointer);
	void setIndicesBuffer(GLBufferPtr indicesBuffer);
	GLBufferPtr getIndicesBuffer();
	GLuint getID();
private:
	void apply();
private:
	GLuint mID;
	bool mDirty;
	std::map<int,GLVertexAttribPtr> mAttributes;
	GLBufferPtr mIndicesBuffer;
};
using GLVertexArrayObjectPtr = std::shared_ptr<GLVertexArrayObject>;

