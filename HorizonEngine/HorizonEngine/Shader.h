#pragma once
#include<string>

namespace HorizonEngine
{
	class Shader
	{
	public:
		void vertexSource(const std::string& source);
		const std::string& vertexSource();
		void fragmentSource(const std::string& source);
		const std::string& fragmentSource();

	public:
		Shader();
		~Shader();

	private:
		std::string mVertexShaderSource;
		std::string mFragmentShaderSource;
	};

}

