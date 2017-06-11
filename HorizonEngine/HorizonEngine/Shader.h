#pragma once
#include<string>

namespace HorizonEngine
{
	class Shader
	{
	public:
		bool Compile();
		std::string GetCompileError();
		void Use();
		void SetSource(std::string vertex, std::string fragment);
		bool IsCompiled();
	public:
		Shader();
		~Shader();

	private:
		std::string mVertexShaderSource;
		std::string mFragmentShaderSource;
		std::string mCompileError;
		unsigned int mShaderProgram;
		bool mCompiled;
	};

}

