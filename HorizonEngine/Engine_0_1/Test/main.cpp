#include "stdafx.h"
#include <iostream>
#include <memory>

#include "RenderSystem/RenderSystem.h"
using namespace std;
int main()
{
	std::cout << "Init Application\n";
	Application::getSingleton().init();
	std::cout << "Run Application\n";
	Application::getSingleton().run();
	std::cout << "Shutdown Application\n";
	Application::getSingleton().shutdown();
	//system("pause");
	return 0;
}