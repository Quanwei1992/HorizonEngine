#pragma once
#include "RenderSystem/GL/VertexArray.h"
// ���ɲ�ֵ�һ����ȾԪ������
// ����һ����Ⱦ�������������ݡ�
// ��������
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

