#pragma once
#include <memory>
#include "GLVertexArrayObject.h"
class VertexData
{
public:
	VertexData(GLVertexArrayObjectPtr vao,bool useIndices,GLenum indicesType,int indicesCount,int vertexCount);
	~VertexData() = default;
	GLVertexArrayObjectPtr getVAO();
	bool UseIndices();
	int getIndicesCount();
	int getVertexCount();
	GLenum getIndicesType();
private:
	GLVertexArrayObjectPtr mVAO;
	bool mUseIndices;
	int mIndicesCount;
	int mVertexCount;
	GLenum mIndicesType;
};
typedef std::shared_ptr<VertexData> VertexDataPtr;

