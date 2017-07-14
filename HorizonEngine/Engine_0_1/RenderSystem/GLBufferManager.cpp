#include "stdafx.h"
#include "GLBufferManager.h"
using namespace HorizonEngine;


GLBufferManager::GLBufferManager()
{
}


GLBufferManager::~GLBufferManager()
{
}

GLBuffer & GLBufferManager::CreateArrayBuffer()
{
	GLBuffer* buffer = new GLBuffer(GL_ARRAY_BUFFER);
	return *buffer;
}

GLBuffer & GLBufferManager::CreateElementBuffer()
{
	GLBuffer* buffer = new GLBuffer(GL_ELEMENT_ARRAY_BUFFER);
	return *buffer;
}
