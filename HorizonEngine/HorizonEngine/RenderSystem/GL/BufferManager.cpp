#include "BufferManager.h"



VertexArray& BufferManager::GenVertexArray()
{
	return *(new VertexArray());
}

void BufferManager::DeleteVertexArray(VertexArray& vao)
{
	delete *vao;
}

ArrayBuffer& BufferManager::GenArrayBuffer()
{
	return *(new ArrayBuffer());
}

void BufferManager::DeleteArrayBuffer(ArrayBuffer& vbo)
{
	delete &vbo;
}

ElementArrayBuffer& BufferManager::GenElementArrayBuffer()
{
	return *(new ElementArrayBuffer());
}

void BufferManager::DeleteElementArrayBuffer(ElementArrayBuffer& ebo)
{
	delete &ebo;
}

BufferManager::BufferManager()
{
}


BufferManager::~BufferManager()
{
}
