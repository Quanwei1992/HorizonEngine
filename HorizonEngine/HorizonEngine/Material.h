#pragma once
#include "Shader.h"
namespace HorizonEngine
{
	class Material
	{

	public:
		const Shader& 
			shader() const;
		void 
			shader(const Shader& shader);

	public:
		Material(const Shader& shader);
		~Material();
	private:
		const Shader* mShader;
	};

}

