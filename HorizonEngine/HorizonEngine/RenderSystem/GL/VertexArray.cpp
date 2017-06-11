#include "VertexArray.h"



void VertexArray::Bind()
{
	glBindVertexArray(mID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &mID);
}


VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &mID);
}
