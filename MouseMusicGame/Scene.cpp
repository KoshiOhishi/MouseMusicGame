#include <string>
#include "Scene.h"

using namespace std;

Scene::Scene()
{
	scene = "Title";
}

void Scene::SetScene(string sceneName)
{
	if (!CheckSceneName(sceneName)) return;

	scene = sceneName;
}

string Scene::GetNowScene()
{
	return scene;
}

bool Scene::CheckSceneName(string sceneName)
{
	if (sceneName.find("Title") == -1 &&
		sceneName.find("Game") == -1 &&
		sceneName.find("Result") == -1
		)
		return false;

	return true;
}