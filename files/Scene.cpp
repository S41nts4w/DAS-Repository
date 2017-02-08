#include "Scene.h"
#include "Player.h"

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::build(void) {
	ObjectControler::insert(new Player(100, 100, 16));
}
