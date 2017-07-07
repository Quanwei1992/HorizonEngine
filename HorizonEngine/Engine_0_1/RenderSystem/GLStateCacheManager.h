#pragma once
#include "ThirdPart/Includes/GL/glew.h"
namespace HorizonEngine
{
	class GLStateCacheManager
	{
	public:
		GLStateCacheManager();
		~GLStateCacheManager();

	private:
		GLuint mVAO;
		GLboolean mEnableDepth;
	};
}


