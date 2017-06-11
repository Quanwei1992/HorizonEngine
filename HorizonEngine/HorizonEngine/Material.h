#pragma once
#include "Shader.h"
namespace HorizonEngine
{
	class Material
	{

	public:
		Shader& shader();
		void	shader(Shader& shader);

	public:
		Material(Shader& shader);
		~Material();
	private:
		Shader* mShader;
	};

}

