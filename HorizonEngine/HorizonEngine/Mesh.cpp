#include "Mesh.h"
// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


void Mesh::Submit()
{
	if (mNumOfTrangles <= 0)return;
	if (mVertices.empty())return;

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLfloat* vertices = &mVertices[0];
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() *sizeof(float), vertices, GL_STATIC_DRAW);

	if (!mIndices.empty())
	{
		GLuint* indices = &mIndices[0];
		GLuint EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(unsigned int), indices, GL_STATIC_DRAW);
		mEBO = EBO;
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	mVAO = VAO;
	mVBO = VBO;
	mSubmited = true;
}

void Mesh::SetData(std::vector<float> vertices, std::vector<unsigned int> indices)
{
	mVertices = vertices;
	mIndices = indices;
	if (mIndices.size() > 0 && mIndices.size() % 3 == 0)
	{
		mNumOfTrangles = mIndices.size() / 3;
	}
	else if(vertices.size() > 0 && vertices.size() % 3 == 0)
	{
		mNumOfTrangles = vertices.size() % 3;
	}
	else
	{
		mNumOfTrangles = 0;
	}
}



void Mesh::Use()
{
	if (!mSubmited)return;
	glBindVertexArray(mVAO);
}


unsigned int Mesh::GetNumOfTrangles()
{
	return mNumOfTrangles;
}

unsigned int Mesh::GetVerticesCount()
{
	return mVertices.size();
}

unsigned int Mesh::GetIndicesCount()
{
	return mIndices.size();
}

bool Mesh::IsSubmited()
{
	return mSubmited;
}

Mesh::Mesh():
	mVAO(0),
	mVBO(0),
	mEBO(0),
	mNumOfTrangles(0),
	mSubmited(false)
{
	
}


Mesh::~Mesh()
{
}
