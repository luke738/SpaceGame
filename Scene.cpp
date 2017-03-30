#include "Scene.h"
#include <SDL.h>
#include <vector>
#include "Element.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::loop()
{
	for each (Element e in elements)
	{
		e.tick();
	}
	render();
}

void Scene::render()
{
	for each (Element e in elements)
	{
		e.render(renderer);
	}
}
