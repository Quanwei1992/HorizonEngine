#pragma once
#include<string>

namespace HorizonEngine
{
	class Shader
	{
	public:
		void vertexSource(const std::string& source);
		const std::string& vertexSource() const;
		void fragmentSource(const std::string& source);
		const std::string& fragmentSource() const;

	public:
		Shader();
		~Shader();

	private:
		std::string mVertexShaderSource;
		std::string mFragmentShaderSource;
	};

}

