#include <Application.h>
#include <Transform.h>
#include <type_traits>
using namespace std;
using namespace HorizonEngine;


int main()
{


	Application app;
	Scene scene;
	auto go = scene.CreateGameObject();
	auto trans = go.AddComponent<Transform>();
	
	app.Run(scene);
	return 0;
}


