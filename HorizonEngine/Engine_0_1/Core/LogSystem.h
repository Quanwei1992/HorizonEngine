#pragma once
#include <memory>
#include <string>

class LogSystem
{
public:
	LogSystem();
	~LogSystem();
	void log(std::string info);
	void startUp();
	void shutDown();
};
typedef std::shared_ptr<LogSystem> LogSystemPtr;