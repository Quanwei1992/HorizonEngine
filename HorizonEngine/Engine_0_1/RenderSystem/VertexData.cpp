#include "stdafx.h"
#include "VertexData.h"



VertexData::VertexData(GLVertexArrayObjectPtr vao, bool useIndices, GLenum indicesType, int indicesCount, int vertexCount):
	mVAO(vao),
	mUseIndices(useIndices),
	mIndicesType(indicesType),
	mIndicesCount(indicesCount),
	mVertexCount(vertexCount)
{

}

GLVertexArrayObjectPtr VertexData::getVAO()
{
	return mVAO;
}

bool VertexData::UseIndices()
{
	return mUseIndices;
}

int VertexData::getIndicesCount()
{
	return mIndicesCount;
}

int VertexData::getVertexCount()
{
	return mVertexCount;
}

GLenum VertexData::getIndicesType()
{
	return mIndicesType;
}
