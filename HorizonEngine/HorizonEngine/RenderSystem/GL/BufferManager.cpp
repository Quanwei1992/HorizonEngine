#include "BufferManager.h"

#include "RenderSystem/GL/VertexArray.h"
#include "RenderSystem/GL/ElementArrayBuffer.h"
#include "RenderSystem/GL/ArrayBuffer.h"


VertexArray& BufferManager::GenVertexArray()
{
	return *(new VertexArray());
}

void BufferManager::DeleteVertexArray(VertexArray& vao)
{
	delete &vao;
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
