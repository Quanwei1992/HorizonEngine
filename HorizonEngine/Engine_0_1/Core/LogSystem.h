#pragma once
#include <string>
namespace HorizonEngine
{
	class LogSystem
	{
	public:
		LogSystem();
		~LogSystem();
		void log(std::string info);
		void startUp();
		void shutDown();
	};

}

