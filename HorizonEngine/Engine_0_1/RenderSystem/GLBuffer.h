#pragma once
#include <memory>
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"


class GLBuffer
{
public:
	enum class GLBufferType {ARRAY,ELEMENT};
	enum class GLBufferUsage {StaticDraw};

public:
	GLBuffer(GLBufferType type);
	~GLBuffer();
	const GLuint getID() const;
	void write(GLsizeiptr size, const void * data, GLBufferUsage usage);
protected:
	GLuint mID;
	GLenum mType;
};
using GLBufferPtr = std::shared_ptr<GLBuffer>;