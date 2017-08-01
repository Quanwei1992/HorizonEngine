#pragma once
#include "System.h"
class TimeSystem : public System
{
public:
	TimeSystem() = default;
	~TimeSystem() override = default;
	void startUp() override;
	void shutDown() override;
	double getCurrentTime();

};

