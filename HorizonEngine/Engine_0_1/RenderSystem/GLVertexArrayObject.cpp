#include "GLVertexArrayObject.h"



GLVertexArrayObject::GLVertexArrayObject()
{
	glGenVertexArrays(1, &mID);
}


GLVertexArrayObject::~GLVertexArrayObject()
{
	glDeleteVertexArrays(1,&mID);
}
