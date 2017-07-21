#pragma once
class System
{
public:
	System() = default;
	virtual ~System() = default;
	virtual void startUp() = 0;
	virtual void shutDown() = 0;
};

