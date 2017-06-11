#include <Application.h>
#include <Transform.h>
#include <Camera.h>
#include <MeshRenderer.h>
#include <type_traits>
#include "HelloWorldScene.h"
using namespace std;
using namespace HorizonEngine;


int main()
{



	auto* scene = new HelloWorldScene();
	Application::getSingleton().Run(*scene);
	return 0;
}


