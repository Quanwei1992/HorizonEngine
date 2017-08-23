#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh():
	mDirty(true)
{
}

void Mesh::setVertices(const std::vector<Vector3>& vertices)
{
	mVertices = vertices;
	mDirty = true;
}

void Mesh::setUV(const std::vector<Vector2>& uv)
{
	mUV = uv;
	mDirty = true;
}

void Mesh::setNormals(const std::vector<Vector3>& normals)
{
	mNormals = normals;
	mDirty = true;
}

void Mesh::setTriangles(const std::vector<int>& triangles)
{
	mTriangles = triangles;
	mDirty = true;
}

const std::vector<Vector3> Mesh::getVertices() const
{
	return mVertices;
}

const std::vector<Vector2> Mesh::getUV() const
{
	return mUV;
}

const std::vector<Vector3> Mesh::getNormals() const
{
	return mNormals;
}

const std::vector<int> Mesh::getTriangles() const
{
	return mTriangles;
}

VertexDataPtr Mesh::getVertexData()
{
	if (mDirty) {
		GLVertexArrayObjectPtr vao = std::make_shared<GLVertexArrayObject>();
		GLBufferPtr vbo = std::make_shared<GLBuffer>(GLBuffer::GLBufferType::ARRAY);
		vbo->write(mVertices.size() * 3 * sizeof(float), &mVertices[0],GLBuffer::GLBufferUsage::StaticDraw);
		vao->addVertexAttrib(0, "Position", vbo, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		//if (!mUV.empty()) {
		//	vao->addVertexAttrib(1, "UV", vbo, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)());
		//}
		GLBufferPtr ebo = std::make_shared<GLBuffer>(GLBuffer::GLBufferType::ELEMENT);
		ebo->write(mTriangles.size() * sizeof(int), &mTriangles[0], GLBuffer::GLBufferUsage::StaticDraw);
		vao->setIndicesBuffer(ebo);
		mData = std::make_shared<VertexData>(vao, false, GL_UNSIGNED_BYTE,0,3);


		mDirty = false;
	}
	return mData;
}


