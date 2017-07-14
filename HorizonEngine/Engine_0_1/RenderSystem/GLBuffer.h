#pragma once
#include "ThirdPart/Includes/GL/glew.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"

	class GLBuffer
	{
	public:
		GLBuffer(GLenum type);
		~GLBuffer();
		const GLuint getID() const;
		void write(GLsizeiptr size, const void * data, GLenum usage);
	protected:
		GLuint mID;
		GLenum mType;
	};
