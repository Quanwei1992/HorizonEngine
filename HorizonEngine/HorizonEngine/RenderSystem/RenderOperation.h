#pragma once
#include "RenderSystem/GL/VertexArray.h"
// 不可拆分的一次渲染元操作。
// 包含一次渲染操作的所有数据。
// 顶点数据
class RenderOperation
{
public:
	RenderOperation();
	~RenderOperation();
public:
	GLenum mode;//GL_TRIANGLES
	GLsizei count;
	bool UseIndices;
	VertexArray* vertexArray;
};

