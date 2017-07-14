#pragma once
#include "GLBuffer.h"
namespace HorizonEngine
{
	class GLBufferManager
	{
	public:
		GLBufferManager();
		~GLBufferManager();

		GLBuffer& CreateArrayBuffer();
		GLBuffer& CreateElementBuffer();
	};
}


