#include "stdafx.h"
#include "GLVertexArrayObject.h"



GLVertexArrayObject::GLVertexArrayObject():
	mDirty(true)
{
	glGenVertexArrays(1, &mID);
}


GLVertexArrayObject::~GLVertexArrayObject()
{
	glDeleteVertexArrays(1,&mID);
}

void GLVertexArrayObject::apply()
{
	glBindVertexArray(mID);
	for (auto kv:mAttributes)
	{
		auto attrib = kv.second;
		auto buffer = attrib->getBuffer();
		
		glBindBuffer(GL_ARRAY_BUFFER, buffer->getID());
		glVertexAttribPointer(kv.first,attrib->getSize(),attrib->getType(),attrib->getNormalized(),
			attrib->getStride(),attrib->getPointer());
		glEnableVertexAttribArray(kv.first);
	}
	if (mIndicesBuffer) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesBuffer->getID());
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

GLuint GLVertexArrayObject::getID()
{
	if (mDirty) {
		apply();
		mDirty = false;
	}
	return mID;
}

void GLVertexArrayObject::addVertexAttrib(GLuint slot, std::string name,GLBufferPtr buffer, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid * pointer)
{
	GLVertexAttrib* attr = new GLVertexAttrib(name, buffer, size, type, normalized, stride, pointer);
	auto ptr = GLVertexAttribPtr(attr);
	mAttributes[slot] = ptr;
	mDirty = true;
}

void GLVertexArrayObject::setIndicesBuffer(GLBufferPtr indicesBuffer)
{
	mIndicesBuffer = indicesBuffer;
	mDirty = true;
}

GLBufferPtr GLVertexArrayObject::getIndicesBuffer()
{
	return mIndicesBuffer;
}


