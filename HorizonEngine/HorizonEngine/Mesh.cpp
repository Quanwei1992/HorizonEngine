#include "Mesh.h"
// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


void Mesh::vertices(const std::vector<float> vertices)
{
	mVertices = vertices;
}

const std::vector<float>& Mesh::vectices()
{
	return mVertices;
}

void Mesh::indices(const std::vector<unsigned int> indices)
{
	mIndices = indices;
}

const std::vector<unsigned int>& Mesh::indices()
{
	return mIndices;
}

Mesh::Mesh()
{
	
}


Mesh::~Mesh()
{
}
