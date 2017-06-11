#pragma once
#include "ThirdPart/Includes/GL/glew.h"

class VertexArray;
class ArrayBuffer;
class ElementArrayBuffer;


class BufferManager
{

public:
	VertexArray& GenVertexArray();
	void		 DeleteVertexArray(VertexArray& vao);
	ArrayBuffer& GenArrayBuffer();
	void		 DeleteArrayBuffer(ArrayBuffer& vbo);
	ElementArrayBuffer& GenElementArrayBuffer();
	void		 DeleteElementArrayBuffer(ElementArrayBuffer& ebo);

public:
	BufferManager();
	~BufferManager();
};

