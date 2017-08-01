#include "stdafx.h"
#include "TimeSystem.h"
#include "ThirdPart/Includes/GLFW/glfw3.h"


void TimeSystem::startUp()
{

}

void TimeSystem::shutDown()
{
}

double TimeSystem::getCurrentTime()
{
	return glfwGetTime();
}
